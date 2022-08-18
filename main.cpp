#include <vector>
#include <string>
#include <iostream>
#include <cmath>

// 브루트 포스
int move_count(const int target, const int size, std::string name){
    int index = 0, x = 1, count = 0;
    for(int i = 0; i < size; i++){
        x = (target & (1 << i)) ? 1 : -1;
        while(true){
            count++;
            index = (name.size()+index+x)%name.size();
            if(name[index] != 'A') {
                name[index] = 'A';
                break;
            }
        }
    }
    return count;
}

int main() {
    std::string name = "BBBBAAAABA";
    int sum = 0, step = 0;
    for(int i = 0; i < name.size(); i++){
        int up = name[i] -'A';
        int down = 91- name[i];
        sum += (up < down) ? up : down;
        if(i != 0 && name[i] != 'A') step++;
    }
    name[0] = 'A';
    int min = move_count(0, step, name);
    for(int i = 1; i < std::pow(2, step); i++){
        min = std::min(min,move_count(i, step, name));
    }
    return sum+min;
}
