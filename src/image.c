#include "raylib.h" 
#include "Space.h"

static unsigned char player()
{
Image img = LoadImage("predator.png");
ExportImageAsCode(img,"playership.h");
UnloadImage(img);
return(0);
}