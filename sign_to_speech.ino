//Declaring Library
#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 5);

//Varriable to store words
char pre[2];
char sentence[20];
char msg;
const int rs = 12, en = 11, d4 = 7, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int mm;
int hh;
int hourr=15;
int minutee=50;
//For a-f
int sensorPin = A0; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor
int i=0;
int a=0;
int c=0;

//For g-l
int sensorPinone = A1; // select the input pin for ldr
int sensorValueone = 0; // variable to store the value coming from the sensor
int j=0;
int b=0;

//For m-s
int sensorPintwo = A2; // select the input pin for ldr
int sensorValuetwo = 0; // variable to store the value coming from the sensor
int k=0;
int ee=0;

//For t-z
int sensorPinthree = A3; // select the input pin for ldr
int sensorValuethree = 0; // variable to store the value coming from the sensor
int l=0;
int f=0;

//For enter data
int sensorPinfour = A4; // select the input pin for ldr
int sensorValuefour = 0; // variable to store the value coming from the sensor
int m=0;
int g=0;
int x=0;

//Send message
int one=3;

//Warning
int two=2;
int r;
int y;

//Emergency
int em=0;
void setup() {
  #ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
  #endif
   if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.begin(16, 2);
  pinMode(sensorPin,INPUT);
  pinMode(sensorPinone,INPUT);
  pinMode(sensorPintwo,INPUT);
  pinMode(sensorPinthree,INPUT);
  pinMode(sensorPinfour,INPUT);
  pinMode(one,INPUT);
  pinMode(two,INPUT);
}



void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int sensorValueone = analogRead(A1);
  int sensorValuetwo = analogRead(A2);
  int sensorValuethree = analogRead(A3);
  int sensorValuefour = analogRead(A4);
  int d= digitalRead(one);
  int e= digitalRead(two);
  
//Code for a-f
if(sensorValue>9){
  i++;
delay(250);
}
if(i==0){

  }
else if(i==1 && a==0){
  lcd.clear();
 pre[0]='\0';
  //Serial.print("A to F");
  lcd.setCursor(0, 0);
  lcd.print("A to F");
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  a=1;
  }
else if(i==2 && a==1){
  lcd.clear();
  pre[0]='\0';
  pre[0]='A';
  //Serial.print(pre);
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  a=0;
  }
 else if(i==3 && a==0){
  lcd.clear();
  pre[0]='\0';
  pre[0]='B';
  //Serial.print(pre);
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  a=1;
  }
else if(i==4 && a==1){
  lcd.clear();
  pre[0]='\0';
  pre[0]='C';
  //Serial.print(pre);
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  a=0;
  }
 else if(i==5 && a==0){
  lcd.clear();
  pre[0]='\0';
  pre[0]='D';
  //Serial.println(pre);
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  a=1;
  }
 else if(i==6 && a==1){
  lcd.clear();
  pre[0]='\0';
  pre[0]='E';
  //Serial.println(pre);
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
   a=0;
  }
else if(i==7 && a==0){
  lcd.clear();
  pre[0]='\0';
  pre[0]='F';
  //Serial.println(pre);
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  a=1;
  }
else if(i>7){
  i=0;
  }
 

//code for g-l

if(sensorValueone>9){
  j++;
delay(250);
}
if(j==1 && c==0){
  pre[0]='\0';
 // Serial.println("G to L");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("G to L");
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  c=1;
  }
else if(j==2 && c==1){
  pre[0]='\0';
  pre[0]='G';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  c=0;
  }
 else if(j==3 && c==0){
  pre[0]='\0';
  pre[0]='H';
 // Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  c=1;
  }
   
else if(j==4 && c==1){
  pre[0]='\0';
  pre[0]='I';
 // Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  c=0;
  }
  
 else if(j==5 && c==0){
  pre[0]='\0';
  pre[0]='J';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  c=1;
  }
  
 else if(j==6 && c==1){
  pre[0]='\0';
  pre[0]='K';
  //Serial.println(pre);
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
   c=0;
  }
  
else if(j==7 && c==0){
  pre[0]='\0';
  pre[0]='L';
 // Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  c=1;
  }
 else if(j>7){
  j=0;
  }


//Code for M-S

if(sensorValuetwo>9){
    k++;
  delay(250);
}
if(k==1 && ee==0){
  pre[0]='\0';
  //Serial.println("Enter Letters From M to S");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("M to S");
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  ee=1;
  
  }
