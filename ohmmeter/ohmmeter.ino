//Inisiasi variabel

#define digithree D3
#define digifour D4
#define digizero D0
#define digifive D5
#define digisix D6

const int sensorPin = A0;
int sensorValue = 0;
float Vin = 5;
float Vout= 0;
int Rref;
float R = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(digithree, INPUT);
  pinMode(digifour, INPUT);
  pinMode(digizero, INPUT);
  pinMode(digifive, INPUT);
  pinMode(digisix, INPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readDigi();
  referenceFormula(Rref);
  Serial.println(sensorValue);
  delay(1000);
}

void readDigi(){
  if(digithree == HIGH){
    Rref = 100;
  } else if(digifour == HIGH){
    Rref = 1000;
  } else if(digizero == HIGH){
    Rref = 10000;
  } else if(digifive == HIGH){
    Rref = 100000;
  } else if(digisix == HIGH){
    Rref = 1000000;
  }
}

float referenceFormula(int Rref){
  sensorValue =  analogRead(sensorPin);
  Vout = (Vin * sensorValue) / 1023;
  R = Rref * (1/((Vin / Vout) - 1));
  return R;
}


