#define SENSE A0         // IR Sensor
#define BUZZER 2         // Buzzer control pin
#define LED 3            // LED indicator pin
#define ALERT_DELAY 3000 // Alert trigger time in ms
#define BLINK_INTERVAL 500 // LED blink interval in ms
#define CLOSED_EYE_THRESHOLD 2000 // Minimum duration for detecting closed eyes in ms

unsigned long eyeClosedStartTime = 0; // Timestamp when eyes are first detected closed
unsigned long alertStartTime = 0;     // Timestamp for the 3-second alert countdown
bool alertInProgress = false;

void setup() {
  pinMode(SENSE, INPUT);       
  pinMode(BUZZER, OUTPUT);     
  pinMode(LED, OUTPUT);        
  Serial.begin(9600);          
}

void loop() {
  if (isEyesClosed()) {
    handleEyesClosed();
  } else {
    resetAlert();
  }
}

bool isEyesClosed() {
  return digitalRead(SENSE) == LOW;
}

void handleEyesClosed() {
  if (eyeClosedStartTime == 0) {
    eyeClosedStartTime = millis(); // Record the time when eyes are first closed
    Serial.println("Eyes closed - timer started");
  }

  unsigned long closedDuration = millis() - eyeClosedStartTime;

  // If eyes remain closed for longer than the threshold, start blinking LED
  if (closedDuration >= CLOSED_EYE_THRESHOLD && closedDuration < ALERT_DELAY) {
    blinkLED();
  }

  // Start alert if eyes remain closed for 3 seconds (ALERT_DELAY)
  if (closedDuration >= ALERT_DELAY && !alertInProgress) {
    triggerAlert();
  }
}

void resetAlert() {
  if (alertInProgress) {
    Serial.println("Eyes opened - buzzer and LED turned off");
  }
  eyeClosedStartTime = 0;
  alertStartTime = 0;
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED, LOW);
  alertInProgress = false;
}

void blinkLED() {
  digitalWrite(LED, (millis() / BLINK_INTERVAL) % 2); // Blink LED every 500 ms
}

void triggerAlert() {
  digitalWrite(LED, HIGH);      // LED stays on
  digitalWrite(BUZZER, HIGH);   // Buzzer on
  alertInProgress = true;
  Serial.println("Alert triggered after 3 seconds of eyes closed");
}
