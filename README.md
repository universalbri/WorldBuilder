# WorldBuilder
A Basic Oculus Template for building VR Scenes leveraging a Hollywood Style Approach to Scene Building

With this repository, my main goal was to simplify the 'scene building' of a basic Oculus application
and to Hollywood-dize it, that is, to take the concept of a Movie Production - populate it with "props"
(models/background), set up lights, camera position, and then set the stage fot the actors, then to
progress through a scene - whether that's using fixed position actors moving on a timeline without user
input (movie style) or it's game style where actors are moving on a scene based on user input - hopefully
making it feel like the final product was less spaghetti-ish and more linearly unified for a single coder
to develop than anything  created  with Unreal, Unity, or any other platform supporting VR. 

Now to simplify the coding, I've also approached c++ programming in a highly nonstandard way to reinforce
anyone developing for this to focus primarily on creating self contained C++ objects (contained in a class 
file). While I understand this may be considered bad practice and 'non-Standard' C++', that's ok, Hollywood
is not standard with anything it does which I am trying to reinforce in the mindset of anyone doing
development with this framework. So while traditional C++ splits code into a header file and a C++ file.
To me, the mindset for you, as a develop, it extremely important you retain an everything is self contained
belief in focus while developing - which will absolutley cause some struggle and difficulty - but the end
products we develop from this framework will, by this methodology - hopefully reinforce this mindset. 

This is a Work In Progress, and while I've not devoted much of any time to this project out of simple lack of 
interest to code any longer. I would LOVE to see someone take this and refine it more into what I envision
for it. It will receive periodic updates as I engage in it. 

On a final note. 
I've also created a Speech Processing application which sends windows messages to this application. It's available
as a secondary repository named "Speech Propcessor", developed in C#. All it does is wait for spoken commands and
then issues a message to the World Builder based on the spoken command. 

Enjoy!
