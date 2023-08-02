//
// Created by jjangchan on 2023/07/31.
// 155651 - 호텔 대실
//

#ifndef MAIN_CPP_155651_H
#define MAIN_CPP_155651_H

/**
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int string_to_time(const std::string& time){
    return std::stoi(time.substr(0,2))*60+std::stoi(time.substr(3));
}

int solution(vector<vector<string>> book_time) {
    std::sort(book_time.begin(), book_time.end(), [](const std::vector<std::string>& a, const std::vector<std::string> b)-> bool{
        if(string_to_time(a[0]) == string_to_time(b[0])) return string_to_time(a[1]) < string_to_time(b[1]);
        return string_to_time(a[0]) < string_to_time(b[0]);
    });

    std::vector<std::vector<int>> answer = {{string_to_time(book_time[0][1])}};

    for(int i = 1; i < book_time.size(); i++) {
        int last_push = 1;
        for(int j = 0; j < answer.size(); j++){
            if(answer[j][answer[j].size()-1]+10 <= string_to_time(book_time[i][0])){
                answer[j].push_back(string_to_time(book_time[i][1]));
                last_push = 0;
                break;
            }
        }
        if(last_push) answer.push_back({string_to_time(book_time[i][1])});

    }


    return answer.size();
}
 **/

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    sort(book_time.begin(), book_time.end());

    for(auto& v : book_time){
        std::cout << v[0] << " , "  << v[1] << std::endl;
    }

    for (int i = 0; i < book_time.size(); i++) {
        string st = book_time[i][0];
        string ed = book_time[i][1];
        int stT = stoi(st.substr(0, 2)) * 60 + stoi(st.substr(3));
        int edT = stoi(ed.substr(0, 2)) * 60 + stoi(ed.substr(3)) + 10;
        while (!q.empty() && q.top() <= stT) {
            q.pop();
        }
        q.push(edT);
        answer = max(answer, (int)q.size());
    }
    return answer;
}


#endif //MAIN_CPP_155651_H
