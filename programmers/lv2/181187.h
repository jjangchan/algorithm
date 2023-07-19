//
// Created by jjangchan on 2023/07/17.
//

#ifndef MAIN_CPP_181187_H
#define MAIN_CPP_181187_H

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long y = (r2-r1+1)*4, x = 0;

    for(int i = 1; i < r2; i++){
        long double b = sqrt((long double)pow((long double)r2,2)-(long double)pow((long double)i,2));
        long long cal = (long long)b; // -- (1)
        if(i < r1){ // -- (2)
            long double a = sqrt((long double)pow((long double)r1,2)-(long double)pow((long double)i,2));
            cal = (long long)b - (long long)a;
            if((long long)a == a) cal += (long long)1;
        }
        x += cal; // -- (3)
    }
    return y+(x*4); // -- (4)
}

/**
 * 두 원에 바깥 쪽으로 겹치는 좌표는 원의 방정식 x^2+y^2 = r^2 과 원에 사분면에 대칭성을 활용한다.
 * 음이 아닌 y축 기준으로 루프(1 <= a <= r2)를 돌면서 x = sqrt(r^2-y^2) 에 좌표를 구해 계산하면 된다.
 * y 축 좌표가 안쪽 원에 반지름 보다
 * (1) 같거나 크면 바같쪽 원 x좌표를 소수점 버리고 0 사이에 좌표 개수를 구하고 (x-0+1)
 * (2) 작으면 바같쪽 원에 소수점 버린 x1 좌표와 안쪽 원에 소수점 올린 x2 좌표에 개수를 구해서 (x1-x2+1)
 * (3) 구한 개수를 계속 누적 한 다음에
 * (4) 원에 대칭성을 이용해 누적된 개수를 4배 해주면 된다.
 *
 * <-- 가독성 좋은 풀이 -->
 * long long solution(int r1, int r2) {
    long long answer = 0;

    for (int t = 1; t <= r2; ++t)
    {
        int h2 = floor(sqrt(pow(r2,2)-pow(t,2)));
        int h1 = (t < r1)?ceil(sqrt(pow(r1,2)-pow(t,2))):0;
        answer += h2-h1 + 1;
    }
    return 4*answer;
}
 */

#endif //MAIN_CPP_181187_H
