//
// Created by jjangchan on 2021-08-25.
//

#ifndef ALGORITHM_EX3_2021KAKAOBLIND_H
#define ALGORITHM_EX3_2021KAKAOBLIND_H

using namespace std;

std::vector<std::string> split(std::string str, char delimiter)
{
    std::vector<std::string> answer;
    std::stringstream stream(str);
    std::string result;

    while(std::getline(stream, result, delimiter))
    {
        if(result == "and") continue;
        answer.push_back(result);
    }
    return answer;
}


vector<int> solution(vector<string> info, vector<string> query) {
    std::vector<int> answer;
    std::map<std::string, std::vector<int>> map_data;
    std::vector<char> v[4];

    //info 파싱
    for(std::string data : info)
    {
        std::vector<std::string> result = split(data, ' ');
        std::string key = "";
        for(int i = 0; i < 4; i++){
            key += result[i][0];
            auto iter = find(v[i].begin(), v[i].end(), result[i][0]);
            if(iter == v[i].end())
                v[i].push_back(result[i][0]);
        }
        map_data[key].push_back(std::stoi(result[4]));
    }

    //sort(오름차순)
    for(auto iter = map_data.begin(); iter != map_data.end(); iter++)
        std::sort(iter->second.begin(), iter->second.end());

    // query 파싱
    for(auto i : query)
    {
        std::vector<std::string> split_query = split(i, ' ');
        std::vector<std::string> result(1);
        std::string key = "";
        int count = 0;
        for(int i = 0; i < 4; i++) {
            if(split_query[i] == "-"){
                std::vector<std::string> temp;
                for(auto i : v[i]) for(auto s : result){
                    temp.push_back(s+i);
                }
                result.clear();
                result.resize(temp.size());
                std::copy(temp.begin(), temp.end(), result.begin());
            }
            else
            {
                for(int j = 0; j < result.size(); j++)
                    result[j] += split_query[i][0];
            }
        }

        // 선형탐색 -> 이분탐색
        for(auto s : result)
        {
            auto iter = lower_bound(map_data[s].begin(), map_data[s].end(), std::stoi(split_query[4]));
            count += (map_data[s].size()-(iter - map_data[s].begin()));
        }
        answer.push_back(count);
    }
    return answer;
}
#endif //ALGORITHM_EX3_2021KAKAOBLIND_H
