//
// Created by jjangchan on 2022/01/05.
// 수식 최대화
//

#ifndef MAIN_CPP_67257_H
#define MAIN_CPP_67257_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <memory.h>

using namespace std;

long long answer;

long long Calculate(const long long a, const long long b, char c){
    switch (c) {
        case '*' : return a*b;
        case '-' : return a-b;
        case '+' : return a+b;
    }
}

void Calculate(const std::vector<std::string> &v){
    std::stack<long long> s;
    for(const auto& str : v){
        if(!isdigit(str[0])){
            long long b = s.top();
            s.pop();
            long long a = s.top();
            s.pop();
            s.push(Calculate(a, b, str[0]));
        }else s.push(std::stoll(str));
    }
    long long result = std::abs(s.top());
    answer = result > answer ? result : answer;
}

void ParseOperator(const std::vector<std::string>& v, std::map<std::string, int>& priority){
    // 중의표기법 -> 후의표기법
    std::stack<std::string> s;
    std::vector<std::string> transform;
    for(const auto& str : v){
        if(!isdigit(str[0])){
            while(!s.empty() && priority[s.top()] >= priority[str]) {
                transform.push_back(s.top());
                s.pop();
            }
            s.push(str);
        }else transform.push_back(str);
    }
    while(!s.empty()){
        transform.push_back(s.top());
        s.pop();
    }
    Calculate(transform);
}

void Permutation(const std::string& str, const std::string& target, bool *is, const std::vector<std::string> &v){
    if(str.size() == target.size()){
        std::map<std::string, int> priority;
        for(int i = 0; i < target.size(); i++) priority[target.substr(i,1)] = target.size()-i;
        ParseOperator(v, priority);
        return;
    } else for(int i = 0; i < str.size(); i++){
        if(!is[i]){
            is[i] = true;
            Permutation(str, target+str[i], is, v);
            is[i] = false;
        }
    }
}

void StrSplit(std::vector<std::string> &splited, std::set<std::string>& s, const string& str)
{
    std::string str_integer = "";
    for(const char& c : str){
        if(isdigit(c)) str_integer.push_back(c);
        else{
            std::string temp ="";
            temp.push_back(c);
            s.insert(temp);
            splited.push_back(str_integer);
            splited.push_back(temp);
            str_integer = "";
        }
    }
    splited.push_back(str_integer);
}

long long solution(string expression) {
    answer = 0;
    std::vector<std::string> splited;
    std::set<std::string> s;
    StrSplit(splited, s, expression);
    std::string ope ="";
    for(const auto a : s) ope += a;
    bool is[ope.size()];
    memset(is, false, ope.size());
    Permutation(ope, "", is, splited);
    return answer;
}

#endif //MAIN_CPP_67257_H
