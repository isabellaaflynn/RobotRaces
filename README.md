# Code for EID 103 Challenge 2: Knocking Over a Cup and Retrieving a Bottle Cap
NOTE: During the competition, we had to use slightly lower voltage motors because our 5V DC Motors Broke :((( The code here, however, utilizes the full power of the DC Motor. So even though our robot was pretty slow, it wasnt because of the code, it was because of our motors!!! 
Also, Cooper Union's screw drivers are insanely dull and we really struggled to drill a hole into the plastic for the hook mechanism, so they are taped on. There is no other reason for using tape, although it is pretty aesthetically appealing!!! Otherwise, we would have attached the hok to the robot using screws and the holes in the chasis.

# Design for knocking over cup:
For our knocking over mechanism, we utilized a wooden dowel attached to a servo motor. The dowel was attached to a 2 inch radius wooden circle at a slightly off center position. Our reasoning for using this dimension was merely that out of our tests of different positions, this was the most effective positioning. We also have a stick taped to the other side of the hook to prevent the cup from sliding. The idea was that we would catch the cup between the two dowels and only move the top dowel, thus flipping the cup over. 
![image](https://user-images.githubusercontent.com/90297435/157105805-14c83657-4ab9-4b5e-94ad-c1490214c70d.png)

# Design for cap retrieval: 
We used the exact same method as we did for the previous challenge, but with an improved design based on the downfalls of the old design. Basically, because the robot is at a slight angle downward, our previous hook had a space in the back where the cap could fall through. We resolved this error and the new hook now sits at an angle that allows its entirety to be on the ground. We also made the hooks mouth smaller because we noticed last challenge that it tended to slip out if the robot made a sudden movement, which happened a lot with out joystick. 
![image](https://user-images.githubusercontent.com/90297435/157106299-2ed8a6fc-1c5c-4424-827c-70475e98866e.png)

# Explanation of Software/ Code:
Because our joystick method was far from ideal, we decided to make the move to bluetooth as fast as possible. In order to establish a connection between the arduino and the phone, we used an HM 10 bluetooth chip. Check it out here: https://www.amazon.com/DSD-TECH-Bluetooth-iBeacon-Arduino/dp/B06WGZB2N4?ref_=ast_sto_dp
![image](https://user-images.githubusercontent.com/90297435/157107163-93bfca68-71d4-455b-b1d4-cbe2eebb3030.png)

However, the DSD TECH accompanying app was difficult to work with, so we utilized a different app with a gaming pad UI. Check it out here: https://thestempedia.com/docs/dabble/getting-started-with-dabble/
The library that came with this app was also surprisingly simple, with functions like ifUpPressed(). This made coding the app's joystick incredibly simple.

# LOOK AT HER IN ACTION!
https://user-images.githubusercontent.com/90297435/157107538-3af6256f-6cb9-4b17-ae92-3e9667ec1cbc.mov

