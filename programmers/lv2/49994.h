//
// Created by jjangchan on 2024/07/13.
// 49994 - 방문길이
//

#ifndef MAIN_CPP_49994_H
#define MAIN_CPP_49994_H

#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(string dirs) {
    int answer = 0;
    std::vector<std::vector<int>> graph{25, std::vector<int>(25, 0)};
    int location[26];
    location['U'-'A'] = 0, location['D'-'A'] = 1, location['R'-'A'] = 2, location['L'-'A'] = 3;
    int dx[4] = {-2, 2, 0, 0}, dy[4] = {0, 0, 2, -2};
    for(int i = 2; i <= 22; i++) for(int j = 2; j <= 22; j++) graph[i][j] = 1;

    int x = 12, y = 12;
    for(int i = 0; i < dirs.size(); i++){
        int index = dirs[i]-'A';
        int f_x = x+dx[location[index]], f_y = y+dy[location[index]];
        if(graph[f_x][f_y]){
            int h_x = x+(dx[location[index]]/2), h_y =  y+(dy[location[index]]/2);
            if(graph[h_x][h_y]) answer++;
            graph[h_x][h_y] = 0;
            x = f_x, y = f_y;
        }
    }
    return answer;
}

#endif //MAIN_CPP_49994_H
