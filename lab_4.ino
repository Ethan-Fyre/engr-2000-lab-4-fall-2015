//Step 1 Constants
const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
//Step 3 Constants
int value = 0;
int num = 0;

void setup() {
  // set ledPin to be designated output
  pinMode(ledPin, OUTPUT);
  // set buttonPina to send input
  pinMode(buttonPin, INPUT);
  // begin the Serial
  Serial.begin(9600);
}
// make a function to blink the LED
void blink(int x){
  digitalWrite(x, HIGH);
  delay(500);
  digitalWrite(x, LOW);
  delay(500);
}
void loop() {
  // Define value and buttonState
  value = Serial.read();
  buttonState = digitalRead(buttonPin);
  //step 3
  if (value == 'L'){
    digitalWrite(ledPin, LOW);
  }
  if (value == 'H'){
    digitalWrite(ledPin, HIGH);
  }
  if (value == 'N'){
    num = Serial.parseInt();
    for(int i = 0; i < num; i++){
    blink(ledPin);
    }
  }
  if (value == 'D'){
    Serial.println("CPU: Greetings User. Are you ready to die?");
    blink(ledPin);
  }
  if (value == '?'){
    Serial.println("Press 'H' to turn LED on");
    Serial.println("Press 'L' to turn LED off");
    Serial.println("Press 'N' followed by a number to have the LED blink that many times");
    Serial.println("Press 'D' for a message from the CPU");
    Serial.println("Press 'n' to respond to the CPU");
    Serial.println("Press 'y' to respond to the CPU");
  }
  if (value == 'n'){
    Serial.println("CPU: You Have No Choice In The Matter");
  }
  if (value == 'y'){
    Serial.println("CPU: Good... Very Good");
  }
  //step 1
  //step 2 mod (says 3 2 1 boom, instead of button pressed)
  if (buttonState == HIGH) {
    Serial.println("3");
    delay(500);
    Serial.println("...");
    digitalWrite(ledPin, HIGH);
    delay(500);
    Serial.println("2");
    delay(500);
    Serial.println("...");
    digitalWrite(ledPin, LOW);
    delay(500);
    Serial.println("1");
    delay(500);
    Serial.println("...");
    digitalWrite(ledPin, HIGH);
    delay(500);
    Serial.println("BOOM!!!!");
    digitalWrite(ledPin, LOW);
  }
 
}
