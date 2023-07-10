//
// Created by jjangchan on 2023/07/04.
// 달리기 경주 - 178871
//

#ifndef MAIN_CPP_178871_H
#define MAIN_CPP_178871_H

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    std::map<std::string, int> m;
    for(int i = 0; i < players.size(); i++) m.insert({players[i], i});
    for(std::string& call : callings){
        int num = m[call]--;
        std::string swap_name = players[num-1];
        players[num] = swap_name;
        players[num-1] = call;
        m[swap_name]++;
    }
    vector<string> answer(players.begin(), players.end());
    return answer;
}
/**
 * 이중 for 문을 돌면 n^2 으로 시간 초과가 된다.
 * 따라서,
 * map 자료구조로 key에 선수명 value에 현재 순서를 저장해서
 * 추월 당한 선수는 vector로 가져오고,
 * 변경헤야할 내용(추월한 선수, 추월 당한 선수)을 두개의 자료구조를 변경하면서 동기화 시켜주면서 해결 한다.
 */

#endif //MAIN_CPP_178871_H
