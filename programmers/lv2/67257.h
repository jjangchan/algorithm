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

void Permutation(const std::string& str, const std::string& target, bool *is, const std::vector<std::string> &v){
    if(str.size() == target.size()){
        std::map<std::string, int> priority;
        for(int i = 0; i < target.size(); i++) priority[target.substr(i)] = i;
        
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
    long long answer = 0;
    std::vector<std::string> splited;
    std::set<std::string> s;
    StrSplit(splited, s, expression);
    std::string ope(s.begin(), s.end());
    bool is[ope.size()];
    memset(is, false, ope.size());
    Permutation(ope, "", is, splited);
    return answer;
}

#endif //MAIN_CPP_67257_H
