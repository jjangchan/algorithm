//
// Created by jjangchan on 2024/07/02.
// 68645 - 삼각달팽이
//

#ifndef MAIN_CPP_68645_H
#define MAIN_CPP_68645_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    std::vector<std::vector<int>> graph(n+2, std::vector<int>(n+2, 0));
    int counts[n+1];
    int dx[3] = {1, 0, -1}, dy[3] = {0, 1, 0};
    int cnt = 1, max = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) graph[i][j] = 1;
        counts[i] = i, max += i;
    }

    auto dfs  = [&](auto& re, const int x, const int y)-> void{
        int n_x = x, n_y = y;
        for(int i = 0; i < 3; i++){
            while(true){
                if(graph[n_x+dx[i]][n_y+dy[i]] == 1) n_x += dx[i], n_y += dy[i];
                else break;
                if(counts[n_x] > 0){
                    graph[n_x][n_y] = cnt++;
                    counts[n_x]--;
                    if(cnt > max) return;
                }
            }
        }
        re(re, x, y+1);
    };

    dfs(dfs, 0, 1);
    answer.push_back(1);
    for(const auto& v : graph){
        for(int i : v){
            std::cout << i << "\t";
        }
        std::cout << std::endl;
    }
    for(const auto& v : graph)  for(int i : v){
        if(i > 1) answer.push_back(i);
    }

    return answer;
}

#endif //MAIN_CPP_68645_H
