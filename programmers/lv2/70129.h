//
// Created by jjangchan on 2022/08/19.
// 이진 변환 반복하기
//

#ifndef MAIN_CPP_70129_H
#define MAIN_CPP_70129_H

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int remove_convert(std::string& s){
    std::string temp = "";
    for(const char& c : s){
        if(c == '1') temp += c;
    }
    int count = s.size()-temp.size();
    s = "";
    for(int i = 0; i < (int)std::log2(temp.size())+1; i++)
        s += (temp.size() & (1 << i)) ? "1" : "0";
    return count;
}

vector<int> solution(string s) {
    vector<int> answer = {0,0};
    while(s != "1"){
        answer[1] += remove_convert(s);
        answer[0]++;
    }

    return answer;
}

#endif //MAIN_CPP_70129_H
