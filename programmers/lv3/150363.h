//
// Created by jjangchan on 2024/09/02.
// 150365 - 미로 탈출 명령어
//

#ifndef MAIN_CPP_150363_H
#define MAIN_CPP_150363_H

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "impossible";
    std::vector<std::vector<int>> graph(n+2, std::vector<int>(m+2, -1));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
            int distance = std::abs(i-r)+std::abs(j-c);
            graph[i][j] = distance;

    }

    char name[4] = {'d', 'l', 'r', 'u'};
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    auto dfs = [&](auto& re, std::string m, int x, int y) -> void{
        if(m.size() == k) {
            //std::cout << m << std::endl;
            if(x == r && y == c) answer = m;
            return;
        }
        int i = 0, next_x, next_y;
        for(i = 0; i < 4; i++){
            next_x = x+dx[i], next_y = y+dy[i];
            int dist = graph[next_x][next_y];
            if(dist >= 0 && k-m.size() >= dist) break;
        }
        if(i < 4) re(re, m+name[i], next_x, next_y);
    };
    dfs(dfs, "", x, y);
    return answer;
}

#endif //MAIN_CPP_150363_H
