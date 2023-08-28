//
// Created by jjangchan on 2023/08/26.
// kakao - k진수에서 소수 개수 구하기
//

#ifndef MAIN_CPP_92335_H
#define MAIN_CPP_92335_H

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;

    auto is_prime = [](long long num)->int{
        if(num == 1) return 0;
        if(num == 2) return 1;
        long long end = sqrt(num);
        for(int i = 2; i <= end; i++) if(num%i == 0) return 0;
        return 1;
    };

    std::string str = "0";
    while(n >= 1) str = to_string(n%k)+str, n /= k;
    std::string temp;
    for(const char c : str){
        if(c == '0' && !temp.empty()){
            if(is_prime(stoll(temp))) answer++;
            temp = "";
        }else if(c != '0')temp.push_back(c);
    }

    return answer;
}

#endif //MAIN_CPP_92335_H
