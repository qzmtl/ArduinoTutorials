#define RED_MOSFET 9
#define GREEN_MOSFET 10
#define BLUE_MOSFET 11

int rgb[3] = {0,0,0};

// Helper function setRGB: sets the LEDs
void setRGB(int R, int G, int B){
  analogWrite(RED_MOSFET,R);
  analogWrite(GREEN_MOSFET,G);
  analogWrite(BLUE_MOSFET,B);
}

// Setup function: set the baud rate to the 
// one used by your bluetooth and the LED pins to OUTPUT
void setup() {
  Serial.begin(9600);
  pinMode(RED_MOSFET,OUTPUT);
  pinMode(GREEN_MOSFET,OUTPUT);
  pinMode(BLUE_MOSFET,OUTPUT);
}

void loop() {
  
  if(Serial.available() > 0){
     // If data has come through the serial port, parse it
     String msg = Serial.readStringUntil('\n');
     String command = msg.substring(0,3);
     String message = msg.substring(3);

     // If the command is "rgb", parse the triplet
     if(command == "rgb")
     {
        // Use strtok to separate the values
        char * unparsedValues = strtok( message.c_str()," ,");
        int k = 0;
        while (unparsedValues != NULL && k < 3)
        {
          // Use atoi to convert the string to an integer
          rgb[k] = atoi(unparsedValues);
          // Use strtok to separate the values
          unparsedValues = strtok(NULL, " ,");
          k = k + 1;
        }
        //msg.c_str()
     }    
  }

  // Call setRGB to set the LED values
  setRGB(rgb[0],rgb[1],rgb[2]);
   
}
