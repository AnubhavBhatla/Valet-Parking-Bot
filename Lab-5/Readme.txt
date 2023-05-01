CS684 Lab-5

Anubhav Bhatla, 200070008
M Shashank Balaji, 200070043
Mudit Goyal, 200070045

Google doc: https://docs.google.com/document/d/1FZIt5UC4kNM_kBtXYvW9IfmKeS7QbNVz08LnibdjIUY/edit?usp=sharing
Simulation video: https://www.youtube.com/watch?v=4tapTdxp5ng

Assumptions made:
* No manual intervention of the bot: it is not picked up nor its position adjusted.
* Ambient light settings used for testing are similar to those used for calibrating the sensors.

Strategy Used

Inputs
The sensors used have been connected to Analog ports on the Alphabot:
sensors give high values on White lines and low values on black lines.
The sensors are defined as follows:
* ll: Left-most Tracker sensor
* lc: Left-centre Tracker sensor
* cc: Centre Tracker sensor
* rc: Right-centre Tracker sensor
* rr: Right-most Tracker sensor

Outputs
The system outputs are left_speed (speed of left wheel), and right_speed (speed of the right wheel), and dir (direction). 

PID Logic
The error function used for the PID node is ll + lc - rc - rr. The control value (pid_out) is error/40 + integral/100000 + derivative/100.

State Description
We have split the control into the following states: Stop, Obstacle_follow, Line_follow, and Back.
The Obstacle_follow state has been commented out for this lab. The automaton starts in the Stop state
where it stays stationary with left_speed = right_speed = 0 and dir = 0 till the centre tracker sensor (cc)
goes above 900, i.e. the bot is on the line. Now it moves to the Line_follow state, where we call the pid node,
which returns the pid_out value. Here, left_speed = 50 + pid_out, right_speed = 50 - pid_out,
capped between 0 and 100, and dir = 1. We stay in this state until at least one sensor value
is high ( > 500), and then we move to the Back state. In this state, we keep moving backwards with
left_speed = right_speed = -98 until we return to the path (cc > 900).


Example Scenario
When we place the bot in the middle of the white line, it starts up in the Stop state and transitions
to the Line_follow once it gets cc > 900. The PID node calculates the control value (pid_out) to set
the left and right motor velocities. Suppose the bot goes outside the white line path, i.e. none of
the tracker sensor values is above 500, we move to the Back state. The motor speeds are set as
left_speed = right_speed = -98, dir = 5 until we return to the path (cc > 900).
