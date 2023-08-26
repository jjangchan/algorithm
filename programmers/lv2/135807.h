//
// Created by jjangchan on 2023/08/16.
// 숫자 카드 나누기 - 135807
//

#ifndef MAIN_CPP_135807_H
#define MAIN_CPP_135807_H

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    auto GCD = [&](const std::vector<int>& v)->int{
        int a = v[0];
        for(int i = 1; i < v.size(); i++){
            int b = v[i];
            while(1){
                int r = a%b;
                if(!r) {
                    a = b;
                    break;
                }
                a = b, b = r;
            }
            if(a == 1) return 1;
        }
        return a;
    };
    int A = GCD(arrayA), B = GCD(arrayB);
    if(A == 1 && B == 1) return 0;
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
    const std::vector<int>& cd_a = CD(A), &cd_b = CD(B);
    auto chk_max = [&](const std::vector<int>& cd, const std::vector<int>& array)-> int{
        int result = 0;
        for(int num : cd){
            int i;
            for(i = 0; i < array.size(); i++) if(array[i]%num == 0) break;
            if(i == array.size()) return num;
        }
        return result;
    };
    return std::max(chk_max(cd_a, arrayB), chk_max(cd_b, arrayA));
}

#endif //MAIN_CPP_135807_H
