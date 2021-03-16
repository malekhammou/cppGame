#include "player.h"
#include <iostream>
#include <string>
#include <regex>

int main(){

    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*WELCOME-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    player p1;
    player p2;
    while(p1.getName()=="Unknown" || p2.getName()=="Unknown"){
        if(p1.getName()=="Unknown"){
            string name;
            cout<<"Hey Player1, please enter your name"<<endl;
            getline(cin,name);
            if(name!=""&&name!=" "){
                p1.setName(name);
            }

        }
        else{
            string name;
            cout<<"Hey Player2, please enter your name"<<endl;
            getline(cin,name);
            if(name!=""&&name!=" "){
                p2.setName(name);
            }

        }
    }
    cout<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"Great! Hi "<<p1.getName()<<" and "<<p2.getName()<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;

    p1.setEnemy(&p2);
    p2.setEnemy(&p1);
    bool winnerExists=false;
    for (int i = 0; i < 6; ++i) {
        if(i%2==0){
            if(p1.isDead()){
                cout<<p2.getName()<<" wins."<<endl;
                winnerExists= true;
                break;
            }
            else
            p1.chooseAction();
        }
        else{
            if(p2.isDead()){
                cout<<p1.getName()<<" wins."<<endl;
                winnerExists= true;
                break;
            }
             else p2.chooseAction();
        }
    }
     if(winnerExists==false)p1.isWinner();
    return 0;
}