#include "player.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include <regex>
#include <cstdlib>
#include <ctime>

int main(){
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*WELCOME-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;

    int players_number=1;
    int actions_number=1;
    cout << "How many players are there? please enter an even number lower than or equal to 6: "<<endl;

    while (!(cin >> players_number) || players_number<=1 || players_number>6 ||(players_number%2)!=0)
    {
        cout << "Please enter a valid even number lower than or eqaul to 4: "<<endl;
        cin.clear();
        cin.ignore(132, '\n');
    }

    cout << "How many actions for each player? "<<endl;
    while (!(cin >> actions_number) || actions_number<=1 || actions_number>5)
    {
        cout << "Please enter a valid number:";
        cin.clear();
        cin.ignore(132, '\n');
    }
    player players[players_number];
    for (int i = 0; i <players_number ;i++) {
        string name;
        cout<<"Hey Player "<<i+1<<", please enter your name:"<<endl;
        fflush(stdin);
        getline(cin,name);
        if(name!=""&&name!=" "){
            player p(name);
            players[i]=p;
        }
    }

    cout << "Which mode do you prefer? "<<endl;
    cout << "1- SOLO MODE - FIGHT FOR YOUR LIFE! "<<endl;
    cout << "2- TEAMS MODE - THINK WITH YOUR ALLY! "<<endl;
    int choice;
    cin>>choice;
    switch (choice) {
        case 1:{
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
                cout<<players[i].getName()<<" V.S "<<players[i].getEnemy()->getName()<<endl;
            }
            cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
            cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
            cout<<endl;
            int actions=0;
            while(actions<actions_number){
                for (int i = 0; i < players_number; i++) {
                    if(players[i].isDead()){
                        cout<<players[i].getName()<<" IS ELIMINATED."<<endl;
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
            break;
        }
        case 2:{

            for (int i = 0; i <players_number/2 ; ++i) {
                players[i]=players[i]+players[i+1];
            }
            for (int j = players_number/2; j <players_number ; ++j) {
                players[j]=players[j]+players[j+1];


            }
            player team_A=players[0];
            player team_B=players[players_number/2];
            team_A.setEnemy(&team_B);
            team_B.setEnemy(&team_A);
            bool winnerExists= false;
            for (int i = 0; i < actions_number*2; ++i) {
                if(i%2==0){
                    if(team_A.isDead()){
                        cout<<team_B.getName()<<" wins."<<endl;
                        winnerExists= true;
                        break;
                    }
                    else
                        team_B.chooseAction();
                }
                else{
                    if(team_B.isDead()){
                        cout<<team_A.getName()<<" wins."<<endl;
                        winnerExists= true;
                        break;
                    }
                    else team_A.chooseAction();
                }
            }
            if(winnerExists==false)team_A.isWinner();
            break;
        }
        default:
            cout<<"Invalid choice."<<endl;

    }






    return 0;
}