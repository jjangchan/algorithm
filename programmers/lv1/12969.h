//
// Created by jjangchan on 2021-12-14.
//

#ifndef MAIN_CPP_12969_H
#define MAIN_CPP_12969_H

#include <iostream>

using namespace std;

struct Star{
    int x;
    int y;
    Star(int _x, int _y):x(_y),y(_y){}
};

std::ostream& operator<<(std::ostream& os, const Star& s){
    for(int i = 0; i < s.y; i++){
        for(int j = 0; j < s.x; j++) std::cout << "*";
        std::cout << std::endl;
    }

}

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    Star s(a,b);

    cout << s;
    return 0;
}

#endif //MAIN_CPP_12969_H
