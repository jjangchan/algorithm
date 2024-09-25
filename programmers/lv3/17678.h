//
// Created by jjangchan on 2024/09/09.
// 17678 - 셔틀버스
//

#ifndef MAIN_CPP_17678_H
#define MAIN_CPP_17678_H

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

std::string next_time(const std::string& time, const int t){
    int hour = std::stoi(std::string(time.begin(), time.begin()+2));
    int min = std::stoi(std::string(time.begin()+3, time.end()));
    std::string next;

    auto zero_padding = [](const std::size_t val, const std::size_t n)->std::string{
        std::string str = std::to_string(val);
        size_t precision = n-std::min(n, str.size());
        return std::string(precision, '0').append(str);
    };

    std::string s_hour;
    if(min+t >= 60) s_hour = zero_padding(hour+1, 2);
    else if(min+t < 0) s_hour = zero_padding((hour-1 < 0) ? 23 : hour-1, 2);
    else s_hour = zero_padding(hour, 2);

    std::string s_min = zero_padding((60+(min+t))%60, 2);
    next = s_hour.append(":").append(s_min);
    return (next >= "24:00") ? "23:59" : next;
}

string solution(int n, int t, int m, vector<string> timetable) {
    std::sort(timetable.begin(), timetable.end());
    std::string bus_time = "09:00";
    int index = 0, cnt = 0;
    std::string answer = "";

    while(n--){
        cnt = 0;
        while(index < timetable.size() && cnt < m && bus_time >= timetable[index]) {
            if(n == 0) if(answer != timetable[index]) answer = timetable[index];
            cnt++, index++;
        }
        std::cout << bus_time << ":" << cnt << "\t";
        if(n) bus_time = next_time(bus_time, t);
    }
    if(cnt < m) return bus_time;
    std::cout << next_time(answer, -1) << std::endl;
    return next_time(answer, -1);
}

#endif //MAIN_CPP_17678_H
