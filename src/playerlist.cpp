#include "playerlist.h"


//Constructor. Need the bet and initial list(betting book) 
PlayerList::PlayerList(int b,list<int> l)
{
    iBet=b;
    iDefaultList=l;
    iList=iDefaultList;
}

//If the list(betting book) contains more than 1 item, sum the first and last items and added the sum to the end. else, add to the bottom of the list 
void PlayerList::AddEndList(void){
    if(iList.size()>1) iList.insert(iList.end(),(iList.front() + iList.back()));
    else               iList.insert(iList.end(),iList.front());
}

//If the list(betting book) contains more than 1 item, remove the first and last items. else, remove the only item.
void PlayerList::RemoveFrontBackList(void){
    if(iList.size()>1){ iList.remove(iList.front());
                        iList.remove(iList.back());}
    else              { iList.remove(iList.front());}
}

//restore default list
void PlayerList::ResetList(void){
    iList = iDefaultList;
}
//returns the player's bet
int PlayerList::Bet(void){
    return iBet;
}
//returns the player's list (betting book)
list<int> PlayerList::List(void){
    return iList;
}
//returns the sum of the items in the list(betting book)
int PlayerList::SumList(void){
    int iSubTot = 0;
    for(int i : iList){
        iSubTot=iSubTot+i;
    }
    return iSubTot;
}

PlayerList::~PlayerList()
{
}