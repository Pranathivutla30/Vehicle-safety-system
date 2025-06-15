#define SW_VERSION " ThinkSpeak.com" // SW version will appears at innitial LCD Display
#include <ESP8266WiFi.h>
#include <Wire.h> 
#include <WiFiClientSecure.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h> 
#include <TinyGPS.h> 
float lat =17.3841 ,lon = 78.4649 ; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(D3,D4);//rx,tx  
TinyGPS gps; // create gps object 
#include <SoftwareSerial.h>
SoftwareSerial ss(D7,D8);
const char* MY_SSID = "1234";
const char* MY_PWD = "12345678";
WiFiClient client;
const char* TS_SERVER = "api.thingspeak.com";
String TS_API_KEY = "SL9PETPP4DG1ZR63";
void connectWifi()
{
  Serial.print("Connecting to " + *MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("");
  
}
int gas=A0;
int buzzer=10;
int motor=D6;
int ir=D5;
int fire=D0;
 void SendMessage( String data)
{
  ss.println("AT+CMGF=1");    
  delay(1000);  
  ss.println("AT+CMGS=\"+918331821483\"\r"); 
  delay(1000);
  ss.println(data);
  delay(100);
   ss.println((char)26);
  delay(1000);
}
void setup(){
Serial.begin(9600); // connect serial
Serial.println("The GPS Received Signal:");
gpsSerial.begin(9600); // connect gps sensor
  ss.begin(9600);
pinMode(ir,INPUT);
  pinMode(gas,INPUT);
  pinMode(fire,INPUT);
  pinMode(motor,OUTPUT);
  pinMode(buzzer,OUTPUT);
  digitalWrite(motor,LOW);
  delay(1000);
  connectWifi();
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("welcome ");
}
void loop()
{
while(gpsSerial.available()){ // check for gps data 
  if(gps.encode(gpsSerial.read()))// encode gps data 
  {  
  gps.f_get_position(&lat,&lon); // get latitude and longitude 
  Serial.print("Position: "); 
  Serial.print("Latitude:"); 
  Serial.print(lat,6); 
  Serial.print(";"); 
  Serial.print("Longitude:"); 
  Serial.println(lon,6);  ; 
  Serial.print(lat); 
  Serial.print(" "); 
 }
} 

String latitude = String(lat,6); 
  String longitude = String(lon,6); 
Serial.println(latitude+";"+longitude); 
delay(1000);
String link1=String("https://www.google.com/maps/search/?api=1&query=");
String link2=(String(lat,6) +"%2C"+ String(lon,6));
  String link3=link1+link2;
    Serial.println(link3);
int x=analogRead(A0); 
  Serial.print("gas value:");
  Serial.println(x);
  delay(1000);
   lcd.clear();
  lcd.print("gas value: ");
  lcd.print(x);
  delay(1000);
 if(x>350)
{
  Serial.println("gas high");
  delay(1000);
  SendMessage("gas high");
    delay(2000);
    SendMessage(link3);
     delay(2000);
  digitalWrite(motor,LOW);
  delay(1000);
  digitalWrite(buzzer,HIGH);
  delay(1000);
   
}
 else
 {
  Serial.println("gas low");
  digitalWrite(buzzer,LOW);
  delay(1000);
  digitalWrite(motor,HIGH);
  delay(1000);
 }
  int y=digitalRead(fire); 
  Serial.print("fire value:");
  Serial.println(y);
  delay(1000);
  lcd.clear();
  lcd.print("fire value: ");
  lcd.print(y);
  delay(1000); 
 if(y==0)
{
  Serial.println("fire alert");
  delay(1000);
  SendMessage("fire alert");
   delay(2000);
   SendMessage(link3);
   delay(2000);
  digitalWrite(motor,LOW);
  delay(1000);
  digitalWrite(buzzer,HIGH);
  delay(1000);
   
}
 else
 {
  //Serial.println("no gas");
  digitalWrite(buzzer,LOW);
  delay(1000);
  digitalWrite(motor,HIGH);
  delay(1000);
 }
  int z=digitalRead(ir); 
  Serial.print("ir value:");
  Serial.println(z);
  delay(1000);
  lcd.clear();
  lcd.print("ir value: ");
  lcd.print(z
  );
  delay(1000);
   
 if(z==0)
{
  Serial.println("ir detect");
  delay(1000);
  digitalWrite(motor,LOW);
  delay(1000);
  digitalWrite(buzzer,HIGH);
  delay(1000);
   SendMessage("ir detect");
    delay(2000);
    SendMessage(link3);
     delay(2000);
}
 else
 {
 // Serial.println("normal");
  digitalWrite(buzzer,LOW);
  delay(1000);
  digitalWrite(motor,HIGH);
  delay(1000);
 }
  if (client.connect(TS_SERVER, 80))
  {
    String postStr = TS_API_KEY;
    postStr += "&field1=";
    postStr += String(x);
     postStr += "&field2=";
    postStr += String(y);
    postStr += "&field3=";
    postStr += String(z);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + TS_API_KEY + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    delay(1000);
  }
}