#include "function.h"


//------------------------------------------------------------ 
// play function
// Objective            Simulation of random number of each game
// Input parameter      none
// Output parameter     random number
//------------------------------------------------------------
int play(void){
    
    return rand()%37;
}


//------------------------------------------------------------ 
// isWinner function
// Objective            Decide whether the player wins or loses the bet 
//                      according to the random number of each game
// Input parameter      random number of the game, player's bet (RED/BLACK/LOW/HIGH/EVEN/ODD)
// Output parameter     1/0
//------------------------------------------------------------
int isWinner(int nro, int bet){
    int color[18]={1, 3, 5, 7, 9, 12,14, 16, 18, 19, 21, 23,25, 27, 30, 32, 34, 36};
    int win[3];


    //Win RED or BLACK
    for(int j =0 ;j<18;j++) {
        if(nro == color[j]){
            win[0] = RED;
            break;
        }
        win[0] = BLACK;
    }
    //Win LOW or HIGH
    if(nro<19) win[1] = LOW;
    else       win[1] = HIGH;
    //Win ODD or EVEN
    if(nro%2)  win[2] = ODD;
    else       win[2] = EVEN;

    //If the bet matches a winning bet
    if((bet == win[0])||(bet == win[1])||(bet == win[2]))   return 1;  
    else                                                    return 0;
    
}


