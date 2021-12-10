//
// Created by jjangchan on 2021-12-09.
// 폰켓몬
//

#ifndef MAIN_CPP_1845_H
#define MAIN_CPP_1845_H

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size()/2;
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return max > nums.size() ? nums.size() : max;
}

#endif //MAIN_CPP_1845_H
