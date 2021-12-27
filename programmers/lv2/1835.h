//
// Created by jjanchan on 2021-12-24.
// 단체사진 찍기
//

#ifndef MAIN_CPP_1835_H
#define MAIN_CPP_1835_H

#include <string>
#include <vector>
#include <algorithm>

/** algorithm(STL) 사용 - 순열(next_permutation)
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {


    vector<char> lst = {'A','C', 'F', 'J' ,'M', 'N', 'R', 'T'};
    int answer = 0;
    do {
        bool flag = false;
        for( auto s : data ) {

            int a = 0;
            int b = 0;
            for( int i=0; i<lst.size(); i++ ) {
                if(lst[i]==s[0]) a=i;
                if(lst[i]==s[2]) b=i;
            }
            int dist = s[4]-'0'+1;
            char var = s[3];

            if(var=='=') {
                flag = abs(a-b)==dist?true: false;
            }
            else if(var=='<') {
                flag = abs(a-b)<dist?true:false;
            }
            else if(var=='>'){
                flag = abs(a-b)>dist?true:false;
            }

            if(!flag) break;

        }

        if(flag) answer++;

    } while(next_permutation(lst.begin(), lst.end()));
    return answer;
}
 **/

using namespace std;

int GetLocation(const char& c){
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'F': return 2;
        case 'J': return 3;
        case 'M': return 4;
        case 'N': return 5;
        case 'R': return 6;
        case 'T': return 7;
    }
}


void LineUp(const std::vector<std::string>& data, bool* is, const std::string& str, const std::string& temp, int& count){
    // 조건 확인
    for(const std::string& d : data){
        if(is[GetLocation(d[0])] + is[GetLocation(d[2])] == 2){
            int gep = d[4] - '0';
            int str_gep = std::abs((int)temp.find(d[0])-(int)temp.find(d[2]))-1;
            if(d[3] == '='){
                if(str_gep != gep) return;
            }else if(d[3] == '>'){
                if(str_gep <= gep) return;
            }else{
                if(str_gep >= gep) return;
            }
        }
    }

    if(temp.size() == str.size()){
        count++;
        return;
    }
    for(int i = 0; i < str.size(); i++){
        if(!is[i]){
            is[i] = true;
            LineUp(data, is, str, temp+str[i], count);
            is[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    std::string str = "ACFJMNRT";
    bool is[8] = {false,};
    LineUp(data, is, str, "", answer);
    return answer;
}

#endif //MAIN_CPP_1835_H
