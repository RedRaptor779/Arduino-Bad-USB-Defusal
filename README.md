# Arduino-Bad-USB-Defusal
A foundation of code that allows for an Arduino Micro Bad USB to be defused for development purposes.

## Hardware and Pre-Requisite 
This was developed for an Arduino Micro. 
Arduino IDE or a Serial Connection to the Arduino is required for defusal.

# Useage 
### Defusal
Open Arduino IDE or setup a serial session for the Arduino, DO NOT CONNECT THE ARDUINO LOADED WITH A PAYLOAD UNTIL A SERIAL SESSION IS ESTABLISHED. To do this in the Arduino IDE application: 
1. Select the Arduino Micro device
2. Select the Serial Monitor icon:
<img width="45" height="36" alt="image" src="https://github.com/user-attachments/assets/a3441f5a-1932-4b69-bc83-4893a5dfbb5c" />

3. Select the "Serial Monitor" tab
4. There should be a yellow banner presented that displays: "Not connected. Select a board and port to connect automatically"
5. Connect the Bad USB
6. To defuse the Bad USB before execution, type "d" into the "Message" line and press enter. You have 5 seconds before the payload executes.

<img width="481" height="242" alt="image" src="https://github.com/user-attachments/assets/6a65ce22-efa0-4e38-a77c-4cade3f8790a" />

### Payload Addition
Code to be executed should be placed into the ```codeExecution()``` function. It currently uses a hello world function as a placeholder.

```ino
void codeExecution (){
      // Code to execute goes here:
      Keyboard.begin();
      Keyboard.print("Hello world");
      Keyboard.end();

}
```
