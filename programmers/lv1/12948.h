//
// Created by jjangchan on 2021-12-16.
// 핸드폰 번호 가리기
//

#ifndef MAIN_CPP_12948_H
#define MAIN_CPP_12948_H

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    phone_number.replace(phone_number.begin(), phone_number.end()-4, phone_number.size()-4,'*');
    return phone_number;
}

#endif //MAIN_CPP_12948_H
