#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
/*
 * CONSTRUCTORS
 */
player::player() {
    name="Unknown";
    score=5;
    damages=1;
}

player::player(string name):name(name),score(5),damages(1){}

/*
 *
 */

/*
 * MEMBER FUNCTIONS
 */

bool player::isDead() {
    if(score<=0){
        cout<<name<<" is dead!"<<endl;
        return true;
    }
    else return false;
}

bool player::attack(player *enemy){
    enemy->setScore(enemy->getScore()-damages);
    cout<<enemy->getName()<<"'s new score is: "<<enemy->getScore()<<endl;
    if(enemy->isDead()){
        return true;
    }
    else return false;
}
player player::operator+(const player &p) const {
    player team;
    team.damages=damages+p.getDamages();
    team.score=score+p.getScore();
    team.name=name+" && "+p.getName();
    return team;
}

void player::displayDamages() {
    cout<<name<<" damages: "<<damages<<endl;
}

void player::challenge() {
    int choice;
    cout<<"*******Welcome******* "<<name<<endl;
    cout<<"***********Answer the following Quiz and increase your score!**********"<<endl;
    cout<<"Which field interests you the most?"<<endl;
    cout<<"1-General Culture."<<endl;
    cout<<"2-Mathematics."<<endl;
    cout<<"3-Science."<<endl;
    cin>>choice;
    switch (choice) {
        case 1:
        {
            cout << "in which year did tunisia become independent?" << endl;
            int max_try = 3;
            int answer = 1956;
            int user_input;
            int counter = 0;
            while (counter < max_try) {
                cin >> user_input;
                if (user_input == answer) {
                    setScore(score + max_try - counter);
                    cout << "Congratulations! You guessed it right. your new score is " << score << endl;
                    break;
                } else {
                    cout << "Try again!" << endl;
                    counter++;
                }


            }
            if (counter == max_try) {
                cout << "You lost!" << endl;
            }
        }

            break;
        case 2:
        {
            cout << "What is the result of the following?" << endl;
            cout<<"9 / 6 * 3 - 12 * 2 / 23 - 13 / 2"<<endl;
            int max_try = 3;
            int answer = -3;
            int user_input;
            int counter = 0;
            while (counter < max_try) {
                cin >> user_input;
                if (user_input == answer) {
                    setScore(score + max_try - counter);
                    cout << "Congratulations! You guessed it right. your new score is " << score << endl;
                    break;
                } else {
                    cout << "Try again!" << endl;
                    counter++;
                }


            }
            if (counter == max_try) {
                cout << "You lost!" << endl;
            }
        }
            ;
        break;
        case 3:
        {
            cout<<"What is the name of our galaxy?"<<endl;
            cout << "1-Maffei I and II.\n"
                    "2-Magellanic Clouds.\n"
                    "3-Milky Way Galaxy.\n"
                    "4-Virgo A." << endl;
            int max_try = 3;
            int answer = 3;
            int user_input;
            int counter = 0;
            while (counter < max_try) {
                cin >> user_input;
                if (user_input == answer) {
                    setScore(score + max_try - counter);
                    cout << "Congratulations! You guessed it right. your new score is " << score << endl;
                    break;
                } else {
                    cout << "Try again!" << endl;
                    counter++;
                }


            }
            if (counter == max_try) {
                cout << "You lost!" << endl;
            }
        }
        break;
        default:cout<<"Invalid choice"<<endl;
    }

    /*
     *


     */
}
/*
 *
 */

/*
 * FRIEND FUNCTIONS
 */

ostream & operator << (ostream & os, const player & p){
    os << "Name: " << p.name <<endl<< "Score: " << p.score <<endl<< "Damages: "<<
    p.damages<<endl<< "Enemy: "<<p.enemy->name<<endl;

    return os;
}

istream & operator >> (istream &is, player &p)
{
    cout << "What is your name?"<<endl;
    is >> p.name;
    return is;

}
/*
 *
 */

/*
 * GETTERS AND SETTERS
 */


void player::chooseWeapon() {
    int random_values[3];
    int damage_bonus;
    for (int i = 0; i <3 ; ++i) {
        srand((unsigned) time(0));
        int random_value=rand()%5;
        random_values[i]=random_value;
    }
    cout<<"Choose a secret weapon to increase your damage effect!"<<endl;
    int choice;
    cout<<"1-PETN"<<endl;
    cout<<"2-RDX"<<endl;
    cout<<"3-TNT"<<endl;
    cin>>choice;
    switch (choice) {
        case 1:{
          damage_bonus=random_values[0];
            break;
        }
        case 2 :{
          damage_bonus=random_values[1];
          break;
        }
        case 3:{
          damage_bonus=random_values[2];
          break;
        }

        default:
            cout<<"Invalid choice."<<endl;

    }

    damages+=damage_bonus;
    cout<<"Your new damage effect is: "<<damages<<endl;
}

bool player::chooseAction(){
    int choice;
    cout<<name<<" What do you want to do?"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"1-Take a challenge."<<endl;
    cout<<"2-Attack!"<<endl;
    cout<<"3-Choose weapon"<<endl;
    cin>>choice;
    switch (choice) {
        case 1:{
           challenge();
            return false;
        }
        case 2 :{
           return attack(getEnemy());
            break;

        }
        case 3:{
            chooseWeapon();
            return false;
        }

        default:
            cout<<"Invalid choice."<<endl;
            break;

    }
}

void player::isWinner() {
    if(score>enemy->getScore()){
        cout<<name<<" wins!"<<endl;

    }
    else if(score<enemy->getScore()){
        cout<<enemy->getName()<<" Wins!";
    }
    else{
        cout<<"DRAW.";

    }
}

const string &player::getName() const {
    return name;
}

void player::setName(const string &name) {
    player::name = name;
}

int player::getScore() const {
    return score;
}

void player::setScore(int score) {
    player::score = score;
}

int player::getDamages() const {
    return damages;
}

void player::setDamages(int damages) {
    player::damages = damages;
}

player *player::getEnemy() const {
    return enemy;
}

void player::setEnemy(player *enemy) {
    player::enemy = enemy;
}


