//
// Created by jjangchan on 2021-12-27.
// 괄호 변환
//

#ifndef MAIN_CPP_60058_H
#define MAIN_CPP_60058_H

#include <string>
#include <vector>

using namespace std;

std::string Transform(std::string p, std::string u, std::string v){
    if(p.size() == 0) return "";
    int right = 0, left = 0, i = 0;
    bool stable = false;
    std::string reverse = "";
    for(; i < p.size(); i++){
        u.push_back(p[i]);
        if(p[i] == '('){
            reverse.push_back(')');
            right++;
        }else {
            reverse.push_back('(');
            left++;
        }
        if(right == left) break;
    }
    v = p.substr(i+1);
    v = Transform(v, "", "");
    if(u[0] == ')' && u[u.size()-1] == '('){
        reverse = reverse.substr(1);
        reverse.pop_back();
        return "("+v+")"+reverse;
    }
    return u+v;
}

string solution(string p) {
    return Transform(p, "", "");
}

#endif //MAIN_CPP_60058_H
