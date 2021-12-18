//
// Created by jjangchan on 2021-11-05.
// 2618 - 경찰차
//

#ifndef MAIN_CPP_2618_H
#define MAIN_CPP_2618_H

#include <iostream>
#include <cstring>
#include <map>
#include <cmath>

int N,W;
int dp[1001][1001];
std::pair<int, int> event[1001];
std::map<std::string, int> result;

int Distance(const std::pair <int, int> &a , const std::pair<int, int>&b){
    return abs(b.first-a.first) + abs(b.second-a.second);
}

int DP(const int x, const int y){
    if(x >= W || y >= W) return 0;

    //memoization
    int &value = dp[x][y];
    if(value != -1) {
        return dp[x][y];
    }

    int next = std::max(x, y)+1;

    int distance_x = (x == 0) ? Distance({1, 1}, event[next]) : Distance(event[x], event[next]);
    int distance_y = (y == 0) ? Distance({N, N}, event[next]) : Distance(event[y], event[next]);

    value = std::min(DP(next, y) + distance_x, DP(x, next) + distance_y);
    return value;
}

void Search(const int x, const int y){
    if(x >= W || y >= W) return;

    int next = std::max(x,y)+1;
    int distance_x = (x == 0) ? Distance({1, 1}, event[next]) : Distance(event[x], event[next]);
    int distance_y = (y == 0) ? Distance({N, N}, event[next]) : Distance(event[y], event[next]);

    if(dp[next][y] + distance_x > dp[x][next]+distance_y){
        std::cout << "2" << std::endl;
        Search(x, next);
    }else{
        std::cout << "1" << std::endl;
        Search(next, y);
    }
    return;
}

void Init(){
    scanf("%d\n%d", &N, &W);
    for(int i = 1; i <= W; ++i) scanf("%d %d", &event[i].first, &event[i].second);
}

int main(){
    Init();
    std::memset(dp, -1, sizeof(dp));
    std::cout << DP(0,0)<< std::endl;
    for(int i = 0; i < W; i ++) for(int j = 0; j < W; j++){
            std::cout << "(" << i  << "," << j <<") " << dp[i][j] << std::endl;
        }
    Search(0,0);
    return 0;
}
#endif //MAIN_CPP_2618_H
