# ArduinoUno_LCD-Firmware--LabView-

What This Project Does --
  
  This project shows how LabView's LINX library can be used to develop firmware for specific hardware to be controlled
  by the custom command functions in LabView's LINX library. This is useful when LabView does not already have hard coded
  functions in its development environment, meaning there are no current/updated libraries in the VI package manager. In my case, I
  was using LabView 2017 and the LINX library to interface with an Ultrasonic sensor. The LINX library comes with hard coded VI functions
  for many of the ultrasonic sensors that work with Arduino microcontrollers, however this version of LabView did not have any for the 
  I2C serial adapter my project partner and I wanted to use for the (16x2) LCD display, which is when I began to dig deeper into the custom command
  features of the LINX library.
  
  This project was written in Arduino's C++ language. The original code and video I watched on someone who had used a similar display
  with the custom commands were found here...
  
  https://www.youtube.com/watch?v=treDpbScN0I
  
  Search the top comments for the link to the original code and subVI. 

Why This Project Is Useful --
  
  This project is useful for anyone interested in learning how the custom commands work with the LINX library. It's a fun project 
  to see how modular MakerHub has made the custom commands, from beginning to not knowing really how to make something work in LabView 
  with text based language, and then building up that text code to be tested in a graphical programming environment. 
  

How You Can Get Started With This Project --
  
  I would recommend first watching S.Stock's YouTube link I posted under "What This Project Does." That is where I spent a lot of time just
  trying to understand how this would all come together and work. Then I would recommend studying his Arduino script and LabView SubVI. Then 
  you're more than welcome to look at mine and comapare the two. I have posted my code in this repository. I have also posted a subVI that went 
  into a bigger VI program I used for a school project. 
  
Other Helpful Links --

  Here are some other links that helped me a whole lot throughout this project...
  
  Character I2C LCD with Arduino Tutorial (8 Examples)
  https://www.makerguides.com/character-i2c-lcd-arduino-tutorial/
  
  How I2C Communication Works and How To Use It with Arduino
  https://howtomechatronics.com/tutorials/arduino/how-i2c-communication-works-and-how-to-use-it-with-arduino/
  
  
  
Who Maintains This Project --
  
  For this specific code I am the only contributer and editor, but please feel free to send suggestions and comments.
  If you want to collaborate send me an email at the address on my profile page.
