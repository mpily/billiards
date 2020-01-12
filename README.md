in order to compile  you will need OPENGL you can do that at https://www.opengl.org/
then you will need sfml which you can download here : https://www.sfml-dev.org/download.php
then you compile with the following commands
 g++ -c location.cpp twoDvector.cpp ball.cpp tests.cpp
 g++ location.o twoDvector.o ball.o tests.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 and run with : ./sfml-app
