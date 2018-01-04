/*     Created by Scott Davis
//     Simple side scroller with an immature twist.
//
*/
#include <Arduboy2.h>
//#include <Tinyfont.h>

#include "titleSequence.h"
#include "globals.h"


Arduboy2 arduboy;
//Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  titleSequence();
  arduboy.setFrameRate(difficulty);
}

//switch for gamestate. 
void loop() {
  // pause render until it's time for the next frame
  arduboy.clear();
  if (!(arduboy.nextFrame()))
    return;
  switch(GAMESTATE){
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
      drawPlayState();
      break;
  }
  arduboy.display();
}
void drawPlayState(){
  drawScore();
  drawPenis();
}

void drawPenis()
{
  int x=pX;
  int y=pY;
  if(arduboy.pressed(UP_BUTTON)){
    if(pY>=7){
        arduboy.drawBitmap(x,y,peenDown,8,8,WHITE);
        pY--;
    }
    else{
      arduboy.drawBitmap(x,y,peenStraight,8,8,WHITE);
    }
  }
  else if(arduboy.pressed(DOWN_BUTTON)){
    if(pY<57){
        arduboy.drawBitmap(x,y,peenUP,8,8,WHITE);
        pY++;
    }
    else{
      arduboy.drawBitmap(x,y,peenStraight,8,8,WHITE);
    }

  }
  else{
    arduboy.drawBitmap(x,y,peenStraight,8,8,WHITE);
  }

}

void drawScore(){
  //To-do add cursor modification to handle larger digit cases. 
  arduboy.setCursor(0,0);
  arduboy.print(points);
  arduboy.drawLine(0,7,128,7,WHITE);
}

//Renders title sequence. 
//add music bit
void titleSequence(){
    //todo
    arduboy.clear(); 
    
    for(int i=0;i<64;i++){
      arduboy.drawBitmap(0,i,CthulhuPlays,128,64,WHITE);
      arduboy.display();
      if(i==0)delay(2500);
      arduboy.clear(); 
    }
    
  }

//Draws menu. Need to add animated bitmaps and audio. 
void mainMenu(){
  arduboy.drawLine(5,6,7,8,WHITE);
  arduboy.clear(); 
  arduboy.setCursor(100,28);
  arduboy.print("Play");
  arduboy.setCursor(98,37);
  arduboy.print("Info");
  arduboy.setCursor(100,46);
  arduboy.print("Help");
  arduboy.setCursor(100,55);
  arduboy.print("Opts"); 
  arduboy.display();
  
  if(arduboy.pressed(DOWN_BUTTON) && buttonHandlerDOWN == 0){
    menuCursor++;
    buttonHandlerDOWN = 1;
    if(menuCursor == 4){
      menuCursor = 0;
    }
  }
  else if(arduboy.pressed(UP_BUTTON) && buttonHandlerUP == 0){
    menuCursor--;
    buttonHandlerUP = 1;
    if(menuCursor <0){
      menuCursor = 3;
    }
  }
  if(arduboy.pressed(A_BUTTON)){
    switch(menuCursor){
      case 0:
        GAMESTATE = 4;
        break;
      case 1:
        GAMESTATE = 1;
        break;
      case 2:
        GAMESTATE = 2;
        break;
      case 3:
        GAMESTATE = 3;
        break;
    }
  }
  
  switch(menuCursor){
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
  if(!arduboy.pressed(DOWN_BUTTON)){
    buttonHandlerDOWN = 0;
  }
  if(!arduboy.pressed(UP_BUTTON)){
    buttonHandlerUP = 0;
  }
}


//Need to add text about functionality and a QR code perhaps
void mainHelp(){
  //todo the dog
    arduboy.clear();
  arduboy.print("help");
  arduboy.display();
  if(arduboy.pressed(B_BUTTON)){
    GAMESTATE = 0;
    return;
  }
}

//Need to add created BY
void mainInfo(){

  //asdf
    arduboy.clear();
  arduboy.print("info");
  arduboy.display();
  if(arduboy.pressed(B_BUTTON)){
    GAMESTATE = 0;
    return;
  }
}

//To-do Bit for music and difficulty(adjust framerate)
void mainOptions(){
  //qwerty
  arduboy.clear();
  arduboy.print("opts");
  arduboy.display();
  if(arduboy.pressed(B_BUTTON)){
    GAMESTATE = 0;
    return;
  }
}
//EOF
