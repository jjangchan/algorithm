//
// Created by jjangchan on 2023/12/26.
// PCCE 기출문제 9번 - 이웃한 칸
//

#ifndef MAIN_CPP_250125_H
#define MAIN_CPP_250125_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;


int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int dh[4] = {0,1,-1,0};
    int dw[4] = {1,0,0,-1};
    for(int i = 0; i < 4; i++){
        int x = h+dh[i], y = w+dw[i];
        std::cout << x << "," << y << std::endl;
        if(x < 0 || x >= board.size() || y < 0 || y >= board.size()) continue;
        if(board[h][w] == board[x][y]) answer++;
    }
    return answer++;
}

#endif //MAIN_CPP_250125_H
