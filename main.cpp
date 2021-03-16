#include "player.h"
#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
#include <ctime>

int main(){

    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*WELCOME-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;

    int players_number=1;
    int actions_number=1;
    cout << "How many players are there? please enter an even number. "<<endl;

    while (!(cin >> players_number) || players_number<=1 || players_number>5 ||(players_number%2)!=0)
    {
        cout << "Please enter a valid number";
        cin.clear();
        cin.ignore(132, '\n');
    }

    cout << "How many actions for each player? "<<endl;
    while (!(cin >> actions_number) || actions_number<=1 || actions_number>5)
    {
        cout << "Please enter a valid number";
        cin.clear();
        cin.ignore(132, '\n');
    }
    player players[players_number];
    for (int i = 0; i <players_number ;i++) {
        string name;
        cout<<"Hey Player "<<i+1<<", please enter your name"<<endl;
        fflush(stdin);
        getline(cin,name);
        if(name!=""&&name!=" "){
            player p(name);
            players[i]=p;
        }
    }

    for (int i = 0; i < players_number; i=i+2) {
            players[i].setEnemy(&players[i+1]);
            players[i+1].setEnemy(&players[i]);
    }
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-* MAIN COMPETITON BOARD-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;

    for (int i = 0; i <players_number ; i+=2) {
           cout<<players[i].getName()<<" VS "<<players[i].getEnemy()->getName()<<endl;
    }
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;
    int actions=0;
    while(actions<actions_number){
        for (int i = 0; i < players_number; i++) {
             if(players[i].isDead()){
                  cout<<players[i].getName()<<" ELIMINATED."<<endl;
             }
             else
            players[i].chooseAction();

        }
        actions++;
    }
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-* COMPETITION RESULT"
          "-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    for (int i = 0; i < players_number;i++) {
        cout<<players[i].getName()<<"'s score is "<<players[i].getScore()<<" points."<<endl;
    }








    return 0;
}