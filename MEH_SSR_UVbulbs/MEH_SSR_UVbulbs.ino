
int ch1 = 2; //channel 1 of SSR, pin D2 of arduino
int triggerType = LOW;// LOW if ssr is low level trigger. vice versa for high level trigger
int ssrON, ssrOFF;// used for two different SSR trigger type. Do not change

void setup() {
  pinMode(ch1, OUTPUT);//define ch1Pin as output
  if(triggerType == LOW)
    {
      ssrON = LOW;
      ssrOFF = HIGH;
    }
  else
    {
      ssrON = HIGH;
      ssrOFF = LOW; //if trigger type is HIGH
    }
  digitalWrite(ch1,ssrON);// set initial state of SSR 1: ON
}

void loop() {
  digitalWrite(ch1,ssrON);// turn lamp on
  delay(10000);
  digitalWrite(ch1,ssrOFF);// turn lamp off
  delay(3000);

}
