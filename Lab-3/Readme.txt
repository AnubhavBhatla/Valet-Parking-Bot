CS684 Lab-3

Anubhav Bhatla, 200070008
M Shashank Balaji, 200070043
Mudit Goyal, 200070045

Google doc link: https://docs.google.com/document/d/1IY27ymtJDUmkggRhEULFhRhTZoeVaJqriloTDw0M-Vg/edit?usp=sharing
Video link: https://youtu.be/ViHj-tyoxao

Assumptions made:
* All turns are at 90 degrees to the straight path, so our input value changes to 11100 or 00111 at the start of a turn.
* Whenever the bot encounters an intersection, it should take a respective turn instead of going straight.
* The bot is perfectly centred in the start box so that once it exits it, we get input values of 00100 (straight path).
* The track’s width is the same as one sensor’s field of view.
* When the bot encounters a 4-way intersection, it will go straight.
* No manual intervention of the bot: it is not picked up nor its position adjusted.
* When we face the object head-on, if the irl sensor value is higher than the irr value, we take a left turn and vice-versa.
* When we are following the object and want to get back on the white path, once we encounter cc > threshold_pid, we go back to the Line_follow state.

Strategy used

State description
We have split the control of the bot into two categories: Line_follow and Obstacle_follow. When the bot is going straight or slightly offset from going straight, then the automaton defined in the Line_follow state does the adjustments. When a turn is detected, we take a hard left or a hard right turn which are again defined as states in the Line_follow automaton. The Line_follow automaton contains the states “Straight”, “Left_offset” (for when the bot veers off to the left), “Right_offset” (for when the bot veers off to the right), “Turn left” (all three left sensor values are high), “Turn right” (all three right sensor values are high), “Right_back” (we were to the right of the line and all sensor values become high), “Left_back” (we were to the right of the line and all sensor values become high), and “Stop”. The Obstacle_follow automaton is triggered when irc < threshold_ir. We start in the Dummy state which decides if we need to take a left turn or a right turn. We have the “Dummy”, “Left_turn”, “Right_turn”, and “Forward” states. We again go back to the Line_follow automaton once cc > threshold_pid.

Inputs
The sensor values, which range from 0 (on white) to 1023 (on black), dictate the transitions between states by raising events. To make it easier to work with the sensor values, we have binarized it by comparing it with a threshold of 400. This can be tuned further based on how the bot performs in real life. The sensors are defined as follows:
* ll_1 - Leftmost WL sensor (LL),
* lc_1 - 2nd WL  sensor from left (LC),
* cc_1 - Center WL sensor (CC),
* rc_1 - 2nd WL sensor from right (RC),
* rr_1 - Rightmost WL sensor (RR),
* irl  - Leftmost IR sensor,
* irc -  Center IR sensor,
* irr  - Rightmost IR sensor,
   where, LL, LC, CC, RC, RR are defined as 1023 - ll_1, … due to white-line following instead of black-line following.
  
PID logic
The input to the PID controller is (50*LL + 40*LC + 30*CC + 20*RC + 10*RR)/(LL + LC + CC + RC + RR) - 30. The offset is subtracted to make sure that if the left sensors have low values (white line), then the error > 0, and the bot is offset to the right. If the right sensors have low values, then error < 0, and the bot is offset to the left. If error = 0, then the bot is centred.

Output
The output of the PID controller is named control. The speed of the left motor is set to base - control and the speed of the right motor is set to base + control. base is the speed common to both the motors, which sets the general swiftness of the bot. This can also be fine tuned based on the performance of the bot in real life. The outputs of the system are dir (the direction of rotation of the wheels), sL (speed of left wheel), and sR (speed of the right wheel). 

Example scenarios
We describe what happens when the bot encounters an obstacle. Before encountering the obstacle, the bot is in the line following state. The transition to the obstacle following state is triggered by irc < threshold_ir. Within the obstacle following state, we go to the dummy state to decide whether to take left or right. If the obstacle is more to the left than to the right then we take right and vice versa. Without the loss of generality, let’s assume we take a right. We keep taking a sharp right turn (left motor at 100, right motor at 0) until irl is low enough. Once that happens, we keep going straight. We take a left turn if there’s nothing to the left, whereas previously there was, and similarly for right turn.
The PID control is the same as what we implemented for the previous lab (except for the bugs).

Simulation
The following are the inputs-outputs for the bot. We have tried to emulate the 
arena as closely as possible 


Given below are inputs used and the outputs used for performing the simulation:

WL Sensor			IR Sensor		State			Output
1000, 1000, 50, 1000, 1000	1000, 1000, 1000	Line, straight		1, 40, 40
1000, 1000, 1000, 100, 300	1000, 1000, 1000	Line, left offset	1, 68, 12
1000, 1000, 50, 1000, 1000	900, 50, 700		Obstacle, left turn	2, 0, 100
1000, 1000, 1000, 1000, 1000	1000, 200, 600		Obstacle, left turn	2, 0, 100
1000, 1000, 1000, 1000, 1000	1000, 600, 200		Obstacle, left turn	2, 0, 100
1000, 1000, 1000, 1000, 1000	1000, 1000, 50		Obstacle, forward	1, 40, 40
1000, 1000, 1000, 1000, 1000	1000, 1000, 1000	Obstacle, right turn	3, 100, 0
1000, 1000, 1000, 1000, 1000	1000, 1000, 700	Obstacle, right turn	3, 100, 0
1000, 1000, 1000, 1000, 1000	1000, 1000, 50		Obstacle, forward	1, 40, 40
1000, 1000, 1000, 1000, 1000	1000, 1000, 1000	Obstacle, right turn	3, 100, 0
1000, 1000, 1000, 1000, 1000	1000, 1000, 600	Obstacle, right turn	3, 100, 0
1000, 1000, 1000, 1000, 1000	1000, 1000, 50		Obstacle, forward	1, 40, 40
50, 50, 50, 50, 50		1000, 1000, 50		Line, left turn	2, 0, 100
100, 1000, 1000, 1000, 1000	1000, 1000, 700	Line, right offset	1, 6, 74
300, 100, 1000, 1000, 1000	1000, 1000, 1000	Line, right offset	1, 14, 66
1000, 400, 50, 1000, 1000	1000, 1000, 1000	Line, right offset	1, 34, 46
1000, 1000, 1000, 1000, 1000	1000, 1000, 1000	Line, right back	4, 100, 0
1000, 500, 200, 1000, 1000	1000, 1000, 1000	Line, right offset	1, 34, 46
1000, 1000, 50, 1000, 1000	1000, 1000, 1000	Line, straight		1, 40, 40
1000, 1000, 1000, 1000, 100	1000, 1000, 1000	Line, left offset	1, 76, 4
1000, 1000, 1000, 100, 300	1000, 1000, 1000	Line, left offset	1, 68, 12
1000, 1000, 50, 400, 1000	1000, 1000, 1000	Line, left offset	1, 48, 32
1000, 1000, 1000, 1000, 1000	1000, 1000, 1000	Line, left back	4, 0, 100
1000, 1000, 200, 500, 1000	1000, 1000, 1000	Line, left offset	1, 48, 32
1000, 1000, 50, 1000, 1000	1000, 1000, 1000	Line, straight		1, 40, 40
1000, 1000, 1000, 1000, 1000	1000, 1000, 1000 	Straight		0, 0, 0


The link to the simulation video:
https://youtu.be/ViHj-tyoxao
