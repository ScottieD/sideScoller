

#include <Arduboy2.h>
//#include <Tinyfont.h>

#include "titleSequence.h"
#include "globals.h"


Arduboy2 arduboy;
//Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

const unsigned char PROGMEM peenStraight[] = {0x7c, 0x7c, 0x7c, 0x7c, 0x0c, 0x0c, 0x0c, 0x0c};
const unsigned char PROGMEM peenUP[] = {0x7c, 0x7c, 0x7c, 0x7c, 0x0c, 0x0c, 0x06, 0x06};
const unsigned char PROGMEM peenDown[] = {0x7c, 0x7c, 0x7c, 0x7c, 0x0c, 0x0c, 0x18, 0x18};

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  tS();
  arduboy.setFrameRate(30);
}

void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;
  switch(GAMESTATE)
  {
    case 0:
      mainMenu();
      break;
    case 1:
      mainInfo();
      break;
    case 2:
      mainHelp();
      break;
    case 3:
      mainOptions();
      break;
     case 4:
      mainMenu();
      break;
  }
  arduboy.display();
}

void drawPenis(int x, int y)
{
  //To-do
  //arduboy.drawBitmap(x,y,peen,8,8,WHITE);
}

void drawScore(int Score)
{
  //To-do
  arduboy.setCursor(0,0);
  arduboy.print(Score);
  arduboy.drawLine(4,0,4,128,WHITE);
}

void tS(){
    //todo
    arduboy.clear(); 
    
    for(int i=0;i<64;i++){
      arduboy.drawBitmap(0,i,CthulhuPlays,128,64,WHITE);
      arduboy.display();
      if(i==0)delay(2500);
      arduboy.clear(); 
    }
    
  }
void mainMenu()
{
  arduboy.drawLine(5,6,7,8,WHITE);
  arduboy.clear(); 
  arduboy.setCursor(100,28);
  arduboy.print("Play");
  arduboy.setCursor(100,37);
  arduboy.print("Info");
  arduboy.setCursor(100,46);
  arduboy.print("Help");
  arduboy.setCursor(100,55);
  arduboy.print("Opts"); 
  arduboy.display();
  
  if(arduboy.pressed(DOWN_BUTTON) && buttonHandlerDOWN == 0)
  {
    menuCursor++;
    buttonHandlerDOWN = 1;
    if(menuCursor == 4)
    {
      menuCursor = 0;
    }
  }
  else if(arduboy.pressed(UP_BUTTON) && buttonHandlerUP == 0)
  {
    menuCursor--;
    buttonHandlerUP = 1;
    if(menuCursor <0)
    {
      menuCursor = 3;
    }
  }
  if(arduboy.pressed(A_BUTTON))
  {
    switch(menuCursor)
    {
      case 0:
        GAMESTATE = 1;
        break;
      case 1:
        GAMESTATE = 2;
        break;
      case 2:
        GAMESTATE = 3;
        break;
      case 3:
        GAMESTATE = 4;
        break;
    }
  }
  
  switch(menuCursor)
  {
    case 0:
      arduboy.drawLine(97,28,97,36,WHITE);
      break;
    case 1:
      arduboy.drawLine(97,37,97,45,WHITE);
      break;
    case 2:
      arduboy.drawLine(97,46,97,54,WHITE);
      break;
    case 3:
      arduboy.drawLine(97,55,97,64,WHITE);
      break;
  }
  if(!arduboy.pressed(DOWN_BUTTON))
  {
    buttonHandlerDOWN = 0;
  }
  if(!arduboy.pressed(UP_BUTTON))
  {
    buttonHandlerUP = 0;
  }
}

void mainHelp()
{
  //todo the dog
    arduboy.clear();
  arduboy.print("help");
  arduboy.display();
  if(arduboy.pressed(B_BUTTON))
  {
    GAMESTATE = 0;
    return;
  }
}

void mainInfo(){

  //asdf
    arduboy.clear();
  arduboy.print("info");
  arduboy.display();
  if(arduboy.pressed(B_BUTTON))
  {
    GAMESTATE = 0;
    return;
  }
}

void mainOptions()
{
  //qwerty
  arduboy.clear();
  arduboy.print("opts");
  arduboy.display();
  if(arduboy.pressed(B_BUTTON))
  {
    GAMESTATE = 0;
    return;
  }
}

