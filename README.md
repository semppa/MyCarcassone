# MyCarcassone
Welcome to my repository! Here you can find my little project, where I made classic board game Carcassone using C++ with QT framework. This repo contains the source code for those who are interested and also build of the current latest version, where you can find executable file.

The reason why I made this game was to teach myself about programming more. I had just started in university and there introduced to programming for the very first time. On vacations I noticed I had some time on my hands and one night decided that I wanted to teach myself to write an actual program people can enjoy. As I like playing games, this came into my mind first with having simple controls. Making this game was long journey with alot of teaching myself networking/GUI-events/pointers in general etc. With covid enraging, I had more time so I pushed myself to finish this project.

The future of this repo is probably not going to get much updates. I'm going to do some bugfixes now and there and draw little bit prettier tiles, but there probably wont be any extensions or extra features.

**NOTE THAT THIS IS ONLY A HOBBY/CV-PROJECT TO TEACH MYSELF ABOUT PROGRAMMING. IT IS IN NO WAY A COMPLETED GAME. IF YOU WANT A PROPER GAME OF CARCASSONE, THERE IS ONE AT EPICGAMES FOR MERE 10€.**

## I don't care, I just want to play
To play the game, follow the following steps

- Download the files as zip by clicking the green code -> download zip
- Extract the "build" directory to somewhere in your pc
- Open "carcassone.exe"
- Have fun!

Some controls:
- Scrolling mousewheel will zoom in and out. If playing with no mouse (for example with laptop), Up and Down -keys can be used.
- Moving screen can be done by either holding middle mouse button or right mouse button
- Left and Right keys will turn the current tile.

## Instructions
The program works by you either being a server or being a client and connecting to some server. The underlying networking is done with QT (https://www.qt.io/product/development-tools) networking sockets using TCP-protocall. When creting/joinining a server, a port 13370 is used (this is hard coded). To have people succesfully join your server, you need to do some portforwarding (unless you are on a LAN). Then give your public IP to recepiant, and they should be able to join. If you are on LAN, you can use your local ip, which you get by calling "cmd" on windows and typing "ipconfig". Then your ip is "IPv4 Adress".

## Known issues
- When creating or joining server, the icon at taskbar disappears
