#include "snake.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void clearscreen();
void who();

int main()
{
    int answ;
    cout << "\nWelcome to snake" << endl
         << "start [1] and [2]'who?'" << endl;
    cin  >> answ;

    if(answ == 2){
        who();
        cout << endl;
    }

    bool GameOver = false;
    system("cls");
     while(GameOver != true){
        clearscreen();
        snake pg;
        pg.print_field();
        GameOver = pg.input();
        GameOver = pg.logic();
        _sleep(100);
    }
}
void clearscreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
void who(){
        cout<< "****************" << endl
            << "* Made by stan *" << endl
            << "****************" << endl;
            system("PAUSE");
}
