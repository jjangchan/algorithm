//
// Created by jjangchan on 2023/07/08.
// 햄버거 만들기
//

#ifndef MAIN_CPP_133502_H
#define MAIN_CPP_133502_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;
int check[4] = {1,2,3,1};

int is_cook(std::vector<int>& ingredient, int i){
    for(int j = 0; j < 4; j++){
        if(check[j] != ingredient[i+j]){
            return -1;
        }
    }
    return 1;
}

int solution(vector<int> ingredient) {
    int answer = 0;
    int i = 0;
    while(ingredient.size() >= 4 && i < (int)ingredient.size()-3){
        if(is_cook(ingredient, i) == 1){
            ingredient.erase(ingredient.begin()+i, ingredient.begin()+i+4);
            std::cout << "erase : " << i << std::endl;
            std::cout << (int)(ingredient.size()-3) << std::endl;
            i = (i <= 1) ? 0 : i-2;
            answer++;
        }else{
            i++;
        }
    }
    return answer;
}

/**
 * 연속되는 숫자 1,2,3,1 을 찾으면 햄버거는 완성된다.
 * 1,2,3,1를 빼고 다시 1,2,3,1이 완성되는지 체크한다.
 *
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for(int x : ingredient){
        if(v.back() == 1 && x == 2) v.back() = 12;
        else if(v.back() == 12 && x == 3) v.back() = 123;
        else if(v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }

    return answer;
}
 */

#endif //MAIN_CPP_133502_H
