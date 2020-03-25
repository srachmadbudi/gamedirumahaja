#ifndef PAAQUIZ2_TRAP_GAME_H
#define PAAQUIZ2_TRAP_GAME_H

#include<bits/stdc++.h>

using namespace std;

class trap_game{
public:
    string player;
    stack <pair<int,int>> S;
    int n , steps;
    char **simpangan;
    int score;
    int kehidupan;
    int *counter_ptr;
    int counter;

    trap_game(int n , string name, char **simpangan_, int *counter_);

    void randomObstruction(double percent);
    void redefine(int n1);
    void Gambar_simpangan();
    int move(int x,int y);
    void score_play(int shortest , double percent);
};

#endif //PAAQUIZ2_TRAP_GAME_H
