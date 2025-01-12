#pragma once
#include <vector>
#include <string>

class player
{
public:
    player(int x, std::string str, float y) : id(x), name(str), score(y) {}

private:
    int id;
    std::string name;
public:
    float score;
};

class startMatch
{
public:
    void createPlayer();
    void createScore(int);
    void matchFirst();

private:
    std::vector<player> player_v,match1,match2;
    std::vector<float> score;
};
