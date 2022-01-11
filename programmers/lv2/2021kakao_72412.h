//
// Created by jjangchan on 2022/01/11.
// 순위검색
//

#ifndef MAIN_CPP_2021KAKAO_72412_H
#define MAIN_CPP_2021KAKAO_72412_H

#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;
/** 이진법 패턴 풀이
const string ALL = "-";
unordered_map<string, vector<int>> m;

//이진법 패턴이랑 똑같음 따라서, 이진법으로 모든 패턴(경우의수) 추출 가능.
void insert(string* key, int mask, int point) {
    string s = "";
    for (int i = 0; i < 4; i++) {
        s += (mask & (1 << i)) ? ALL : key[i];
    }
    m[s].push_back(point);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string key[4], tmp;
    int point;

    for (auto& inf : info) {
        istringstream iss(inf);
        iss >> key[0] >> key[1] >> key[2] >> key[3] >> point;
        for (int i = 0; i < 16; i++) insert(key, i, point);
    }

    for (auto& m : m) sort(m.second.begin(), m.second.end());

    for (auto& que : query) {
        istringstream iss(que);
        iss >> key[0] >> tmp >> key[1] >> tmp >> key[2] >> tmp >> key[3] >>
            point;
        string s = key[0] + key[1] + key[2] + key[3];
        vector<int>& v = m[s];
        answer.push_back(v.end() - lower_bound(v.begin(), v.end(), point));
    }

    return answer;
}
**/

const string ALL = "-";
unordered_map<string, vector<int>> m;

//이진법 패턴이랑 똑같음 따라서, 이진법으로 모든 패턴(경우의수) 추출 가능.
void insert(string* key, int mask, int point) {
    string s = "";
    for (int i = 0; i < 4; i++) {
        s += (mask & (1 << i)) ? ALL : key[i];
    }
    m[s].push_back(point);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string key[4], tmp;
    int point;

    for (auto& inf : info) {
        istringstream iss(inf);
        iss >> key[0] >> key[1] >> key[2] >> key[3] >> point;
        for (int i = 0; i < 16; i++) insert(key, i, point);
    }

    for (auto& m : m) sort(m.second.begin(), m.second.end());

    for (auto& que : query) {
        istringstream iss(que);
        iss >> key[0] >> tmp >> key[1] >> tmp >> key[2] >> tmp >> key[3] >>
            point;
        string s = key[0] + key[1] + key[2] + key[3];
        vector<int>& v = m[s];
        answer.push_back(v.end() - lower_bound(v.begin(), v.end(), point));
    }

    return answer;
}

#endif //MAIN_CPP_2021KAKAO_72412_H
