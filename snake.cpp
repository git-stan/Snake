#include "snake.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;

char coordinates[10][25];
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection edir;
int headposition_x  = 5, headposition_y  = 12, fruit_x = 1+(rand() % 7), fruit_y = 1+(rand() % 22), score = 0;
bool GameOver = false;
int tailPosition_x[100], tailPosition_y[100];
int nTail = 0;

snake::snake()
{
    //ctor
}
void snake::print_field()
{
    cout << "Score: " << score << endl;

    for(int x = 0; x < 10;x++){
        for(int y = 0; y < 25;y++){
            if(x==0 || x == 9){

                coordinates[x][y] = '#';

            }else{
                coordinates[x][y] = ' ';
                coordinates[x][0] = '#';
                coordinates[x][24]= '#';
                for(int k = 0; k < nTail; k++){

                    coordinates[tailPosition_x[k]][tailPosition_y[k]] = '+' ;
                }
                if(x == headposition_x && y == headposition_y ){
                    coordinates[x][y] = '@';
                }else if(x == fruit_x && y == fruit_y){
                    coordinates[x][y] = '$';
                }
            }
            cout << coordinates[x][y];
            if(headposition_x == tailPosition_x[y] && headposition_y == tailPosition_y[y]){
                GameOver = true;
            }
        }
        cout << endl;
    }
}
bool snake::input(){
    if(_kbhit()){
        switch(_getch()){

        case 'w':
                    edir = UP;
                    break;
        case 's':
                    edir = DOWN;
                    break;
        case 'a':
                    edir = LEFT;
                    break;
        case 'd':
                    edir = RIGHT;
                    break;
        case 'x':
                    GameOver = true;
                    return GameOver;
                    break;
        }
    }
    return GameOver;
}
bool snake::logic(){
    // prevTail_x/y = das erste segment hinter dem kopf
    int prevTail_x = headposition_x;
    int prevTail_y = headposition_y;
    int prevTail2_x, prevTail2_y;


    for(int j = 0; j < nTail; j++){
            prevTail2_x = tailPosition_x[j];
            prevTail2_y = tailPosition_y[j];
            tailPosition_x[j]  = prevTail_x;
            tailPosition_y[j]  = prevTail_y;
            prevTail_x  = prevTail2_x;
            prevTail_y = prevTail2_y;
    }
        switch(edir){

        case UP:
                    headposition_x--;
                    break;
        case DOWN:
                    headposition_x++;
                    break;
        case LEFT:
                    headposition_y--;
                    break;
        case RIGHT:
                    headposition_y++;
                    break;
        }
        if(headposition_x == 9 || headposition_y == 0 || headposition_x == 0 || headposition_y == 24){

            GameOver = true;

        }else if(headposition_x == fruit_x && headposition_y == fruit_y){

            score += 10;
            srand(time(0));
            fruit_x = 1+(rand() % 7), fruit_y = 1+(rand() % 22);
            nTail++;
        }
        return GameOver;
}
