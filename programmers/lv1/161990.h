//
// Created by jjangchan on 2023/07/07.
// 바탕화면 정리 - 161990
//

#ifndef MAIN_CPP_161990_H
#define MAIN_CPP_161990_H

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int x1 = 50, y1 = 50, x2 = -1, y2 = -1;
    for(int i = 0; i < wallpaper.size(); i++){
        std::string code_file = wallpaper[i];
        bool is_y = false;
        for(int j = 0; j < code_file.size(); j++){
            if(code_file[j] == '#'){
                x1 = j < x1 ? j : x1;
                x2 = j > x2 ? j : x2;
                is_y = true;
            }
        }
        if(is_y){
            y1 = i < y1 ? i : y1;
            y2 = i > y2 ? i : y2;
        }
    }

    return {y1, x1, y2+1, x2+1};
}
#endif //MAIN_CPP_161990_H
