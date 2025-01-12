#include <vector>
#include "startMatch.h"
#include <random>
#include <ctime>
#include <algorithm>

void startMatch::createPlayer()//TODO:一种是系统创建，一种是用户创建
{
    if(!player_v.empty())
        player_v.clear();
    std::string tmp_name;
    char c;
    for (int i = 0; i < 12;i++)//TODO:人数也可以是用户输入
    {
        c = 'A' + i;
        tmp_name = c;//等号赋值会先清空原string再赋值
        player_v.push_back(player(i + 1,tmp_name, score[i]));
    }
}

void startMatch::createScore(int playerNumber)
{
    if(!score.empty())
    {
        score.clear();
    }
    // std::default_random_engine e;
    // std::uniform_real_distribution<float> u(0,100);
    // e.seed(time(0));
    std::mt19937 rng;
    rng.seed(time(0));
    std::uniform_real_distribution<float> u(0, 100);
    for (int i = 1; i <= playerNumber;i++)
    {
        score.push_back(u(rng));
    }
}

void startMatch::matchFirst()
{
    std::mt19937 rng;
    rng.seed(time(0));

    std::shuffle(player_v.begin(), player_v.end(), rng);

    std::vector<player>::iterator it = player_v.begin();

    std::transform(it, it + 6, /*match1.begin()*/std::back_inserter(match1), //back_inserter（插入迭代器）执行的是push_back操作，会动态扩展空间，直接用begin()不会扩展空间，需要预留足够的空间
                   [](player p){ return p; });//只是进行复制的话可以用copy

    std::sort(match1.begin(), match1.end(),
              [](player p1, player p2)
              { return p1.score > p2.score; });//严格弱序，不能用>=，避免不必要的拷贝提高性能
}

