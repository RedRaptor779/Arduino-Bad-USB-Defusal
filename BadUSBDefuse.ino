#include <Keyboard.h>

bool disarmed = false;
String input = "";

unsigned long startTime;
const unsigned long window = 5000; // 5 seconds

void setup() {
  Serial.begin(9600);

  delay(2500);

  startTime = millis();

  Serial.println("SYSTEM ARMED");
  Serial.println("Send 'd' to DISARM within 5 seconds");
}

void loop() {

  // -----------------------------
  // READ SERIAL INPUT
  // -----------------------------
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {

      input.trim();

      // DISARM command
      if (input == "d") {
        disarmed = true;
        Serial.println("DISARMED");
      }

      input = "";

    } else {
      input += c;
    }
  }

  // -----------------------------
  // COUNTDOWN DISPLAY
  // -----------------------------
  unsigned long elapsed = millis() - startTime;

  if (elapsed < window && !disarmed) {
    unsigned long remaining = (window - elapsed) / 1000;

    // Print countdown once per second (not every loop iteration)
    static int lastPrinted = -1;

    if ((int)remaining != lastPrinted) {
      lastPrinted = remaining;

      Serial.print("Time left: ");
      Serial.print(remaining);
      Serial.println("s");
    }
  }

  // -----------------------------
  // EXECUTE AFTER WINDOW
  // -----------------------------
  if (elapsed >= window) {

    if (!disarmed) { // Code for execution
      Serial.println("Executing HID...");

      codeExecution();

    } else {
      Serial.println("Execution cancelled.");
    }

    // Freeze forever
    while (true) {
      delay(1000);
    }
  }
}

void codeExecution (){
      // Code to execute goes here:
      Keyboard.begin();
      Keyboard.print("Hello world");
      Keyboard.end();

}