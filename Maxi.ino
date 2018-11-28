#include <LiquidCrystal.h> // includes the LiquidCrystal Library 

LiquidCrystal lcd(3, 2, 4, 5, 6, 7);//LCD object
byte heart[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};//heart on screen
String Name="";
String voice="";
String Mood="";
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  
   lcd.createChar(0, heart);
 lcd.clear();
lcd.print("Hello");
 
}

void loop() {

while(  Serial.available())
{
  char c=(char)Serial.read();
  voice+=c;
  
}delay(2000);
  Serial.print(voice);
  //take data from user


if(voice.length()>0){
  Serial.println(voice);



  

if(voice=="hi")
{lcd.clear();
lcd.print("Hello");


    lcd.clear();
  lcd.print("What is ur name?");
  delay(8000);
  while(  Serial.available())
{
  char a=(char)Serial.read();
  Name+=a;
  Serial.print(Name);
  
}

  lcd.clear();
  lcd.print("hi");
   lcd.setCursor(3,0);
   lcd.print(Name);
   lcd.setCursor(2,1);
   lcd.print("I'm Maxi");
    lcd.print(char(0));
    lcd.print(char(0));
     lcd.print(char(0));
     delay(2500);
     lcd.clear();

     lcd.print("are you ");
     lcd.setCursor(2,1);
     lcd.print("Felling good?");
       delay(8000);
  while(  Serial.available())
{
  char x=(char)Serial.read();
  Mood+=x;
  
}

  if(Mood=="yes")
  {
    lcd.clear();
    lcd.print("el7amdellah");
  
    
    }
    else if(Mood="no")
    {
      lcd.clear();
    lcd.print("m3lish");
 
    
     
      }
   
   
}

else if(voice=="off")
{
  lcd.clear();
  lcd.print("Bye");
  lcd.setCursor(2,1);
  lcd.print("see you Later");
  
  

  
}

Name="";
Mood="";
voice="";

}

}

