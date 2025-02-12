// C++ code
//
int pin = 2, i;
int fourthOctave[]={262, 294, 330, 350, 392, 440, 494};

void setup()
{
  Serial.begin(9600); //to seiriako montelo epikoinonias 
  pinMode(pin, OUTPUT);
}

void loop()
{
  for(i=0; i<7; i++)
  {
    tone(pin, fourthOctave[i]);
    Serial.print("Now playing: ");
    Serial.println(fourthOctave[i]);
    delay(350);
  }
  noTone(pin);
  delay(1000); 
}