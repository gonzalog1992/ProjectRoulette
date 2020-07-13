#pragma once
#include <iostream>

//representation of each bet
#define RED     0
#define BLACK   1
#define LOW     2
#define HIGH    3
#define EVEN    4
#define ODD     5

#define MAXPLAYERS  6           //maximum number of players
#define MAXGAMES    10000       //maximum number of games

#define MAXBET  4000            //maximum bet
#define MINBET  5               //minimum bet

int play(void);
int isWinner(int nro, int bet);


