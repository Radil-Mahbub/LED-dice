#include <Arduino.h>

//LED pins//
#define one 5
#define two 6
#define three 7
#define four 8
#define five 9
#define six 10

// pin for the button//
#define button 12
int pressed = 0;


void setup() 
{
  
  // set all LED pins to OUTPUT//
  for (int i=one; i<=six; i++)
  {
    pinMode (i, OUTPUT);
  }
  
  pinMode (button, INPUT);
  
  //random seed from analog pin 0//
  randomSeed (analogRead(0));

}


void loop()
{

  // if button is pressed - throw the dice
  pressed = digitalRead (button);
  if (pressed == HIGH)
  {
    // remove previous number
    setAllLEDs (LOW);
    
    buildUpTension();

    int thrownNumber = throwDice();
    showNumber (thrownNumber);
  } 

}



//simulates shaking of dice//
void buildUpTension() 
{

  // left to right
  for (int i=one; i<=six; i++) 
  {
    if (i!=one)
    {
      digitalWrite (i-1, LOW);
    }
    
    digitalWrite (i, HIGH);
    delay (100);
  }

  // right to left
  for (int i=six; i>=one; i--) 
  {
    if (i!=six) 
    {
      digitalWrite (i+1, LOW);
    }
    
    digitalWrite (i, HIGH);
    delay (100);
  }
  
}


//what do if spcific number is shown//
void showNumber(int number) 
{
  
  digitalWrite (one, HIGH);
  
  if (number >= 2) 
  {
    digitalWrite (two, HIGH);
  }
  
  if (number >= 3)
  {
    digitalWrite (three, HIGH);    
  }
  
  if (number >= 4)
  {
    digitalWrite (four, HIGH);    
  }
  
  if (number >= 5) 
  {
    digitalWrite (five, HIGH);    
  }
  
  if (number == 6) 
  {
    digitalWrite (six, HIGH);    
  }
  
}


//gets random number//
int throwDice()
{
  // get a random number in the range [1,6]
  int randNumber = random (1,7);
  return randNumber;
}


void setAllLEDs (int val) 
{ 

  for (int i=one; i<=six; i++) 
  {
    digitalWrite(i, val);
  }
  
}