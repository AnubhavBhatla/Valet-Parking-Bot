CS684 Lab-6

Doc Link: https://docs.google.com/document/d/10BnfYsAbfELWxO4Ac2thi2tJ99P2GZYMyy9fc46Z6NI/edit?usp=sharing

Anubhav Bhatla, 200070008
M Shashank Balaji, 200070043
Mudit Goyal, 200070045


Assumptions made:
* No manual intervention of the bot: it is not picked up nor its position adjusted.
* Ambient light settings used for testing are similar to those used for calibrating the sensors.


Strategy Used

Inputs
The sensors used have been connected to Analog and Digital ports on the Alphabot: sensors give high values on White lines and low values on black lines. The sensors are defined as follows:
* ll: Left-most Tracker sensor
* lc: Left-centre Tracker sensor
* cc: Centre Tracker sensor
* rc: Right-centre Tracker sensor
* rr: Right-most Tracker sensor
* proxr: Right-digital sensor
* proxc: Center-digital sensor
* irbr: Right-digital sensor 
* irbl: Left-digital sensor


Outputs
The system outputs are absolute values of left_speed (speed of left wheel), and right_speed (speed of the right wheel), respectively.


PID Logic
The error function used for the PID node is ll + lc - rc - rr. The control value (pid_out) is error/40 + integral/100000 + derivative/100.


State Description
We have split the control into the following states: Stop, Obstacle_follow, Line_follow, Line_following_b, Parking, Reverse, and Back. The Obstacle_follow state has been modified as compared to the previous lab and works for general geometry too . The automaton starts in the Stop state where it stays stationary with left_speed = right_speed = 0 till the centre tracker sensor (cc) goes above 900, i.e. the bot is on the line. Now it moves to the Line_follow state, where we call the pid node, which returns the pid_out value. Here, left_speed = 50 + pid_out, right_speed = 50 - pid_out, capped between 0 and 100. We stay in this state until at least one sensor value is high ( > 500), and then we move to the Back state. In this state, we keep moving backwards with left_speed = right_speed = -98 until we return to the path (cc > 900). It will transition to the Obstacle_follow state as soon as proxc becomes true, and remain there until the centre tracker sensor(cc) goes above 900, i.e., comes back to the white path and then transitions to the Line_following state. The switch from white line following to black line following is when rr > 900 and ll > 900 and cc<500 and transitions to Light_following_b, which has the same PID logic as the Line_following with the a small change of input values as (1000-value). Initialise variable is to figure out when does the parking area begin (assuming that atleast one object is present). Then if irbr is off for a certain amount (counter) then the supervisor will transition to the parking state and will take back right along with certain reverse to properly park.


Example Scenario
When we place the bot in the middle of the white line, it starts up in the Stop state and transitions to the Line_follow once it gets cc > 900. The PID node calculates the control value (pid_out) to set the left and right motor velocities. The bot encounters an object and transitions to Object_follow state, then again transitions to Line_following state. Suppose the bot goes outside the white line path, i.e. none of the tracker sensor values is above 500, we move to the Back state. The motor speeds are set as left_speed = right_speed = -98 until we return to the path (cc > 900). 


The link to the simulation video:
https://youtube.com/shorts/xUpko9JnMtc?feature=share
