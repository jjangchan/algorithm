//
// Created by jjangchan on 2021-12-21.
// target number
//

#ifndef MAIN_CPP_43165_H
#define MAIN_CPP_43165_H

#include <string>
#include <vector>

using namespace std;

/** BIT solution
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

    for(int i = 0 ; i < size ; i++){
        int temp = 0;
        for(int j = 0 ; j < numbers.size() ; j++)
        {
            if(i &(1 << j)){
                temp -= numbers[j];
            }
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }
    return answer;
}
**/

void SearchTarget(const int start, const std::vector<int>& v, const int sum, int& count, const int target){
    if(start == v.size()){
        if(sum == target || sum*-1 == target) count++;
        return;
    }
    SearchTarget(start+1, v, sum+v[start], count, target); // +1
    if(start >= 1)
        SearchTarget(start+1, v, sum-v[start],count,target); // -1, 첫번쨰항(x1, x2, x3) , 마지막항(-x1, -x2, -x3) 따라서 Xn-a+1 == -1(Xa)
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    SearchTarget(0, numbers, 0, answer, target);
    return answer;
}

#endif //MAIN_CPP_43165_H