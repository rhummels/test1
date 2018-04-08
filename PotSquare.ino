unsigned long t;
float a;
float b;
float c;
float g;

int POT=0;    //Potentiometer Read Pin
float ConstP=1/102.3;     //Scales the potentiometer read
float HH=10;   //Desired High Hertz
float HL=.1; //Desired Low Hertz
float XP=.99;
float CP;
float P;
float V;


void setup() {
  Serial.begin(9600);     // initialize serial comm
  pinMode(8,OUTPUT);      // sets pin 8 to output
  pinMode(0,INPUT);       // sets pin A0 to input
  pinMode(POT,INPUT);     // sets POT to input
}

void loop() {
    //(float)analogRead(0)/1024*5

    P=((float)analogRead(POT))*ConstP;                // Reads the Potentiometer  
    CP=(HL+(XP*P))/2;                     
    
    
    t = millis();                                     // Continous time clock of board (in ms)
    g=((1000/CP))/2;                                   // sets g to half of frequency in (in ms)

    a=t+g;                                            // sets a value to the current time plus half frequency time
    b=a+g;                                            // sets b value to the current time plus full frequency time
    
    V=3.5;                                             // Set Output voltage to High
    do{
      c= millis();                                    // reads the current board time
      Serial.print(c);                                // print time (in ms) 
      Serial.print(",");                              // print comma delimiter
      Serial.print(V);      // print Input Voltage
      Serial.print(",");                              // print comma delimiter
      Serial.println(0);    // print Output Voltage
    }while(c<a);


    V=0;                             // Sets output voltage to Zero
    do{
      c= millis();                                    // reads the current board time
      Serial.print(c);                                // print time (in ms) 
      Serial.print(",");                              // print comma delimiter
      Serial.print(V);      // print Input Voltage
      Serial.print(",");                              // print comma delimiter
      Serial.println(0);    // print Output Voltage
    }while(c>a && c<=b);
    
    
}

