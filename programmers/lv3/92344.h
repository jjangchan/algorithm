//
// Created by jjangchan on 2024/09/23.
// 92344 - 파괴되지 않는 건물
//

#ifndef MAIN_CPP_92344_H
#define MAIN_CPP_92344_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    std::vector<std::vector<int>> graph(board.size()+2, std::vector<int>(board[0].size()+2, 0));

    for(auto& v : skill){
        int op = (v[0] == 1) ? -1*v[5] : 1*v[5];
        graph[v[1]+1][v[2]+1] += op, graph[v[1]+1][v[4]+2] = op*-1;
        graph[v[3]+2][v[2]+1] += op*-1, graph[v[3]+2][v[4]+2] += op;
    }

    auto pre_sum = [&graph](const std::size_t m1, const std::size_t  m2, const int x) -> void{
        for(int i = 1; i <= m1; i++) {
            int sum = 0;
            for(int j = 1; j <= m2; j++){
                int &val = (x == 1) ? graph[i][j] : graph[j][i];
                sum += val;
                val = sum;
            }
        }

    };

    pre_sum(board.size(), board[0].size(), 1);
    pre_sum(board[0].size(), board.size(), 2);

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++){
           board[i][j] += graph[i+1][j+1];
           if(board[i][j] > 0) answer++;
        }
    }
    return answer;
}


#endif //MAIN_CPP_92344_H
