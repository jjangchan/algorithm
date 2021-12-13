//
// Created by jjangchan on 2021-12-13.
// 최소직사각형
//

#ifndef MAIN_CPP_86491_H
#define MAIN_CPP_86491_H
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int left_max = 0, right_max = 0;
    for(std::vector<int>& size : sizes){
        int right, left;
        // 무조건 왼쪽이 오른쪽 보다 커야한다.
        if(size[0] > size[1]){
            left = size[0];
            right = size[1];
        }else{
            left = size[1];
            right = size[0];
        }
        // max값 찾기
        left_max = left_max > left ? left_max : left;
        right_max = right_max > right ? right_max : right;
    }
    return left_max*right_max;
}


#endif //MAIN_CPP_86491_H
