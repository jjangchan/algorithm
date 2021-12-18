//
// Created by jjangchan on 2021-12-10.
// 2016년
//

#ifndef MAIN_CPP_12901_H
#define MAIN_CPP_12901_H
#include <string>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    // calculate unix_time
    int day_unix_time = 60*60*24;
    time_t start_unix_time = 1451574000-(day_unix_time)+(60*60*9); // GMT()
    int month[13] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_day = b;
    for(int i = 1; i < a; i++) total_day += month[i];
    start_unix_time += (total_day*day_unix_time);
    std::cout << ctime(&start_unix_time);
    std::cout << start_unix_time << std::endl;
    for(int i = 0; i < 3; i++) {
        char c = ctime(&start_unix_time)[i];
        if(c >= 'a' && c <= 'z') c ^= 32;
        answer.push_back(c);
    }
    std::cout << answer;
    return answer;
}
#endif //MAIN_CPP_12901_H
