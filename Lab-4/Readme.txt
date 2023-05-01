CS684 Lab-4

Anubhav Bhatla, 200070008
M Shashank Balaji, 200070043
Mudit Goyal, 200070045

Simulation video: https://www.youtube.com/watch?v=5Vaz8kC9bq0
Google doc: https://docs.google.com/document/d/1ihxYw5WJ1jLx42hVDeHHrbWklbwOgqFhdPkGeU3lL5E/edit?usp=sharing


Assumptions made:
* No manual intervention of the bot: it is not picked up nor its position adjusted.
* The object is rectangular with sharp edges
* Ambient light settings used for testing are similar to those used for calibrating the sensors.


Strategy used

Inputs
The sensors used have been connected to Digital ports on the Alphabot: a logic high means the sensor 
is obstructed by the obstacle, logic low means otherwise. The sensors are defined as follows:
* proxc: Center Proximity Sensor
* proxl: Left Proximity Sensor

Outputs
The outputs of the system are left_speed (speed of left wheel), and right_speed (speed of the right wheel). 


State description

We have split the control into the following states: Start, Right_turn, Forward, and Left_turn.
The automaton starts in the Start state where it keeps going straight with left_speed = right_speed = 40
till the centre proximity sensor (proxc) goes high, i.e. the bot is obstructed by an object.
Now it moves to the Right_turn state where we set left_speed = 43, right_speed = -43.
We stay in this state until the counter time_step exceeds 13, after which we move to the Forward state.
In this state we keep moving forward with left_speed = right_speed = 40 and transition to the Left_turn state
if the proxy and proxc sensors both go low or to the Right_turn state if we have completed obstacle following
and want to get back on the path (indicated by the forwardl2 boolean). The Left_turn state sets left_speed = -38,
right_speed = 36 and transitions to the Forward state when the time_step counter value exceeds 4. 


Example Scenario

When we place the bot at a distance from the obstacle, it starts up in the Start state and moves forward till
it gets close enough to the obstacle and proxy turns high. The boolean start is set to true and we move to the
Right_turn state where we keep  left_speed = 43, right_speed = -43 until the counter time_step exceeds 13.
The boolean forwardl1 is calculated to be true, so we move to the Forward state. In this state we keep moving
forward with left_speed = right_speed = 40 and transition to the Left_turn state if the proxy and proxc sensors both go low,
i.e., the bot overshoots and now needs to take a Left_turn.  The Left_turn state sets left_speed = -38, right_speed = 36
and transitions to the Forward state when the time_step counter value exceeds 4. It also sets the boolean left as true and
forwardl2 as false. Now, again, the bot keeps going straight in the Forward state until both proximity sensor values go low
and we transition to the Left_turn state. It also recalculates forwardl1 to be false. We stay in the Left_turn state till
the counter exceeds 4 and transition back to the Forward state. The boolean forwardl2 is recalculated to be true.
Back in the Forward state, we keep going straight till the dist counter becomes negative, after which we go
to the Right_turn, where the final right turn is taken to get back on the path.
