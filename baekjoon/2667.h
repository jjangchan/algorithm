//
// Created by jjangchan on 2021-09-08.
//

#ifndef ALGORITHM_2667_H
#define ALGORITHM_2667_H

std::map<int, std::pair<int, bool>> m;
std::vector<int> v;
int n;
int v_index = 0;


void DFSRecursion(const int index, const int *d)
{
    m[index].second = true;
    v[v_index]++;
    for(int i = 0; i < 4; i++){
        int new_index = index+d[i];
        bool is_left = (index%n == 0 && d[i] == -1);
        bool is_right = ((index+1)%n == 0 && d[i] == 1);
        if(m.find(new_index) == m.end() || is_left || is_right)
            continue;
        if(!(m[new_index].second) && m[new_index].first == 1)
        {
            DFSRecursion(new_index, d);
        }
    }
}

void Input()
{
    // 2
    // 11
    // 11n b
    std::string line;
    std::getline(std::cin,line);
    n = std::stoi(line);

    // down, up, left, right
    int direction[4] = {+n, -n, -1, 1};


    for(int i = 0; i != n; i++){
        std::getline(std::cin, line);
        for(int j = 0; j != line.size(); j++)
        {
            std::string temp ="";
            temp += line[j];
            m[(i*n)+j].first = std::stoi(temp);
            m[(i*n)+j].second = false;
        }
    }

    auto start = m.begin();
    for(; start != m.end(); start++){
        if(start->second.first == 1 && !start->second.second)
        {
            v.push_back(0);
            DFSRecursion(start->first, direction);
            v_index += 1;
        }
    }

    std::sort(v.begin(), v.end());
    std::cout << v.size() << std::endl;
    for(int i : v){
        std::cout << i << std::endl;
    }
}


#endif //ALGORITHM_2667_H
