const int dummy = 0;
#define kapitan1o A7
#define kapitan2o A1
#define kapitan3o A2
#define kapitan3i A3
#define kapitan4o A6 
#define handy 12
#define switcheroo 6

int hand=0;

void setup() {
  pinMode(kapitan1o, OUTPUT);
  pinMode(kapitan2o, OUTPUT);
  pinMode(kapitan3o, OUTPUT);
  pinMode(kapitan3i, INPUT);
  pinMode(kapitan4o, OUTPUT);
  pinMode(handy, OUTPUT);
  pinMode(switcheroo, INPUT);
  pinMode(2,INPUT); 


  Serial.begin(9600);

}
//LOOOOOOOOOOOOOOPPPPPPPPP
void loop() {
//Serial.println(digitalRead(switcheroo));
    if(digitalRead(switcheroo) == LOW)
    {
        Serial.println("b100");
    }
//Serial.println(analogRead(kapitan3i));
  if(analogRead(kapitan3i)>=900)
  {
    hand=1;
    Serial.println("a10");
  }
  else
  {
    hand =0;
  }
//Serial.println(digitalRead(switcheroo));
  if( digitalRead(switcheroo) == HIGH && hand ==0)//on/off switch triggered
  {
    Serial.println("a100");
    static uint32_t starttime=millis();
    analogWrite(kapitan1o,1);
    analogWrite(kapitan2o,1);
    analogWrite(kapitan3o,1);
    analogWrite(kapitan4o,1);


    if ( 5000<(millis()-starttime)&&(millis()-starttime) < 10000) //mania start @ 20 seconds
      { 
         digitalWrite(handy,HIGH);
         Serial.println("20000");
         analogWrite(kapitan1o,100);
         analogWrite(kapitan2o,100);
         analogWrite(kapitan3o,100);
         analogWrite(kapitan4o,100);
      }
    if ((millis()-starttime) > 21000)
    {
    digitalWrite(handy,LOW);
    Serial.println("51000");
    analogWrite(kapitan1o,200);
    analogWrite(kapitan2o,200);
    analogWrite(kapitan3o,200);
    analogWrite(kapitan4o,200);
    }
    if ((millis()-starttime) > 54000)//END OF CYCLE
    {
    Serial.println("b100");
    delay(500);
    Serial.println("a100");
    starttime=millis();//RESTART CLOCK
    }
  }
  if( digitalRead(switcheroo) == LOW)
  {
    //do nothing
  }
  delay(100);
}
