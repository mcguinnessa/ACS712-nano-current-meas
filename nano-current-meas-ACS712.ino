

void setup() {
  Serial.begin(9600); //Start Serial Monitor to display current read value on Serial monitor
}


void loop()
{
  int sensitivity = 185;
  int offsetVoltage = 2500;
  double adcVoltage = 0;
  double currentValue = 0;
  int adcValue= 0;

  adcValue = analogRead(A0);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  
  Serial.print("Raw Sensor Value = " );
  Serial.print(adcValue);
  
  delay(2000);

  Serial.print("\t Voltage(mV) = ");
  Serial.print(adcVoltage,3);
  
  delay(2000);
 
  Serial.print("\t Current = ");
  Serial.println(currentValue,3);
 
  delay(2500);
}


//void loop() {
//  unsigned int x=0;
//  float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;
//
//  for (int x = 0; x < 150; x++){ //Get 150 samples
//    AcsValue = analogRead(A0);     //Read current sensor values   
//    Samples = Samples + AcsValue;  //Add samples together
////    Serial.print(AcsValue);
//    delay (3); // let ADC settle before next sample 3ms
//  }
//  AvgAcs=Samples/150.0;//Taking Average of Samples
//  Serial.print(" Av:");
//  Serial.print(AvgAcs);
//  Serial.print(" ");
//
//  //((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
//  //2.5 is offset(I assumed that arduino is working on 5v so the viout at no current comes
//  //out to be 2.5 which is out offset. If your arduino is working on different voltage than 
//  //you must change the offset according to the input voltage)
//  //0.185v(185mV) is rise in output voltage when 1A current flows at input
//  float offset = 2.5;
////  float offset = 11.14;
//  AcsValueF = (offset - (AvgAcs * (5.0 / 1024.0)) )/0.185;
//
//  Serial.print(AcsValueF);//Print the read current on Serial monitor
//  Serial.print("\n");
//  delay(50);
//}
