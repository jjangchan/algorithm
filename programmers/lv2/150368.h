//
// Created by jjangchan on 2023/08/03.
// kakao - 이모티콘 할인행사
//

#ifndef MAIN_CPP_150368_H
#define MAIN_CPP_150368_H

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    double discount[4] = {0.9, 0.8, 0.7, 0.6};
    int discount_cnt[4] = {0,0,0,0};
    for(const std::vector<int>& v : users){
        for(int i = 0; i < 4; i++){
            int a = std::round((1.0-discount[i])*100.0);
            if(a >= v[0]) discount_cnt[i]++; // -- (1)
        }
    }
    std::vector<double> v_discount;
    std::stack<std::string> go;
    for(int i = 0; i < 4; i++) if(discount_cnt[i]) v_discount.push_back(discount[i]); // -- (2)
    for(int i = 0; i < v_discount.size(); i++) go.push(std::to_string(i));
    std::vector<std::vector<int>> result(v_discount.size()+1);
    int max_size = 0;

    while(!go.empty()){ // -- (3)
        std::string str = go.top();
        go.pop();
        if(str.size() == emoticons.size()){ // -- (4)
            std::cout << str << std::endl;
            int plus_cnt = 0, buy = 0;
            for(const std::vector<int>& v : users){
                int total = 0;
                for(int i = 0; i < str.size(); i++){
                    int a = std::round((1.0-v_discount[str[i]-'0'])*100.0);
                    std::cout << a << " ";
                    if(a >= v[0]) total += (std::round(emoticons[i]*v_discount[str[i]-'0'])); // -- (5)
                }
                if(total >= v[1]) plus_cnt++; // -- (6)
                else buy += total; // -- (7)
            }
            std::cout << std::endl;
            std::cout << plus_cnt << "," << buy << std::endl;
            std::cout << "=============================" << std::endl;
            result[plus_cnt].push_back(buy); // -- (8)
            max_size = std::max(max_size, plus_cnt); // -- (9)
        } else for(int i = 0; i < v_discount.size(); i++) go.push( str+std::to_string(i));
    }

    std::sort(result[max_size].begin(), result[max_size].end(), greater<>()); // -- (10)
    for(int i : result[max_size]){
        std::cout << i << " ";
    }
    return {max_size, result[max_size][0]};
}

/**
 * 이모트콘을 주어진 할인 비율에 모든 경우의 수를 구하는 문제이다.
 * s(할인 비율에 개수)는 e(이모티콘 개수)로 정의하면 경우의수는 -> s^e
 * 따라서, 최악의 경우의 수는 4^7 = 16384
 *
 * (1) - 모든 users[비율, 가격]들은 비율 이상에 할인율이 적용 되므로,
 *       모든 유저가 적용되는 할인율(10%, 20%, 30%, 40%)을 카운팅 한다.
 * (2) - 카운팅 된 숫자가 있으면 적용되는 할인율 이므로 경우의 수를 구하기 위해 벡터에 보관
 * (3) - 모든 경우의 수를 계산할 때 재귀 사용시 메모리가 부족하면 call stack frame overflow가 발생할 수 있으므로, 스택 사용
 *
 * [스택을 활용한 모든 경우의 수 구하는 예시] s(3) e(2) -> 3^2 = 9
 *
 * 1st. push(0, 1, 2) ->
 * 2st. pop(2), push(20, 21, 22) -> 3st. pop(22, 21, 20) ->
 * 4st. pop(1), push(10, 11, 12) -> 5st. pop(12, 11, 10) ->
 * 6st. pop(0), push(00, 01, 02) -> 7st. pop(02, 01, 00) -> empty(end)
 *
 * (4) - 3,5,7 st는 e 만큼 경우의 수를 구해서 더이상 스택에 push하지 않고 서비스 가입자 와 판매액을 계산한다.
 * (5) - for문을 돌면서 i번째 유저에 비율 이상에 할인율을 받는 이모티콘 금액들을 누적한다.
 * (6) - 누적된 금액 total이 유저에 가격보다 높으면 서비스 가입자 이므로 plus_cnt를 1 증감
 * (7) - 낮으면 이모티콘 판매액을 누적
 * (8) - 해당하는 경우의 수에, 서비스 가입자 수와 판매액을 2차원 벡테에 보관한다.
 * (9) - 서비스 가입자 수를 최대한 늘리는게 우선 목표 이므로 plus_cnt에 max값을 계산한다.
 * (10) - 모든 계산이 끝나면, 최대한 서비스 가입자를 늘린 수에 판매액이 제일 높은 금액을 구하기 위해 내림차순으로 정렬한다.
 */

#endif //MAIN_CPP_150368_H
