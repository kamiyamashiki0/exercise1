#pragma once
#include <vector>
#include <string>

class player
{
public:
    player(int x, std::string str, float y) : id(x), name(str), score(y) {}


    int id;
    std::string name;

    float score;
};

class startMatch
{
public:
    void createPlayer();
    void createScore(int);
    void matchFirst();

private:
    std::vector<player> player_v,match1_1,match1_2,match2;
    std::vector<float> score;
    std::string userFile;
};
