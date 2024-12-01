int ledPins[4] = { 2, 3, 4, 7 };

int buttonPins[4] = { 29, 30, 31, 32 };

int buttonOn[4] = { LOW, LOW, LOW, LOW };
int buttonState[4] = { LOW, LOW, LOW, LOW };
int lastButtonState[4] = { LOW, LOW, LOW, LOW };
int currentStep = 0;
int tempoPot = A16;

long timeBetweenSteps = 1000;
long lastStepChangeTime = 0;

void setup() {
  // put your setup code here, to run once:
  
  delay(2000);
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  checkButtons();
  checkLeds();


  //If it's time to go to the next step
    //Add 1 to currentStep

  if (millis() > lastStepChangeTime + timeBetweenSteps) {
    currentStep++;
    lastStepChangeTime = millis();

    if (currentStep == 4) {
      currentStep = 0;
    }
  }
  
  if(buttonState[i], HIGH);
  digitalWrite(ledPins[i], HIGH);
  else(ledPins[i]), LOW);






}
void checkButtons() {

  for (int i = 0; i < 4; i++) {
    lastButtonState[i] = buttonState[i];
    buttonState[i] = digitalRead(buttonPins[i]);

    if (lastButtonState[i] == LOW and buttonState[i] == HIGH) {
      buttonOn[i] = !buttonOn[i];
      delay(5);
    } else if (lastButtonState[i] == HIGH and buttonState[i] == LOW) {
      delay(5);
    }
  }
}

//shoud it include led array in the code above ^^


void checkLeds() {

  for (int i = 0; i < 4; i++) {
    if (i == currentStep) {
      analogWrite(ledPins[i], 100);
    } else {
      if (buttonOn[i] == HIGH) {
        analogWrite(ledPins[i], 50);
      } else if (buttonOn[i] == LOW) {
        analogWrite(ledPins[i], 0);
      }
    }

  } 
  
}
