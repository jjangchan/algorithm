//
// Created by jjangchan on 2023/08/10.
// 테이블 해시 함수 - 147354
//

#ifndef MAIN_CPP_147354_H
#define MAIN_CPP_147354_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    std::sort(data.begin(), data.end(), [&](const auto& a, const auto& b)->int {
        if(a[col-1] == b[col-1]) return a[0] > b[0];
        return a[col-1] < b[col-1];
    });
    for(int i = row_begin-1; i < row_end; i++){
        int cal = 0;
        for(int num : data[i]){
            cal += (num%(i+1));
        }
        answer ^= cal;
    }
    return answer;
}


#endif //MAIN_CPP_147354_H
