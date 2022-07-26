int rightSensor = A3;
int middleSensor = A4;
int leftSensor = A5;

int led = 13;

#define left_wheelGo 3
#define left_wheelBack 5
#define right_wheelGo 6
#define right_wheelBack 9

int max_speed = 255;
int middle_speed = 150;
int min_speed = 50;


void serialPrint(char sensor, int value)
{
  Serial.println("Sensor "+(String)sensor+" value="+(String)value);
}


// LEITURA DOS SENSORES
int rightSensorFunction()
{
  int value = analogRead(rightSensor);
  serialPrint('R', value);
  return(value);  
}

int leftSensorFunction()
{
  int value = analogRead(leftSensor);
  serialPrint('L', value);
  return(value);  
}

int middleSensorFunction()
{
  int value = analogRead(middleSensor);
  serialPrint('M', value);
  return(value);  
}

void stopMotor()
{
  analogWrite(left_wheelGo, 0);
  analogWrite(left_wheelBack, 0);
  analogWrite(right_wheelGo, 0);
  analogWrite(right_wheelBack, 0);
}

void dickVigarista()
{
  analogWrite(right_wheelGo, middle_speed);
  analogWrite(left_wheelGo, middle_speed);
}

void rightCurve()
{
  analogWrite(right_wheelGo, min_speed);
  analogWrite(left_wheelGo, middle_speed);
}

void leftCurve()
{
  analogWrite(right_wheelGo, middle_speed);
  analogWrite(left_wheelGo, min_speed);
}


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

  stopMotor();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Right Sensor:");
  rightSensorFunction();
  delay(100);

  Serial.println("Middle Sensor:");
  middleSensorFunction();
  delay(100);

  Serial.println("Left Sensor:");
  leftSensorFunction();
  delay(100);

  dickVigarista();
  
}
