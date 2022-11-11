int data = 0;

void setup(){
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4, OUTPUT);//digital defindo salida #4
}

// the loop function runs over and over again forever
void loop(){
  if (Serial.available() > 0){
     data = Serial.parseInt(); 
     digitalWrite(4, HIGH);
     Serial.println(data);

     if (data == 1){
        digitalWrite(LED_BUILTIN, HIGH);//apaga
        digitalWrite(4, LOW);
      }else if (data == 0){
        digitalWrite(LED_BUILTIN, LOW);//prende 
        digitalWrite(4, HIGH);    
      }else{
        Serial.print("no conectado");  
      }
  }
}
