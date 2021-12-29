//
// Created by jjangchan on 2021-12-29.
// [1차] 뉴스 클러스터링
//

#ifndef MAIN_CPP_17677_H
#define MAIN_CPP_17677_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define NUM 65536.0

using namespace std;

/** 효율적 풀이법
#include <bits/stdc++.h>
using namespace std;
short a, b, C[676], D[676];
int solution(string A, string B) {
    for(int i=1; i<A.size(); i++)
        if(isalpha(A[i-1]) && isalpha(A[i]))
            C[(A[i-1]&31)*26+(A[i]&31)]++;
    for(int i=1; i<B.size(); i++)
        if(isalpha(B[i-1]) && isalpha(B[i]))
            D[(B[i-1]&31)*26+(B[i]&31)]++;
    for(int i=0; i<676; i++) a+=min(C[i], D[i]), b+=max(C[i], D[i]);
    return b ? a*65536/b : 65536;
}
*/

std::ostream& operator<<(std::ostream& os, std::vector<std::string>& v){
    for(const auto& s : v) os << s << " ";
    return os;
}

char& ToLower(char& c){
    if(65 <= c && c <= 90) c |= 32;
    return c;
}

void Cluster(std::vector<std::string>& v, std::string& s){
    for(int i = 0; i < s.size()-1; i++){
        if(isalpha(s[i]) && isalpha(s[i+1])){
            std::string temp ="";
            temp.push_back(ToLower(s[i]));
            temp.push_back(ToLower(s[i+1]));
            v.push_back(temp);
        }
    }
    std::sort(v.begin(), v.end());
}


double MakeSetCount(std::vector<std::string>& v1, std::vector<std::string>& v2, const int mode = 0){
    std::vector<std::string> buff(v1.size()+v2.size());
    auto iter = (mode == 0) ? set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), buff.begin()) : set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), buff.begin());
    buff.erase(iter, buff.end());
    return buff.size();
}



int solution(string str1, string str2) {
    int answer = 0;
    std::vector<std::string> v1;
    std::vector<std::string> v2;
    Cluster(v1, str1);
    Cluster(v2, str2);
    if(v1.size() + v2.size() == 0) return NUM;
    answer = NUM*static_cast<double>(MakeSetCount(v1, v2, 1)/ MakeSetCount(v1, v2));
    return (int)answer;
}

#endif //MAIN_CPP_17677_H
