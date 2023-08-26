//
// Created by jjangchan on 2023/08/22.
// kakao - 양궁대회
//

#ifndef MAIN_CPP_92342_H
#define MAIN_CPP_92342_H

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer = {-1};
    int max_score = 0;
    for(int i = 1; i < 2047; i++){
        int cal_n = n, a_score = 0, r_score = 0;
        std::vector<int> scores(11, 0);
        for(int j = 0; j < 11; j++){
            if(i & (1<<j)){
                int cal = (info[j]+1 >= cal_n) ? cal_n : info[j]+1;
                scores[j] = cal;
                cal_n -= cal;
            }
            if(info[j] || scores[j]){
                if(scores[j] > info[j]) r_score += (10-j);
                else a_score += (10-j);
            }
        }

        if(cal_n == 0){
            int total = r_score-a_score;
            if(total > max_score){
                max_score = total;
                answer = scores;
            }else if(total == max_score){
                for(int j = 10; j >= 0; j--){
                    if(scores[j] > answer[j]){
                        answer = scores;
                        break;
                    }else if(answer[j] > scores[j]) break;
                }
            }
        }
    }
    return answer;
}

#endif //MAIN_CPP_92342_H
