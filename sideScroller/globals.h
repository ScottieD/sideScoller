//int of gamestate, 0 → 7
int GAMESTATE = 0;

//Constants for bitmaps 

//antagonist ani
const unsigned char PROGMEM peenStraight[] = {0x7c, 0x7c, 0x7c, 0x7c, 0x0c, 0x0c, 0x0c, 0x0c};
const unsigned char PROGMEM peenUP[] = {0x7c, 0x7c, 0x7c, 0x7c, 0x0c, 0x0c, 0x06, 0x06};
const unsigned char PROGMEM peenDown[] = {0x7c, 0x7c, 0x7c, 0x7c, 0x0c, 0x0c, 0x18, 0x18};

//consts for antagonists(inverted pro)
const unsigned char PROGMEM peenemy[] = {0x01, 0x01, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00};
//end bitmaps

//game vars
int pY = 32;
int pX = 4;
//int health = 100;
int difficulty = 40; //framerate
//int music = 0;
int points = 0;
int menuCursor = 0;
int buttonHandlerDOWN = 0;
int buttonHandlerUP = 0;
