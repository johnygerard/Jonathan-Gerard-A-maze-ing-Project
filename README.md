Jonathan-Gerard-A-maze-ing-Project
===

Overview: 
---
    The goal of this project is to navigate the vehicle through the maze until you reach the red line. In doing so, you will be faced with monsters that get in your way. Try to make it to the end goal without getting hit. Once you get to the red line you are finished! Great job!

Key Challenges: 
---
    There were many challenges getting this whole program to work. First challenge was trying to understand Enviro and .json format. I was not prepared as much as I liked going into the final project. I wish we had more time/hw earlier on in the semester utilizing .json and Enviro. Second challenge was developing an understanding of the Enviro architecture. I feel like tons of information was dumped into Klavins Enviro repository and it was difficult understanding how to utilize the provided functions. After figuring out how each function worked, I was limitied on time to develop something more complex. Regardless of the due date. I plan to play around more with Enviro to learn/understand each function.

Install and Simulator Instructions:
---
    1. Create your own folder on your desktop to install project 
    2. Open terminal and change your directory to your created folder
    3. Go to project reository link https://github.com/johnygerard/Jonathan-Gerard-A-maze-ing-Project
    4. get the code for the project:
        git clone https://github.com/johnygerard/Jonathan-Gerard-A-maze-ing-Project.git
    5. get the latest code:
        git pull origin master
    6.  cd Jonathan-Gerard-A-maze-ing-Project
    7. docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:alpha bash
    8. ls
    9. confirm you are in the project directory. 
    10. make
    11. esm start
    12. Enviro
    13. Go to the following link to see code simulator:
        http://localhost


How to use project:
---
    Movement is controled using computer keys:
        W: Forward
        A: Pan left
        S: Reverse
        D: Pan right
        space: fire bullets

Sources:
---
    1. https://github.com/klavinslab

