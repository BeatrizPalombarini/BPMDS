#define trigPin1 13
#define echoPin1 12
#define trigPin2 9
#define echoPin2 8
#define trigPin3 5
#define echoPin3 4
#define USONIC_DIV 58.0
#define MEASURE_SAMPLE_DELAY 1 // 5
#define MEASURE_SAMPLES 2 //25
#define MEASURE_DELAY 1 //250

void setup()
{
  Serial.begin(9600);

  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

 digitalWrite(trigPin1, LOW);
 digitalWrite(trigPin2, LOW);
 digitalWrite(trigPin3, LOW);
 delayMicroseconds(500);
}
void loop()
{
  //PRINTLN MM
  
  delay(MEASURE_DELAY);
  long distance1 = measure1();
  long distance2 = measure2();
  long distance3 = measure3();
  if(distance1 > 20 && distance1 < 200){
    buzzer();
  }
  if(distance2 > 20 && distance2 < 200){
    buzzer();
  }

  if(distance3 > 20 && distance3 < 200){
    buzzer();
  }
   Serial.println(distance1);
  Serial.println(distance2);
  Serial.println(distance3);
  Serial.flush();
}
long measure1()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += singleMeasurement1();
  }
  return measureSum / MEASURE_SAMPLES;
}
long measure2()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += singleMeasurement2();
  }
  return measureSum / MEASURE_SAMPLES;
}
long measure3()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += singleMeasurement3();
  }
  return measureSum / MEASURE_SAMPLES;
}
long singleMeasurement1()
{
  long duration = 0;
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  return (long) (((float) duration / USONIC_DIV) * 10.0);
}
long singleMeasurement2()
{
  long duration = 0;
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  return (long) (((float) duration / USONIC_DIV) * 10.0);
}
long singleMeasurement3()
{
  long duration = 0;
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH);
  return (long) (((float) duration / USONIC_DIV) * 10.0);
}

void buzzer()
{
  tone(2,1000);
  delay(600);
  noTone(2);
  //delay(1000);
}
