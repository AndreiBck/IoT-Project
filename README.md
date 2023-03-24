# IoT - Project

# Overview
  The current project demonstrates how to use ultrasonic and infrared sensors, LEDs, resistors and LED displays together with an Arduino board.
  The project has two main functionalities:
  * distance detection with the ultrasonic sensor. This sensor detects the distance to an object in front of it and lights up one of the bulbs depending on this distance:
    * the green bulb: if the distance between the sensor and the object is greater than 25cm
    * the yellow bulb: if the distance between the sensor and the object is between 10 and 25 cm
    * the red bulb: if the distance between the sensor and the object is less than 10 cm
  * signal sending via the IR remote. 
    * if the users presses any number between 0 and 9 on the remote, the seven segments LED will display the number
    * if the users presses any other button, the seven segments LED will display "-"
# Schematics Plan
![Schita-AT](https://user-images.githubusercontent.com/100125385/227187876-f32b6091-2a80-4ef5-8849-7208444ac77c.png)
# Pre-requisites
* Arduino IDE: https://www.arduino.cc/en/software
* Arduino compatible board (in this case Arduino UNO is used)
* 3 LEDs of 3 different colors (in this case green, yellow and read LEDs)
* 3 220R resistors
* 1 1k resistor
* 1 seven segments LED display
* 1 ultrasonic sensor
* 1 infrared sensor
* 22 jumper wires
* 1 IR Remote

# Setup and Build Plan
* Assemble the project following the presented schemes
* Clone the git repository: 
  * https://github.com/AndreiBck/IoT-Project.git
  * Command: $ git clone https://github.com/AndreiBck/IoT-Project.git
  * Connect the Arduino board to the PC
  * Select the board and port from the Arduino IDE
  * Upload the code to the Arduino board by pressing the "Upload" button from the IDE
# Running
  * After uploading the code, it will start running
  * For the **distance detection funtionality** : move an object closer and further away from the sensor and the light bulbs will indicate the change
  * For the **signal sending funtionality** : press the buttons on the remote and the result will be displayed by the seven segments leds


