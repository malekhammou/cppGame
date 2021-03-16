#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H
#include <string>
using namespace std;


class player {
private:
    string name;
    int score;
    int damages;
    player *enemy;
public:
    const string &getName() const;

    void setName(const string &name);

    int getScore() const;

    void setScore(int score);

    int getDamages() const;

    void setDamages(int damages);

    player *getEnemy() const;

    void setEnemy(player *enemy);

public:
     player();
     player(string name);


    bool attack(player *enemy);
    void challenge();
    void chooseWeapon();
    bool chooseAction();
    bool isDead();
    void displayDamages();
    void isWinner();

    friend ostream & operator << (ostream &os,const player &p);
    friend istream & operator >> (istream &is, player &p);


};


#endif //PLAYER_PLAYER_H
