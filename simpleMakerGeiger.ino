#define MAXCNT 100 
#define CalFactor 1 
volatile int counter = 0; 
unsigned long oldTime = 0; 
volatile 
bool speaker=0;
void setup()
{
Serial.begin
(9600);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
speaker=0;  
attachInterrupt(digitalPinToInterrupt(0), count, FALLING); 
}
void loop()
{
  unsigned long time; 
  unsigned long dt; 
  float rate; 
  int err;
  if (counter == MAXCNT) { 
  detachInterrupt(digitalPinToInterrupt(0)); 
  time = millis(); 
  dt = time-oldTime; 
  rate = (float)MAXCNT*60.0*1000.0/(float)dt/CalFactor; 
  Serial.println(round(rate));
  oldTime = millis(); 
  counter = 0;     
  attachInterrupt(digitalPinToInterrupt(0), count, FALLING);   
  }   
}
void count() 
{ 
  if (speaker) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW); 
  speaker = 0;   
}
else {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH); 
  speaker = 1;   
}  
counter++; 
}
