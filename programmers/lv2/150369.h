//
// Created by jjangchan on 2023/08/02.
// 택배 배달과 수거하기
//

#ifndef MAIN_CPP_150369_H
#define MAIN_CPP_150369_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0, deli_cnt = 0, pick_cnt = 0;
    for(int i = n-1; i >= 0; i--){ // -- (1)
        deli_cnt -= deliveries[i];
        pick_cnt -= pickups[i];
        std::cout << deli_cnt << "," << pick_cnt << std::endl;
        if(deli_cnt < 0 || pick_cnt < 0){ // -- (2)
            long long weight = std::max(deli_cnt*-1, pick_cnt*-1); // -- (3)
            weight = (weight%cap) ? weight/cap+1 : weight/cap; // -- (4)
            std::cout << "weight >> " << weight << std::endl;
            deli_cnt += weight*cap;
            pick_cnt += weight*cap;
            std::cout << "after >> " << deli_cnt << " , " << pick_cnt << std::endl;
            answer += (weight*(i+1)*2); // -- (5)
            std::cout << "answer >> " << answer << std::endl;
        }
        std::cout << "================================================" << std::endl;
    }
    std::cout << answer << std::endl;
    return answer;
}

/**
 * 택배를 배달 하거나 수거할 때 최소 이동거리를 구하려면 최대한 먼 곳 부터 배달을 하거나 수거 해야 한다.
 * 왜냐하면, 먼 곳에 수거량이 많으면 가면서 배달을 하거나 배달량이 많으면 오면서 수거를 하기 떄문이다.
 *
 * (1) - for문을 맨 뒤에서 부터 시작
 * (2) - 누적된 수거(pick_cnt) 또는 배달(deli_cnt) 짐이 음수이면 해당 지역을 갔다 오고,
 *       둘다 양수이면 적재된 짐이 있으므로 갔다 오지 않아도 된다.
 * (3) - 실을수 있는 물량이 cap으로 제한되어 있어서 몇번을 갔다 와야 할지 정해야 하므로 max로 기준값을 정한다.
 * (4) - 기준값(weight)이 cap에 나누어 떨어지면 나눈 몫 만 가도 되고, 안 떨어지면 한번 더 가야 하므로 +1 를 해준다.
 * (5) - 짐을 가져 왔으므로 deli_cnt, pick_cnt에 누적 하고, 갔다가 되돌아온 거리를 더해준다.
 *
 * 되돌아오는 거리 까지 미리 더해주는 이유는 예시로,
 * deliveries(0,0,0,4), pickups(1,2,1,0), cap 이 4이면
 * i = 3 먼저 검증하면, deli_cnt(-4), pick_cnt(0) 이므로 한번 지역을 갔다 오면,
 * deli_cnt(0), pick_cnt(4)로 수량이 누적 되므로 i = 2, 1, 0 은 pick_cnt 에 누적 수량으로 해결 된다.
 * 결론적으로 미리 되돌아오는 거리를 누적합 해서 앞에 일을 해결할 수 있다.
 *
 */

#endif //MAIN_CPP_150369_H
