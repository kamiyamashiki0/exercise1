#include <vector>
#include "startMatch.h"
#include <random>
#include <ctime>

void startMatch::createPlayer()
{

    for (int i = 0; i < 12;i++)
    {
        player_v.push_back(player(i + 1,'a', score[i]));
    }
}

void startMatch::createScore()
{
    std::default_random_engine e;
    std::uniform_real_distribution<float> u(0,100);
    e.seed(time(0));
    for (int i = 1; i <= 12;i++)
    {
        score.push_back(u(e));
    }
}

