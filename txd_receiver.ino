#define txdPin 2

volatile unsigned long lastChangeTime = 0;
volatile unsigned long pulseDuration = 0;
volatile bool newPulse = false;

const int maxBits = 24;
char bitBuffer[maxBits + 1];
volatile int bitIndex = 0;
volatile bool bitSequenceComplete = false;

void setup() {
  pinMode(txdPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(txdPin), handleInterrupt, CHANGE);
  Serial.println("Ready to capture");
  bitBuffer[maxBits] = '\0'; 
}

void loop() {
  if (bitSequenceComplete) {
    noInterrupts();
    Serial.print("Captured bits: ");
    Serial.println(bitBuffer);
    bitIndex = 0;
    bitSequenceComplete = false;
    interrupts();
    delay(2000); 
  }
}

void handleInterrupt() {
  unsigned long now = micros();
  pulseDuration = now - lastChangeTime;
  lastChangeTime = now;

  if (pulseDuration > 500000) {
    bitIndex = 0;
    return;
  }

  char bitVal = '?';
  if (pulseDuration > 900 && pulseDuration < 1300) {
    bitVal = '0';
  } else if (pulseDuration > 200 && pulseDuration < 500) {
    bitVal = '1';
  }

  if (bitVal != '?') {
    if (bitIndex < maxBits) {
      bitBuffer[bitIndex++] = bitVal;
      if (bitIndex == maxBits) {
        bitSequenceComplete = true;
      }
    }
  }
}
