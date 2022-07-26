int rightSensor = A3;
int middleSensor = A4;
int leftSensor = A5;

int led = 13;


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


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led,HIGH);
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
}
