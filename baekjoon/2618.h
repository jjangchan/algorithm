//
// Created by jjangchan on 2021-11-05.
// 2618 - 경찰차
//

#ifndef MAIN_CPP_2618_H
#define MAIN_CPP_2618_H

#include <iostream>
#include <vector>
int N,W;

std::pair<int, int>work[1001];
int dp_table[1001][1001];

int dist(std::pair<int, int> a, std::pair<int, int> b){
    return std::abs(b.first - a.first) + std::abs(b.second - a.second);
}

int dp(int x, int y){
    if(x == W || y == W) return 0;
    //memoization
    int &cache = dp_table[x][y];
    if(cache != -1) return dp_table[x][y];

    int next = std::max(x, y)+1;
    int distance1, distance2;

    //base
    // move x
    distance1 = (x==0) ? dist({1,1}, work[next]) : dist(work[x], work[next]);
    // move y
    distance2 = (y == 0) ? dist({N,N}, work[next]) : dist(work[y], work[next]);
    cache = std::min(dp(next, y) + distance1, dp(x, next)+distance2);
    return cache;
}

int main(){
    return 0;
}


#endif //MAIN_CPP_2618_H
