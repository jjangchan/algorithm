//
// Created by jjangchan on 2021-12-16.
// 제일 작은 수 제거하기
//

#ifndef MAIN_CPP_12935_H
#define MAIN_CPP_12935_H
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int min = arr[0], min_index = 0;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < min){
            min = arr[i];
            min_index = i;
        }
    }
    if(min_index == 0){
        arr.clear();
        arr.push_back(-1);
    }else{
        arr.erase(arr.begin()+min_index);
    }
    return arr;
}
#endif //MAIN_CPP_12935_H
