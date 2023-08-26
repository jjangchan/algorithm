//
// Created by jjangchan on 2023/08/16.
// 우박수열 정적분
//

#ifndef MAIN_CPP_134239_H
#define MAIN_CPP_134239_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    auto make_lc = [&]() -> std::vector<double> {
        std::vector<double> v;
        while(k != 1){
            v.push_back((double)k);
            k = (k%2 == 0) ? k/2 : k*3+1;
        }
        v.push_back((double)1);
        return v;

    };
    const std::vector<double>& lc = make_lc();
    std::vector<double> volumes;
    for(int i = 0; i < lc.size()-1; i++) volumes.push_back((lc[i]+lc[i+1])/2.0);
    int n = (int)lc.size()-1;
    for(const auto& range : ranges){
        int a = range[0], b = (range[1] > 0) ? range[1]: n+range[1];
        if(a > b) answer.push_back(-1.0);
        else{
            double total = 0.0;
            for(int i = a; i < b; i++) total += volumes[i];
            answer.push_back(total);

        }
    }
    return answer;
}

/**
 * (1차원 두개의 좌표 정적분 공식) -> 밑변 1 고정
 * (x1, y1) , (x2, y2)
 * (y2-y1)/2 + y1*1 = (y1+y2)/2
 *
 */

#endif //MAIN_CPP_134239_H
