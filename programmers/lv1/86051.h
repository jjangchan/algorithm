//
// Created by jjangchan on 2021-11-17.
// 없는 숫자 더하기
//

#ifndef MAIN_CPP_86051_H
#define MAIN_CPP_86051_H

#include <string>
#include <vector>

int solution(std::vector<int> numbers) {
    int answer = 0;
    for(int i : numbers) answer += i;
    return 45-answer;
}
#endif //MAIN_CPP_86051_H
