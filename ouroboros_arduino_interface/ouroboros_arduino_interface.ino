//Max Value of 5-volt allowed
const float referenceVolts= 5.0;
// battery is connected to analog pin 0 
const int batteryPin = 0;  
 
void setup()
{
  Serial.begin(9600);
}  

void loop() 
{ 
  // read the value from the sensor 
  int val = analogRead(batteryPin); 
  // calculate the ratio
  float volts = (val / 1023.0) * referenceVolts;
  // print the value in volts  
  Serial.println(volts);
}

