//
// Created by jjangchan on 2022/08/19.
// 게임 맵 최단거리
//

#ifndef MAIN_CPP_1844_H
#define MAIN_CPP_1844_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool graph[102][102];

struct info{
    int x, y, d;
};

int solution(vector<vector<int> > maps)
{
    for(int i = 0; i < maps.size(); i++) for(int j = 0; j < maps[0].size(); j++){
        graph[i+1][j+1] = maps[i][j];
    }

    int direction[4][2] = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
    std::queue<info> q;
    q.push({0,1,0});
    while(!q.empty()){
        auto in = q.front();
        q.pop();
        if(in.x == maps.size() && in.y == maps[0].size()) return in.d;
        for(int i =0; i < 4; i++){
            int r = in.x+direction[i][0], c = in.y+direction[i][1];
            if(graph[r][c]){
                graph[r][c] = false;
                q.push({ r, c, in.d+1});
            }
        }
    }
    return -1;
}

#endif //MAIN_CPP_1844_H
