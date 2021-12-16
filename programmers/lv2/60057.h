//
// Created by jjangchan on 2021-12-16.
// 문자열 압축
//

#ifndef MAIN_CPP_60057_H
#define MAIN_CPP_60057_H

#include <string>
#include <vector>

using namespace std;

void InsertPattern(std::vector<std::string>& patterns, const std::string& s, const int n){
    for(int i = 0; i < s.length(); i += n) patterns.push_back(s.substr(i, n));
}

int solution(string s) {
    int min = s.length();
    for(int i = 1; i <= s.length()/2; ++i){
        std::string str = "";
        std::vector<std::string> patterns;
        InsertPattern(patterns, s, i);
        std::string pattern = patterns[0];
        int count = 1;
        for(int j = 1; j < patterns.size(); j++){
            if(pattern != patterns[j]){
                if(count != 1) str += to_string(count);
                str += pattern;
                pattern = patterns[j];
                count = 1;
            }else count++;
        }
        if(count != 1) str += to_string(count);
        str += pattern;

        std::cout << "str : " << str << std::endl;
        min = min < str.length() ? min : str.length();
    }

    return min;
}

#endif //MAIN_CPP_60057_H
