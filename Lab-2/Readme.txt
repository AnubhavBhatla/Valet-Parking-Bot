Link to Google doc (same content as here, but better formatting): https://docs.google.com/document/d/1s7P3HCT93S5eqoqJRrprgu9JxqpdMddiAdYb99dO29U/edit?usp=sharing
Link to the video (YouTube): https://youtu.be/4tmgnDaWsQg
Link to the video (Drive): https://drive.google.com/file/d/1XbCVRSn_B6beM5f_b6Gv9oyB4AsQUInO/view?usp=share_link

CS684 Lab-2

Anubhav Bhatla, 200070008
M Shashank Balaji, 200070043
Mudit Goyal, 200070045

Assumptions made:
* All turns are at 90 degrees to the straight path, so our input value changes to 11100 or 00111 at the start of a turn.
* Whenever the bot encounters an intersection, it should take a respective turn instead of going straight.
* The bot is perfectly centred in the start box so that once it exits it, we get input values of 00100 (straight path).
* The track’s width is the same as one sensor’s field of view.
* When the bot encounters a 4-way intersection, it will go straight.
* No manual intervention of the bot: it is not picked up nor its position adjusted.
Strategy used


  State description
We have split the control of the bot into two categories: PID control and state-based control. When the bot is going straight or slightly offset from going straight, then the PID controller does the adjustments. When a turn is detected, we take a hard left or a hard right turn and then let the PID controller take control again. The composite state “PID controlled” contains the states “Go straight”, “Left offset” (for when the bot veers off to the left), “Right offset” (for when the bot veers off to the right), and “Stop”. The composite state “Turn” has the states “Turn left” and “Turn right”.


  Inputs
The sensor values, which range from 0 (on white) to 1023 (on black), dictate the transitions between states by raising events. To make it easier to work with the sensor values, we have binarized it by comparing it with a threshold of 340. This can be tuned further based on how the bot performs in real life. The sensors are defined as follows:
* in1 - Left most sensor (LL),
* in2 - 2nd sensor from left (LC),
* in3 - Center sensor (CC),
* in4 - 2nd sensor from right (RC),
* in5 - Right most sensor (RR),
   where, LL, LC, C, RC, RR are the bits (either 0 or 1) after the thresholding is performed.
  
  PID controller
The input to the PID controller is (in1 - in2)*LL + 0.3*(in2 - in4)*C + (in4 - in5)*RR. If only LL is 1, then the bot has veered off to the right too much, thus, needing a larger correction. If LL and LC are both 1, then the correction required is less, which is why they are subtracted. In the case when both LC and C are 1, the correction required is the least. Thus, a factor of 0.3 is multiplied to reduce its contribution. This factor can be fine tuned based on the performance of the bot. If error > 0, then the bot is offset to the right. If error < 0, then the bot is offset to the left. If error = 0, then the bot is centred.
  
  Output
The output of the PID controller is named control. The speed of the left motor is set to base - control and the speed of the right motor is set to base + control. base is the speed common to both the motors, which sets the general swiftness of the bot. This can also be fine tuned based on the performance of the bot in real life. The outputs of the system are dir (the direction of rotation of the wheels), sL (speed of left wheel), and sR (speed of the right wheel). 
  
  Example scenarios
	Our initial state will be the Go Straight state. In the Go Straight state, as long as our input remains 11111, i.e., we are inside the start box, we keep going forward. As soon as we exit the box, our input changes to 00100 and thus the machine transitions remains in the Go Straight state, wherein we output 1 for forward direction and both motors have the same speed of base + control as long as input remains 00100, where base = 30 and control is the output of PID.
	Once we approach a turn, say left turn, since all turns are at 90 degrees, our input(bits) will change to xx100 at the start of the left turn. So, the machine transitions to the Turn Left state. Right after that we transition to the Right offset, which then uses PID to correct the offset created due to the Turn Left state.
	Similarly if I encounter a right turn, the input(bits) change to 001xx, and the machine transitions to the Turn Right state. Right after that we transition to the Right offset, which then uses PID to correct the offset created due to the Turn Left state.
	White Line Sensors is high while the left(right) ones are both low, which means the path is to the right(left) of the bot. In the case where out inputs all turn low (00000), which means Ie have gone completely off the path and our last state was the Turn Right (Turn Left) state, it means that we overshot to the right(left) and thus need to perform a backward right(left) adjust, respectively .
	Once we complete a turn, the input values again change to 00100, machine transitions to the Go Straight state. We remain in this state till the input stays at 00100 and keep outputting 1 for forward direction and both motors have the same speed of (base+control). 
	Suppose the bot was on a straight path and suddenly encounters an input of 11111, i.e., we have reached the Stop box, we transition to the Start state and output 111. We stay in this state till all the input values are high and keep going straight. Once the bot exits the Stop box, we transition to the Stop state and go straight back,i.e., the output is 0 for backward direction and both motors have the same speed of (base+control). This is the final state of the machine.

  Simulation
	Given below are inputs used and the outputs used for performing the simulation:


Input				Current state	Next state	Output
Reset				-		Start		-
1023, 1023, 1023, 1023, 1023	Start		Go straight	1, 30, 30
0, 0, 0, 0, 900		Go straight 	Left offset	1, 81, 0
0, 0, 0, 900, 700		Left offset	Left offset	1, 69, 0
0, 0, 950, 600, 0		Left Offset	Left Offset	1, 29, 31
0, 0, 0, 0, 0			Left Offset	Backward Left	0, 0, 100
0, 0, 800, 500, 0		Backward Left	Left Offset	1, 30, 30
0, 0, 1000, 0, 0		Left Offset	Go Straight	1, 100, 100
900, 0, 0, 0, 0		Go Straight	Right Offset	1, 0, 81
700, 900, 0, 0, 0		Right Offset	Right Offset	1, 0, 69
0, 600, 950, 0, 0		Right Offset	Right Offset	1, 31, 29
0, 0, 0, 0, 0			Right Offset	Backward Right	0, 100, 0
0, 500, 800, 0, 0		Backward Right	Right Offset	1, 30, 30
0, 0, 1000, 0, 0		Right Offset	Go Straight	1, 87, 87
950, 950, 950, 0, 0		Go Straight	Left Turn	1, 0, 100
900, 0, 0, 0, 0		Left Turn	Right Offset	1, 32, 28
0, 0, 1000, 0, 0		Right Offset	Go Straight	1, 30, 30
0, 0, 950, 950, 950		Go Straight	Right Turn	1, 100, 0
0, 0, 0, 0, 900		Right Turn	Left Offset	1, 28, 32
0, 0, 950, 0, 0		Left Offset	Go Straight	1, 30, 30
0, 0, 0, 0, 0			Go Straight	Stop		0, 30, 30
XXXXX				Stop		-		-
