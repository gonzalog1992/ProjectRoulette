#include <iostream>
#include <stdlib.h>
#include <list>

#include "function.h"
#include "playerlist.h"

using namespace std;


//------------------------------------------------------------ 
// Main function
// Objective            It is the entry point to the program
// Input parameter      none
// Output parameter     none
//------------------------------------------------------------
int main(){

    //----- Declaration of variables of interest-----

    int iNro=0;                                                                                     //Objetive: store the simulated roulette number                              
    int iBalance[MAXPLAYERS] = {NULL};                                                              //Objetive: store each player's temporary balance
    int iTotal=0 ;                                                                                  //Objetive: store the total balance of all players at the end of the game
    char PlayerBets[MAXPLAYERS][6] = {{"RED  "},{"BLACK"},{"LOW  "},{"HIGH "},{"EVEN "},{"ODD  "}}; //Symbolic name of each player
    list<int> iInitial={1,2,3,4};                                                                   //Starting value of the betting book

    PlayerList* pl[MAXPLAYERS] = {                                                                  //Objetive:create the six players. only interested in the betting book of each player  
        new PlayerList(RED,iInitial),
        new PlayerList(BLACK,iInitial),
        new PlayerList(LOW,iInitial),
        new PlayerList(HIGH,iInitial),
        new PlayerList(EVEN,iInitial),
        new PlayerList(ODD,iInitial)
    };
    srand(time(0));
    

    //main Loop 
    //Objetive: Simulation of the number of roulette spins (MAXGAMES = 10000)
    for(int i =0 ; i<MAXGAMES ; i++) {
        iNro = play();                              //random number of each set                                                       
        cout<< endl << endl << "(Game "<< (i+1) << ") | Nro: " << iNro ;
        for(int n =0 ; n<6 ; n++) {                 //For each player, process the bet according to the random number. 
            cout<< endl<< PlayerBets[n] << '\t';         
            if(iNro){                               //If the random number is '0', everyone loses 
                if(isWinner(iNro,pl[n]->Bet())){    //
                    pl[n]->AddEndList();            //if WIN, add to the end of the list as appropriate
                    cout<< '\t'<<"WIN"<< '\t';   
                }else
                {
                    pl[n]->RemoveFrontBackList();   //if LOSE, remove the numbers of the list as appropriate
                    cout<< '\t'<<"LOSE"<< '\t'; 
                }
            }else{
                pl[n]->RemoveFrontBackList();       //If the random number is '0', everyone loses. Remove the numbers of the list as appropriate
                cout<< '\t'<<"LOSE"<< '\t'; 
            }


            //if it exceeds the maximum bet, or there is a number less than the minimum, 
            //the sum of the numbers must be stored in the betting book and restarted (1 - 2 - 3 - 4)
            if(pl[n]->SumList() < MINBET || (pl[n]->List().front() + pl[n]->List().back()) > MAXBET){
                iBalance[n] = iBalance[n] + pl[n]->SumList();
                pl[n]->ResetList();
                iBalance[n] = iBalance[n] - pl[n]->SumList(); //Subtract the sum of numbers from the betting book (loan).
            } 
            cout<<"Temporary balance: "<< iBalance[n] <<" ---> New list: ";  
            for(int k : pl[n]->List()) cout<< k <<",";
        }
    }

    //finally, print out the final results on screen
    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    for (int n = 0; n < MAXPLAYERS; n++)
    {
        iBalance[n] = iBalance[n] + pl[n]->SumList();
        cout<< endl << "Balance of the Player who bet on "<< PlayerBets[n] << " : "<< iBalance[n]<<endl;
        iTotal = iTotal + iBalance[n];
        pl[n]->~PlayerList();
    }
    cout<<"Total Balance: "<< iTotal <<endl;
 
    return 0;
    
}



