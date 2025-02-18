const int sensorPin = A0;
int sensorValue = 0;
float Vin = 5;
float Vout= 0;
float Rref = 99999;
float R = 0;
float val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue =  analogRead(sensorPin);
  //val = map (val, 220, 980, 883, 558);
  //sensorValue = map (sensorValue, 897, 558, 224, 980);
  Serial.println(sensorValue);
  delay(1000);
}
