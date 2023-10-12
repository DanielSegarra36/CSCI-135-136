/*
  Author: Daniel Segarra
  Course: 135
  Instructor: Eric Schweitzer
  Assignment: Project 2

  This program finds all ships on the Battleships boards
  in as few turns as possible.
*/
#include <cstdlib>
#include <iostream>
#include "bot.h"
#include "screen.h"
using namespace std;

int ROWS;
int COLS;

/*
  possible values for gameMap:
    0 = empty/not shot at
    1 = HIT
    2 = SUNK
    3 = MISS or spaces around ships
*/
int gameMap[35][35]; // to store the state of locations on the game map

/* Initialization procedure, called when the game starts:

   init (rows, cols, num, screen, log)

   Arguments:
    rows, cols = the boards size
    num        = the number of ships
    screen     = a screen to update your knowledge about the game
    log        = a cout-like output stream
*/
void init(int rows, int cols, int num, Screen &screen, ostream &log)
{
  ROWS = rows;
  COLS = cols;
  // To initialize entire array to 0
  // Global arrays are zero by default but this is just a precaution
  for (int row = 0; row < ROWS; row++)
    for (int col = 0; col < COLS; col++)
      gameMap[row][col] = 0;
  log << "Start." << endl;
}

/* The procedure handling each turn of the game:

   next_turn(sml, lrg, num, gun, screen, log)

   Arguments:
    sml, lrg = the sizes of the smallest and the largest ships that are currently alive
    num      = the number of ships that are currently alive
    gun      = a gun.
               Call gun.shoot(row, col) to shoot:
                  Can be shot only once per turn.
                  Returns MISS, HIT, HIT_N_SUNK, ALREADY_HIT, or ALREADY_SHOT.
    screen   = a screen to update your knowledge about the game
    log      = a cout-like output stream
*/
void next_turn(int sml, int lrg, int num, Gun &gun, Screen &screen, ostream &log)
{
  result res;
  int x = rand()%ROWS;
  int y = rand()%COLS;
  if (gameMap[x][y]==0) // if spot untouched, shoot it
    {
      res = gun.shoot(x, y);
      if (res == MISS){
        screen.mark(x, y, 'M', BLUE);
        gameMap[x][y] = 3;
      }
      else
        if (res == HIT){
          screen.mark(x, y, 'x', GREEN);
          gameMap[x][y] = 1;
        }
      else
        if (res == HIT_N_SUNK){
          screen.mark(x, y, '$', RED);
          gameMap[x][y] = 2;
        }
    }

  // if spot HIT(1) or SUNK(2) and not already a missed shot(3)
  else if (((gameMap[x][y]==1) || (gameMap[x][y]==2)) && (gameMap[x][y]!=3))
  {


    // check the row below
    if((x+1<ROWS) && (gameMap[x+1][y]==0) ) // if not outside map and untouched proceed and shoot
      {
        x++;
        res = gun.shoot(x,y);
        if (res == MISS){
          screen.mark(x, y, 'M', BLUE);
          gameMap[x][y] = 3;
        }
        else
          if (res == HIT){
            screen.mark(x, y, 'x', GREEN);
            gameMap[x][y] = 1; // current spot
            if(y-1>=0)gameMap[x][y-1] = 3; // column to left no longer shootable
            if(y+1<COLS)gameMap[x][y+1] = 3; // column to right no longer shootable
            if(y-1>=0)gameMap[x-1][y-1] = 3; // column to left and one above no longer shootable
            if(y+1<COLS)gameMap[x-1][y+1] = 3; // column to right and one above no longer shootable
          }
        else
          if (res == HIT_N_SUNK){
            screen.mark(x, y, '$', RED);
            gameMap[x][y] = 2;
            if(x+1<ROWS)gameMap[x+1][y] = 3;
            if(y-1>=0)gameMap[x][y-1] = 3; // column to left no longer shootable
            if(y+1<COLS)gameMap[x][y+1] = 3; // column to right no longer shootable
            if(y-1>=0)gameMap[x-1][y-1] = 3; // column to left and one above no longer shootable
            if(y+1<COLS)gameMap[x-1][y+1] = 3; // column to right and one above no longer shootable
          }
      }

    // check row above
    else if((x-1>=0)&&(gameMap[x-1][y]==0)) // if not outside map and untouched proceed and shoot
      {
        x--;
        res = gun.shoot(x,y);
        if (res == MISS){
          screen.mark(x, y, 'M', BLUE);
          gameMap[x][y] = 3;
        }
        else
          if (res == HIT){
            screen.mark(x, y, 'x', GREEN);
            gameMap[x][y] = 1;
            if (y+1<COLS)gameMap[x][y+1] = 3; // column to the right is no longer shootable
            if (y-1>=0)gameMap[x][y-1] = 3; // column to the left is no longer shootable
            if (y+1<COLS)gameMap[x+1][y+1] = 3; // column to the right and one below is no longer shootable
            if (y-1>=0)gameMap[x+1][y-1] = 3; // column to the left and one below is no longer shootable
          }
        else
          if (res == HIT_N_SUNK){
            screen.mark(x, y, '$', RED);
            gameMap[x][y] = 2;
            if (x-1>=0)gameMap[x-1][y] = 3; // spot above sunk
            if (y+1<COLS)gameMap[x][y+1] = 3; // column to the right is no longer shootable
            if (y-1>=0)gameMap[x][y-1] = 3; // column to the left is no longer shootable
            if (y+1<COLS)gameMap[x+1][y+1] = 3; // column to the right and one below is no longer shootable
            if (y-1>=0)gameMap[x+1][y-1] = 3; // column to the left and one below is no longer shootable
          }
      }


    // check column to the right
    else if((y+1<COLS)&&(gameMap[x][y+1]==0)) // if not outside map and untouched proceed and shoot
      {
        y++;
        res = gun.shoot(x,y);
        if (res == MISS){
          screen.mark(x, y, 'M', BLUE);
          gameMap[x][y] = 3;
        }
        else
          if (res == HIT){
            screen.mark(x, y, 'x', GREEN);
            gameMap[x][y] = 1;
            if(x-1>=0)gameMap[x-1][y] = 3; // spot above no longer shootable
            if(x+1<ROWS)gameMap[x+1][y] = 3;  // spot below no longer shootable
            if(x-1>=0)gameMap[x-1][y-1] = 3;  // spot above and to the left no longer shootable
            if(x+1<ROWS)gameMap[x+1][y-1] = 3;  // spot below and to the left no longer shootable
          }
        else
          if (res == HIT_N_SUNK){
            screen.mark(x, y, '$', RED);
            gameMap[x][y] = 2;
            if(y+1<COLS)gameMap[x][y+1] = 3; // spot to the right no onger shootable
            if(x-1>=0)gameMap[x-1][y] = 3; // spot above no longer shootable
            if(x+1<ROWS)gameMap[x+1][y] = 3;  // spot below no longer shootable
            if(x-1>=0)gameMap[x-1][y-1] = 3;  // spot above and to the left no longer shootable
            if(x+1<ROWS)gameMap[x+1][y-1] = 3;  // spot below and to the left no longer shootable
          }
      }


    // check column to the left
    else if((y-1>=0)&&(gameMap[x][y-1]==0)) // if not outside map and untouched proceed and shoot
      {
        y--;
        res = gun.shoot(x,y);
        // mark coordinate accordingly
        if (res == MISS){
          screen.mark(x, y, 'M', BLUE);
          gameMap[x][y] = 3;
        }
        else
          if (res == HIT){
            screen.mark(x, y, 'x', GREEN);
            gameMap[x][y] = 1;
            if(x-1>=0) gameMap[x-1][y] = 3; // spot above no longer shootable
            if(x+1<ROWS) gameMap[x+1][y] = 3; // spot below no longer shootable
            if(x-1>=0) gameMap[x-1][y+1] = 3; // spot above and to the right no longer shootable
            if(x+1<ROWS) gameMap[x+1][y+1] = 3; // spot below and to the right no longer shootable
          }
        else
          if (res == HIT_N_SUNK){
            screen.mark(x, y, '$', RED);
            gameMap[x][y] = 2;
            if(y-1>=0) gameMap[x][y-1] = 3; // spot to the left no longer shootable
            if(x-1>=0) gameMap[x-1][y] = 3; // spot above no longer shootable
            if(x+1<ROWS) gameMap[x+1][y] = 3; // spot below no longer shootable
            if(x-1>=0) gameMap[x-1][y+1] = 3; // spot above and to the right no longer shootable
            if(x+1<ROWS) gameMap[x+1][y+1] = 3; // spot below and to the right no longer shootable
          }
      }
  }


  else{
    // keep generating coordinates until
    // it is a section that has not been shot at all
    while((gameMap[x][y]==1) || (gameMap[x][y]==2) || (gameMap[x][y]==3)){
      x = rand()%ROWS;
      y = rand()%COLS;
    }
    // mark coordinate accordingly
    res = gun.shoot(x,y);
    if (res == MISS){
      screen.mark(x, y, 'M', BLUE);
      gameMap[x][y] = 3;
    }
    else
      if (res == HIT){
        screen.mark(x, y, 'x', GREEN);
        gameMap[x][y] = 1;
      }
    else
      if (res == HIT_N_SUNK){
        screen.mark(x, y, '$', RED);
        gameMap[x][y] = 2;
      }
  }

  log << "Smallest: " << sml << " Largest: " << lrg << ". ";
  log << "Shoot at " << x << " " << y << ".\n";
}