else if(k==2 && ee==1){
  pre[0]='\0';
  pre[0]='M';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  ee=0;
  }
 else if(k==3 && ee==0){
  pre[0]='\0';
  pre[0]='N';
 // Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  ee=1;
  }
   
else if(k==4 && ee==1){
  pre[0]='\0';
  pre[0]='O';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  ee=0;
  }
  
 else if(k==5 && ee==0){
  pre[0]='\0';
  pre[0]='P';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  ee=1;
  }
  
 else if(k==6 && ee==1){
  pre[0]='\0';
  pre[0]='Q';
  //Serial.println(pre);
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
   ee=0;
  }
  
else if(k==7 && ee==0){
  pre[0]='\0';
  pre[0]='R';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  ee=1;
  }
  
else if(k==8 && ee==1){
  pre[0]='\0';
  pre[0]='S';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  ee=0;
  }
else if(k>8){
  k=0;
  }





//Code for T-Z

if(sensorValuethree>9){
    l++;
  delay(250);
}
if(l==1 && f==0){
  pre[0]='\0';
  //Serial.println("Enter Letters From T to Z");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T to Z");
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  f=1;
  }
else if(l==2 && f==1){
  pre[0]='\0';
  pre[0]='T';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  f=0;
  }
 else if(l==3 && f==0){
  pre[0]='\0';
  pre[0]='U';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  f=1;
  }
   
else if(l==4 && f==1){
  pre[0]='\0';
  pre[0]='V';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  f=0;
  }
  
 else if(l==5 && f==0){
  pre[0]='\0';
  pre[0]='W';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  f=1;
  }
  
 else if(l==6 && f==1){
  pre[0]='\0';
  pre[0]='X';
  //Serial.println(pre);
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
   f=0;
  }
  
else if(l==7 && f==0){
  pre[0]='\0';
  pre[0]='Y';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  f=1;
  }
  
else if(l==8 && f==1){
  pre[0]='\0';
  pre[0]='Z';
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  f=0;
  }
else if(l>8){
  l=0;
  }

//Entry Data
if(sensorValuefour>12){
  m++;
delay(70);
}
if(m==0){

  }
else if(m==1 && g==0){
  //Serial.print("Entered data-");
  //Serial.println(pre);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Entered data-");
  lcd.print(pre);
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  g=1;
  }
else if(m==2 && g==1){
  //Serial.println("Are You Sure?");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Are You Sure?");
  lcd.setCursor(0, 1);
  lcd.print(sentence);
  g=0;
  }
 else if(m==3 && g==0){
  sentence[x]=pre[0];
    x++;
    //Serial.print("Total-");
    //Serial.println(sentence);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Confirmed?-");
    lcd.print(pre);
    lcd.setCursor(0, 1);
    lcd.print(sentence);
    delay(100);
    i=0;
    j=0;
    k=0;
    l=0;
    g=1;
  }
  else if(m>3){
    m=0;
    }

//Message Send

 if(d==HIGH )
  {
   SendMessage();
    //Serial.println("Sent");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sent");
    pre[0]='\0';
    delay(400);
  for(;x>=0;x--){
    sentence[x]='\0';
    } 
     lcd.setCursor(0, 1);
    lcd.print(sentence);     
    i=0;
    j=0;
    k=0;
    l=0;
    g=1;
  }


  //Warning
 else if(e==HIGH){
  Sendmessage();
  lcd.clear();
  lcd.setCursor(0, 0);
    lcd.print("Sent help?");
     lcd.setCursor(0, 1);
    lcd.print(sentence);
    delay(400);
     i=0;
    j=0;
    k=0;
    l=0;
    g=1;
    pre[0]='\0';

  }

//Medical Support
 DateTime now = rtc.now();
  hh=now.hour();
  mm=now.minute();
  if(hh==hourr && em==0){
    emergency();
    em=1;
    }
}


//Message function


void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+8801772208691\"\r"); // Replace x with mobile number
  delay(1000);
  //Serial.println("SENDING");
  mySerial.println(sentence);// The SMS text you want to send
  delay(100);
  Serial.println("SENT//");
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }

//Warning Message

void Sendmessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+8801772208691\"\r"); // Replace x with mobile number
  delay(1000);
  //Serial.println("SENDING");
  mySerial.println("Help Needed//");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }
 
//Emergency


void emergency()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+8801772208691\"\r"); // Replace x with mobile number
  delay(1000);
  //Serial.println("SENDING");
  mySerial.println("Its time to take medicine.Give patient the proper medicine.");// The SMS text you want to send
  delay(100);
  Serial.println("SENT");
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }

