//
// Created by jjangchan on 2023/08/24.
// kakao - 주차 요금 계산
//

#ifndef MAIN_CPP_92341_H
#define MAIN_CPP_92341_H
#define END_TIME 1439

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int str_to_time(const std::string& str){
    return std::stoi(str.substr(0,2))*60+std::stoi(str.substr(3,2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    std::stable_sort(records.begin(), records.end(), [](const std::string& a, const std::string& b)->int{
        return a.substr(6,4) < b.substr(6,4);
    });
    double total_time = 0, pre_time = str_to_time(records[0].substr(0,5));
    int num_cnt = 1;
    std::string time, info, number, pre_number = records[0].substr(6,4);
    auto total_fee = [&]()->int{
        total_time += (num_cnt%2 == 0) ? 0 : (END_TIME-pre_time);
        int add_fee = (total_time <= (double)fees[0]) ? 0 : (int)std::ceil((total_time-fees[0])/fees[2])*fees[3];
        return fees[1]+add_fee;
    };

    for(int i = 1; i < records.size(); i++){
        std::istringstream iss(records[i]);
        iss >> time >> number >> info;
        double cur_time = str_to_time(time);
        if(number != pre_number){
            answer.push_back(total_fee());
            pre_time = cur_time;
            total_time = 0, num_cnt = 1;
        }else{
            if(info == "OUT") total_time += (cur_time-pre_time);
            else pre_time = cur_time;
            num_cnt++;
        }
        pre_number = number;
    }
    answer.push_back(total_fee());
    return answer;
}

#endif //MAIN_CPP_92341_H
