//https://www.teachmemicro.com/arduino-timer-interrupt-tutorial#crayon-5dac2da71beb1111404788
const int ledPin = 13;
volatile byte state = LOW;

/*     
 *  https://github.com/enjoyneering/RotaryEncoder/blob/master/src/RotaryEncoder.cpp    
 *      - declare all global variables inside ISR as "volatile", it prevent
      compiler to make any optimization & unnecessary changes in the code
      with the variable
 */
 
 
void setup() {
   pinMode(ledPin, OUTPUT);
   TIMSK2 = (TIMSK2 & B11111110) | 0x01;
   TCCR2B = (TCCR2B & B11111000) | 0x07;
}
 
 
void loop() {
   digitalWrite(ledPin, state);
}
 
 
ISR(TIMER2_OVF_vect){
   state = !state;
}
