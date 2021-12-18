//
// Created by jjangchan on 2021-12-13.
//

#ifndef MAIN_CPP_17681_H
#define MAIN_CPP_17681_H
#include <string>
#include <vector>

using namespace std;

/** 비트 연산자
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i <n; i++){
        arr1[i] = arr1[i]|arr2[i];
        string ans = "";
        for(int j = 0; j<n; j++){
            if(arr1[i] % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
    return answer;
}
**/

std::string Decoding(int code, const int n){
    std::string str = "";
    while(code){
        str = ((code%2) ? "#" : " ") + str;
        code /= 2;
    }
    for(int i = str.size(); i < n; i++) str = ' '+str;
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        int or_bit = (arr1[i] | arr2[i]);
        answer.push_back(Decoding(or_bit, n));
    }
    return answer;
}

#endif //MAIN_CPP_17681_H
