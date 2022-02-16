const int ultraPIN = 7;
const int redPIN=3;     //Pins declaration
const int buzzPIN=4;
void setup() {

  Serial.begin(9600);
  pinMode(redPIN,OUTPUT);  //Assigning actuators to the right Mode
  pinMode(buzzPIN,OUTPUT);
  
}

void loop() {

  long duration,cm; //decralatio  of duration and cm

 
  pinMode(ultraPIN, OUTPUT);
  digitalWrite(ultraPIN, LOW);   //Putting on and off the Ultrasonic sensor to detect obstacle every less than second
  delay(900);
  digitalWrite(ultraPIN, HIGH);
  delay(900);
  digitalWrite(ultraPIN, LOW);

  pinMode(ultraPIN, INPUT);
  duration = pulseIn(ultraPIN, HIGH); //geting duration from Ultrasonic sensor

  // convert the duration centimenters
  cm = microsecondsToCentimeters(duration);

 
  Serial.print(cm);
  Serial.print("cm"); //Printing the centimiters on Serial monitor
  Serial.println();
  
  if(cm <60){                // IF condition to detect if distance is below 60 cm
    digitalWrite(redPIN,HIGH); // lighting the LED
    delay(1000);
    digitalWrite(buzzPIN,HIGH); //Buzzing the PIEZO
    delay(1000);
  }
  
  else{ 
    digitalWrite(redPIN,LOW);     //Stoping th LIGHT
    digitalWrite(buzzPIN,LOW);     // Stoping the Piezo
  }
}

long microsecondsToCentimeters(long microseconds) { //Function to convert duration to cm
  return microseconds / 29 / 2;
}