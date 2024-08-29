//
// Created by jjangchan on 2023/12/20.
//

#ifndef MAIN_CPP_2023_12_21_H
#define MAIN_CPP_2023_12_21_H

#include <vector>
#include <iostream>
#include <list>

int solution(std::vector<int> student, int k){
    int result = 0;
    int count = 0;
    std::list<int> counts;
    student.push_back(1);

    for(int i = 0; i < student.size(); i++){
        if(student[i]) {
            if(counts.size() >= k){
                int l_count = counts.front();
                counts.pop_front();
                result += (1+l_count+count+(l_count*count));
            }
            counts.push_back(count);
            count = 0;
        }else count++;
    }
    std::cout << result << std::endl;
    return result;
}

#endif //MAIN_CPP_2023_12_21_H
