/****************************************************************************************  
**  This is example LINX firmware for use with the Arduino Uno with the serial 
**  interface enabled.
**
**  For more information see:           www.labviewmakerhub.com/linx
**  For support visit the forums at:    www.labviewmakerhub.com/forums/linx
**  
**  Written By Sam Kristoff
**
**  BSD2 License.
*  
*  Script edited by George J. Suarez. This code allows users to implement
*  an I2C serial adapter and 16x2 LCD display using LabView and the LINX custom VI 
*  command function. It enables a user to output string data onto the LCD screen on lines 
*  1 & 2 of the screen. It also can take user input from the keyboard and output those 
*  characters onto the screen. This can be done using similar LabView functions that are shown 
*  through the link on the last line of the blocked out comment head. Something worth noting
*  is that in order to use this with Arduino successfully, the user must flash this IDE code to the board,  
*  and then flash the board with the LINX firmware using the LabView software. 
*  
*  Original script by S.Stock / Youtube Channel: www.youtube.com/c/sstock
****************************************************************************************/

//Include All Peripheral Libraries Used By LINX

#include <Wire.h>
#include <LiquidCrystal_I2C.h>



//Include Device Specific Header From Sketch>>Import Library (In This Case LinxChipkitMax32.h)
//Also Include Desired LINX Listener From Sketch>>Import Library (In This Case LinxSerialListener.h)
#include <LinxArduinoUno.h>
#include <LinxSerialListener.h>

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); //Changed to (.., 16, 2) for 16X2 LCD
//Create A Pointer To The LINX Device Object We Instantiate In Setup()
LinxArduinoUno* LinxDevice;

int LCD_L0();
int LCD_L1();

//Initialize LINX Device And Listener
void setup()
{
  lcd.init(); //initialize LCD
  lcd.backlight(); //Turn on LCD backlight

   LinxSerialConnection.AttachCustomCommand(0, LCD_L0);     //Custom command 0
   LinxSerialConnection.AttachCustomCommand(1, LCD_L1);     //Custom command 1
  
  
  LinxDevice = new LinxArduinoUno();  //LINX device => Arduino UNO
  
  //The LINXT Listener Is Pre Instantiated, Call Start And Pass A Pointer To The 
  //LINX Device And The UART Channel To Listen On
  LinxSerialConnection.Start(LinxDevice, 0);  
}
/****************************************************************************************/
void loop()
{
  //Listen For New Packets From LabVIEW
  LinxSerialConnection.CheckForCommands();
}

  /**************************************Custom command 0******************************************/
int LCD_L0(unsigned char numInputBytes, unsigned char* input, unsigned char* numResponseBytes, unsigned char* response)

//parameters of custom cmds are defined in utility folder's 
//LinxListener.h file.

{
    
    lcd.setCursor (0,0);
    lcd.print("                    ");                          //Clear Line 0 (empty space)
    lcd.setCursor (0,0);
for(int i = 0; i < (numInputBytes); i++)
  {
    input[i] = byte(input[i]);
    lcd.write(input[i]);
    response[i]=input[i];
  }
    *numResponseBytes = numInputBytes;                          //Sends bytes in return (used for error handling).
    
 return 0;
}
  /**************************************Custom command 1******************************************/

int LCD_L1(unsigned char numInputBytes, unsigned char* input, unsigned char* numResponseBytes, unsigned char* response)
{
   
    lcd.setCursor (0,1);
    lcd.print("                    ");                          //Clear Line 1 (empty space)
    lcd.setCursor (0,1);
for(int i = 0; i < (numInputBytes); i++)
  {
    input[i] = byte(input[i]);
    lcd.write(input[i]);
    response[i]=input[i];
  }
    *numResponseBytes = numInputBytes;                          //Sends bytes in return (used for error handling).
    
 return 0;
}