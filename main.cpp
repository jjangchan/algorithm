#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>

int N, a, b, size;
std::vector<int> road;
std::vector<std::string> sequence;

std::ostream& operator<<(std::ostream& os, const std::vector<int>& road){
    return os;
}

std::string ToBinary(int n){
    std::string s;
    while(n != 0){
        s += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return s;
}

void Init(){
    scanf("%d", &N);
    a = 1;
    b = N*2;
    scanf("%d", &size);
    std::string init;
    for(int i = 0; i < size; i++){
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        road.push_back(num1+num2);
        init.push_back('0');
    }
    sequence.push_back(init);
    for(int i = std::pow(2, size-1); i < std::pow(2, size); i++){
        sequence.push_back(ToBinary(i));
    }
    for(auto &s : sequence)
        std::cout << s << std::endl;

}

int main(){
    Init();
    return 0;
}