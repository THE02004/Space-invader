#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Space.h"
#include "raylib.h"

void Spaceship(bool **current, int cols, int rows)
{
    Vector2 pos = GetMousePosition();
    float x = pos.x;
    float y = pos.y;
    //Image img = LoadImage("predator.png");
    Texture2D img = LoadTexture("predator.png"); 
    current[(int)x][(int)y] = true;
    DrawTexture(img,(int)x,(int)y,BLACK);
    //UnloadImage(img);
}