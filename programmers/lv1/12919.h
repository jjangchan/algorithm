//
// Created by jjangchan on 2021-12-14.
//

#ifndef MAIN_CPP_12919_H
#define MAIN_CPP_12919_H
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int i;
    for(i = 0; i < seoul.size(); i++) if(seoul[i] == "Kim") return "김서방은 "+to_string(i)+"에 있다";
}
#endif //MAIN_CPP_12919_H
