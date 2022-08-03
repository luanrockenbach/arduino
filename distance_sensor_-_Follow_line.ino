//Line Sensor
int rightSensor = A3;
int middleSensor = A4;
int leftSensor = A5;
int led = 13;

// Wheels
#define left_wheelGo 3
#define left_wheelBack 5
#define right_wheelGo 6
#define right_wheelBack 9

// Motor speed
int max_speed = 255;
int middle_speed = 120;
int min_speed = 50;

// Ultrasonic sensor
#define echo 7
#define trigger 8

int sensorControll = 28;
int buzzer = 12;


void serialPrint(char sensor, int value)
{
  Serial.println("Sensor "+(String)sensor+" value="+(String)value);
}

// ----------------------------------------- BUZZER ---------------------------------------

int buzzy(unsigned int timing) // gera buzina por 'ms'
{
  digitalWrite(buzzer, HIGH);
  delay(timing);
  digitalWrite(buzzer, LOW);
}

void angry_buzzy(){
  buzzy(2000); // buzina por 2s
  delay(200);
  buzzy(200); // buzina por 0,5s
  delay(200);
  buzzy(200); // buzina por 0,5s
  delay(100);
  buzzy(500); // buzina por 0,5s
}

// ------------------------------------ OBSTÁCULO -----------------------------------------

void barrier()
{
  if(superSonic() <= 10)
  {
    stopMotor();
    angry_buzzy();
  }
}


// ------------------------------ LEITURA DOS SENSORES -------------------------------------
int rightSensorFunction()
{
  int value = analogRead(rightSensor);
  //serialPrint('R', value);
  return(value);  
}

int leftSensorFunction()
{
  int value = analogRead(leftSensor);
  //serialPrint('L', value);
  return(value);  
}

int middleSensorFunction()
{
  int value = analogRead(middleSensor);
  //serialPrint('M', value);
  return(value);  
}

// ------------------------------- CONTROLE DE MOTORES -----------------------------------------

void stopMotor()
{
  analogWrite(left_wheelGo, 0);
  analogWrite(left_wheelBack, 0);
  analogWrite(right_wheelGo, 0);
  analogWrite(right_wheelBack, 0);
}

void dickVigarista(const int right, const int left)
{
  analogWrite(right_wheelGo, right);
  analogWrite(right_wheelBack, 0);
  
  analogWrite(left_wheelGo, left + 1);
  analogWrite(left_wheelBack, 0);
}

// ------------------------------- LEITURA SUPERSÔNICO ------------------------------------------

int superSonic() // retorna distância estimada em cm
{
  long int lenght;
  int distance; /* em cm */

  digitalWrite(trigger, LOW);
  delay(100);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  lenght = pulseIn(echo, HIGH, 100000);
  distance = lenght * 0.034 / 2;
  return(distance);
  }

// ------------------------------------ CONTROLE ------------------------------------------------

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led,HIGH);

  pinMode(left_wheelGo, OUTPUT);
  pinMode(left_wheelBack, OUTPUT);
  pinMode(right_wheelGo, OUTPUT);
  pinMode(right_wheelBack, OUTPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);


  stopMotor();
}

void loop() {
  // put your main code here, to run repeatedly:
  int d = superSonic();
  Serial.println(d);

   while(rightSensorFunction() >sensorControll && leftSensorFunction() >sensorControll)
   {
    dickVigarista(middle_speed, middle_speed);
   }
    
   while(rightSensorFunction() > sensorControll && leftSensorFunction() <= sensorControll)
   {
    dickVigarista(middle_speed, min_speed);
   }
  
   while(rightSensorFunction() <= sensorControll && leftSensorFunction() > sensorControll)
   {
    dickVigarista(min_speed, middle_speed);
   }
  
   if(rightSensorFunction() <=sensorControll && leftSensorFunction() <=sensorControll)
   {
    stopMotor();
   }
}
