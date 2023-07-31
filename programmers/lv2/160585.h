//
// Created by jjangchan on 2023/07/27.
// 혼자서 하는 틱택토 - 160585
//

#ifndef MAIN_CPP_160585_H
#define MAIN_CPP_160585_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cnt_o[8];
int cnt_x[8];
int back_cnt = 0, front_cnt = 0;

int check(int* a,int * b, int flag){
    int b_cnt = 0;
    for(int i = 0; i <= 7; i++) if(b[i] >= 3) b_cnt++;
    for(int i = 0; i <= 7; i++){
        if(a[i] >= 3){
            if(b_cnt >= 1) return 1; // -- (3)
            if(flag && front_cnt-1 != back_cnt) { // -- (4)
                return 1;
            }
            if(!flag && front_cnt != back_cnt) { // -- (5)
                return 1;
            }
        }
    }
    return 0;
}

int solution(vector<string> board) {
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++){ // -- (1)
        if(board[i][j] == 'O'){
            front_cnt++, cnt_o[3+j]++, cnt_o[i]++;
            if(i == j) cnt_o[6]++;
            if(i+j == 2) cnt_o[7]++;
        }
        if(board[i][j] == 'X'){
            back_cnt++, cnt_x[3+j]++, cnt_x[i]++;
            if(i == j) cnt_x[6]++;
            if(i+j == 2) cnt_x[7]++;
        }
    }
    if(back_cnt > front_cnt || front_cnt-back_cnt >= 2) return 0; // -- (2)
    if(check(cnt_o, cnt_x, 1)) return 0;
    if(check(cnt_x, cnt_o, 0)) return 0;
    return 1;
}

/**
 * for문을 돌면서 필요한 변수들에 값들을 저장한다.
 * (1) -- front_cnt -> 선공(O)에 횟수, back_cnt -> 후공(X)에 횟수
 *        cnt[0 or 1 or 2] -> 각 행에 포함되어 있는 O or X에 수 (행 빙고)
 *        cnt[3 or 4 or 5] -> 각 열에 포함되어 있는 O or X에 수 (열 빙고)
 *        cnt[6] -> 대각선에 포함되어 있는 O or X 에 수(대각선 빙고)
 *        cnt[7] 역 대각선에 포함되어 있는 O or X에 수 (역 대각선 빙고)
 *
 * 규칙이 잘 지킨 틱택토는 다음 조건을 만족해야 한다.
 * (2) -- front_cnt는 back_cnt랑 같거나 1이 많아야 한다.
 * (3) -- 둘이 같이 빙고가 나올수 없다.
 * (4) -- 선공이 빙고가 나오면 front_cnt-1 은 back_cnt 와 같아야 한다.
 * (5) -- 후공이 빙고가 나오면 front_cnt 와 back_cnt는 같아야 한다.
 */

#endif //MAIN_CPP_160585_H
