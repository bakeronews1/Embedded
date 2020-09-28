# Embedded
Embedded-Labs
1
EECE.4520/5520 Microprocessor II and Embedded System Design
Lab 1: Traffic Light Controller
last update: 9/13/20
General Information
Lab Mode: Remote. You need to work on the lab remotely on your own computer with your
own lab kit.
Lab Due Date: Posted in Blackboard. You need to submit all the required deliverables on or
before the due date.
Lab Report Submission: Submit via Blackboard. No email submissions are accepted
Lab Contents: Additional requirements applied for EECE.5520. EECE.5520 (graduate level
section) students need to complete additional lab requirements.
Lab Description
This lab is to design a controller for traffic lights that face one traffic direction. There are three
colors of lights, represented with Red, Yellow, Green LEDs. The traffic lights operate in the
following patterns:
(1) At the start of the system (power up), the Red light flashes until a button is pressed
(2) The Red light stays on for 15 seconds before the Green light is turned on
(3) The Green light stays on for 15 seconds before switching the Yellow light on
(4) The Yellow light stays on for 3 seconds before switching back to Red light
(5) The R-G-Y pattern continues until the system is powered off
(6) An active buzzer beeps for 3 seconds before a light is changed.
Additional requirements for EECE.5520 students
(7) A four-digit 7-Segment display shows the time (in seconds) remaining for each light
Lab Materials:
Required Parts:
Part name Quantity Notes
Arduino board 1
Red LED 1
Green LED 1
Yellow LED 1
220Ohm or 1K Ohm resistor 3
Push switch 1
Active Buzzer 1
4-digit 7-segment display 1 For EECE.5520 only
74HC595 IC 1 For EECE.5520 only
220Ohm resistor 4 For EECE.5520 only
2
assorted jumper wires as needed
Required Software:
(a) Arduino IDE: https://www.arduino.cc/en/main/software
(b) The resource files (sample code and tutorials) from Elegoo:
https://www.elegoo.com/download/
Lab Instructions
Step 1:
You can first check the resource files under the following folders
2.1 LED
2.3 Digital Inputs
2.5 Active Buzzer
3.5 Four Digit Seven Segment Display (for EECE.5520 students only)
These folders contain useful instructions on hardware wiring and sample code to drive these
components. You are strongly suggested to run these examples on your Arduino kit, and build
on them to implement Lab 1.
Step 2:
Using what you learn from Step 1, wire up the Arduino with other components on your
breadboard. Double check the wiring and basic sample code to make sure you can (a) turn
on/off LED (b) detect input from a switch (c) make beep sound with the active buzzer (d) make a
“clock” variable that counts down on every second
Step 3:
You will then need to design a state machine to implement the control logic on the rotating
pattern of traffic lights. The example 3.9 on page 62 of the textbook shows a traffic light control
at a pedestrian crosswalk. You can refer to that as a starting point to design yours for Lab 1.
Step 4:
Based on step 3, Implement the necessary code to represent the states and drive the state
transitions.
EECE5520:
<For 5520 Students>: display the time remaining (in seconds) on the 7-segments.
Step 5:
Test and debug your design.
Step 6:
Record demo video and post it on Youtube.
3
###
Please refer to lab demonstration and report guidelines for demonstration and
report writing.
