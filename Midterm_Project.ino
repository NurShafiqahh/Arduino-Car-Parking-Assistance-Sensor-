int distance = 0;	//declare variable for containing distance sensor
int inches   = 0;          ;	//for Ultrasonic Sensor
int cm = 0;
 
 void setup()
{  
  Serial.begin(9600);	 	//Send the data rate in bits per second for serial data
  pinMode(13, OUTPUT); 		//set LED (green) as output
  pinMode(12, OUTPUT); 		//set LED (yellow) as output
  pinMode(11, OUTPUT); 		//set LED (red) as output
  pinMode(6,  OUTPUT); 		//set the trigger pin as output
  pinMode(5,  INPUT); 		//set the echo pin as input  
  

}

void loop()
{
  int pulse1;
  distance = 333;	           // The maximum distance for sensor
  digitalWrite(6, HIGH);	   //Set the trigger pin on
  delay(1000);
  digitalWrite(6,LOW);		   //Set the trigger pin off
  pulse1 = pulseIn(5,HIGH);	   //Echo pin turn on to give pulse before
  cm = 0.01723 * pulse1;	   //The program start
  inches = ((cm *50)/127);
  Serial.print(inches);
  Serial.print ("in,");
  Serial.print(cm);
  Serial.println("cm");
  delay(1000);                  // Wait for 1000 millisecond(s)

    if (cm > distance) 
  {
    digitalWrite(13, LOW);  //Green LED turn ON
    digitalWrite(12, LOW);	//Yellow LED turn OFF
    digitalWrite(11, LOW);	//Red LED turn OFF

  }
  
  else if (cm <= distance - 60 && cm > distance - 149)
  {
    digitalWrite(13, HIGH);	//Green LED turn ON
    digitalWrite(12,  LOW);	//Yellow LED turn OFF
    digitalWrite(11,  LOW);	//Red LED turn OFF

    
  }
  else if (cm <= distance - 150 && cm > distance - 249 ) 
  {
    digitalWrite(13, LOW);	//Green LED turn OFF
    digitalWrite(12, HIGH);	//Yellow LED turn ON
    digitalWrite(11,  LOW);	//Red LED turn OFF
   
  }
  else if (cm <= distance - 250 && cm > distance - 310) 
  {
    digitalWrite(13, LOW);	//Green LED turn OFF
    digitalWrite(12, LOW);	//Yellow LED turn OFF
    digitalWrite(11, HIGH);	//Red LED turn ON
    
  }
  
  delay(1000);             // Wait for 1000 millisecond(s)

}