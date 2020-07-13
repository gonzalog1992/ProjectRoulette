#pragma once
#include <list>

using namespace std;


class PlayerList
{
public:
    PlayerList(int b,list<int> l);
    ~PlayerList();
    void AddEndList(void);
    void RemoveFrontBackList(void);
    void ResetList(void);
    list<int> List(void);
    int Bet(void);
    int SumList(void);
private:
    int iBet;
    list<int> iList;
    list<int> iDefaultList;
};

