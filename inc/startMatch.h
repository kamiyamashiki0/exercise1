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
    float score;
};

class startMatch
{
public:
    void createPlayer();
    void createScore();

private:
    std::vector<player> player_v;
    std::vector<float> score;
};
