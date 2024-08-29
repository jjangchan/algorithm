//
// Created by jjangchan on 2024/06/20.
// 68936 - 쿼드압축 후 개수 세기
//

#ifndef MAIN_CPP_68936_H
#define MAIN_CPP_68936_H
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);
    std::queue<std::vector<int>> location;
    int len = arr.size()-1;
    location.push({0, 0, len, len});
    while(!location.empty()){
        std::vector<int> v = location.front();
        location.pop();
        int chk = arr[v[0]][v[1]];
        bool out = true;
        for(int i = v[0]; i <= v[2] && out; i++) {
            for(int j = v[1]; j <= v[3] && out; j++){
                if(chk != arr[i][j]) out = false;
            }
        }
        if(!out){
            int x = v[0], y = v[1], m = (v[2]-v[0])/2;
            for(int i = 0; i < 4; i++){
                int n_x = (i&1) ? x+m+1 : x;
                int n_y = (i&2) ? y+m+1 : y;
                location.push({n_x, n_y, n_x+m, n_y+m});
            }
        }else answer[chk]++;
    }
    return answer;
}

#endif //MAIN_CPP_68936_H
