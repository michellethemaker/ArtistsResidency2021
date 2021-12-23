/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int ch1 = 3;           // channel 1 of relay, pin D3 of arduino


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ch1, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ch1,LOW);
  delay(1000);
  digitalWrite(ch1,HIGH);
  delay(1000);
}
