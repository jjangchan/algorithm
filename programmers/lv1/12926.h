//
// Created by jjangchan on 2021-12-14.
// 시저 암호
//

#ifndef MAIN_CPP_12926_H
#define MAIN_CPP_12926_H

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = (s[i]+n > 90) ? s[i]+n-'Z'+64 : s[i]+n;
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = (s[i]+n > 122) ? s[i]+n-'z'+96 : s[i]+n;
        }
    }
    return s;
}

#endif //MAIN_CPP_12926_H
