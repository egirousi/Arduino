/////////////////////////////////////////////////////////////
// 
// ATtiny85
// 
// 
/////////////////////////////////////////////////////////////

const int RED = 2; // Red LED
const int YEL = 1; // Yellow LED
const int GRN = 0; // Green LED



// Configuração:

// Definir LEDS :
// red Led on e off
#define RedOn()       digitalWrite(RED, HIGH)
#define RedOff()      digitalWrite(RED, LOW)
// Yellow LED on e off
#define YellowOn()    digitalWrite(YEL, HIGH)
#define YellowOff()   digitalWrite(YEL, LOW)
// Green LED on e off
#define GreenOn()     digitalWrite(GRN, HIGH)
#define GreenOff()    digitalWrite(GRN, LOW)
// Timer de espaçamento
#define DelayOne()    delay(5000)
// Timer de espaçamento
#define DelayTwo()    delay(2000)
// Timer de espaçamento
#define DelayThree()  delay(5000)
// Timer de espaçamento
#define DelayFour()   delay(2000)

void setup() {
  // LEDs als Ausgänge:
  pinMode(RED, OUTPUT);
  pinMode(YEL, OUTPUT);
  pinMode(GRN, OUTPUT);
  // erst einmal alle LEDs aus:
  initialize();
}

// Alle LEDs aus:
void initialize() {
  RedOff();
  YellowOff();
  GreenOff(); 
}

// Rotphase:
void phaseOne() {
  RedOn();
  YellowOff();
  GreenOff();
  DelayOne();
}

// RotNachGrünPhase:
void phaseTwo() {
  RedOn();
  YellowOn();
  GreenOff();
  DelayTwo();
}

// Grünphase:
void phaseThree() {
  RedOff();
  YellowOff();
  GreenOn();
  DelayThree();
}

// GrünNachRotPhase:
void phaseFour() {
  RedOff();
  YellowOn();
  GreenOff();
  DelayFour();
}

// Ausfall => Gelbes Signal blinkend:
void emergency() {
  RedOff();
  GreenOff();
  YellowOn();
  delay(500);
  YellowOff();
  delay(500);
}

void loop(){
// Mit Grünphase starten:
 phaseThree();
 phaseFour();
 phaseOne();
 phaseTwo();
}