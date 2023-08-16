#include <iostream>
#include <cmath>
#include "programmers/lv2/138476.h"


int gcd(int a, int b){
    while(1){
        int c = a%b;
        if(c == 0) return b;
        a = b;
        b = c;
    }
}

int main(){
    auto CD = [&](int a)->std::vector<int>{
        std::vector<int> v;
        int end = std::sqrt(a);
        for(int i = 1; i <= end; i++){
            if(a%i == 0){
                v.push_back(i);
                if(a/i != i) v.push_back(a/i);
            }
        }
        std::sort(v.begin(), v.end(), greater<>());
        v.pop_back();
        return v;
    };
    std::vector<int> v = CD(2);
    for(int i : v) std::cout << i << std::endl;
    return 0;
}