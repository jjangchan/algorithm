//
// Created by jjangchan on 2023/12/30.
// PCCP 3번 - 아날로그 시계
//

#ifndef MAIN_CPP_250135_H
#define MAIN_CPP_250135_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0, start = (h1*60*60)+(m1*60), end = (h2*60*60)+(m2*60)+s2;
    double cal_h = ((h1*5)%60)+(m1/60.0)*5.0, cal_m = m1;
    double h_x = 720.0/719.0, m_x = 60.0/59.0;

    while(start <= end){
        double overlap_h = cal_h*h_x, overlap_m = cal_m*m_x;
        bool is_h = (start+std::ceil(overlap_h) <= end && overlap_h < 60.0);
        bool is_m = (start+std::ceil(overlap_m) <= end && overlap_m < 60.0);
        if((double)s1 <= overlap_h && is_h) answer++;
        if((double)s1 <= overlap_m && is_m) answer++;
        if(is_h && is_m && overlap_h == overlap_m) answer--;
        double next_h = cal_h+(5.0/60.0), next_m = cal_m+1;
        cal_h = (next_h >= 60) ? 0 : next_h, cal_m = (next_m >= 60) ? 0 : next_m;
        start += 60;
        s1 = 0;
    }
    return answer;
}

#endif //MAIN_CPP_250135_H
