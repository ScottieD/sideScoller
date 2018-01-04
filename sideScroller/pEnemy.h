#include <Arduboy2.h>

int yLocation = 128;
int xLocation = 32;

class pEnemy
{
  void setXLoc(int x){
    
  }
  void setYLoc(int y){
    
  }
  void getXLoc(){
    return xLocation;
  }
  void getYLoc(){
    return yLocation;
  }
  void drawSelf(){
    arduboy.drawBitmap(yLocation,XLocation,peenemy,8,8,WHITE);
  }
}

