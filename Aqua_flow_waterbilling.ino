#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
float Fine = 0;
const int input = A0;
void setup()
{
Serial.begin(9600);
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Flow Meter");
lcd.setCursor(0,1);
lcd.print("****************");
delay(2000);
pinMode(input,INPUT);
}
void loop()
{
X = pulseIn(input, HIGH);
Y = pulseIn(input, LOW);
TIME = X + Y;
FREQUENCY = 1000000/TIME;
WATER = FREQUENCY/7.5;
LS = WATER/60;
if(FREQUENCY >= 0)
{
if(isinf(FREQUENCY))
{
lcd.clear();
/* lcd.setCursor(0,0);
lcd.print("VOL. :0.00"); */
lcd.setCursor(0,0);
lcd.print("TOTAL:");
lcd.print( TOTAL);
lcd.print(" L");
lcd.setCursor(0,1);
lcd.print("Bill:");
lcd.print(Fine);
}
else
{
TOTAL = TOTAL + LS;
Serial.println(FREQUENCY);
lcd.clear();
/* //lcd.print("VOL.: ");
//lcd.print(WATER);
//lcd.print(" L/M"); */
lcd.setCursor(0,0);
lcd.print("TOTAL:");
lcd.print( TOTAL);
lcd.print(" Liters");
}
if(TOTAL>1 && TOTAL<2)
{
 Fine =(TOTAL - 1) *1;
 lcd.setCursor(0,1);
 lcd.print("Bill:");
 lcd.print(Fine); 
 lcd.print(" Rupees");
} else if(TOTAL>2 && TOTAL<3)
{
   Fine =(TOTAL - 1) *2;
   lcd.setCursor(0,1);
   lcd.print("Bill:");
   lcd.print(Fine); 
   lcd.print(" Rupees");
}
else if(TOTAL>3)
{
   Fine =(TOTAL - 1) *5;
   lcd.setCursor(0,1);
   lcd.print("Bill:");
   lcd.print(Fine); 
   lcd.print(" Rupees");
}
else
{
  lcd.print("");
}
}
delay(1000);
}
