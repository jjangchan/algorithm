#include <iostream>

struct Star{
    int x;
    int y;
    Star(int _x, int _y):x(_x),y(_y){}
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
    std::cin >> a >> b;
    Star s(a,b);

    std::cout << s;
    return 0;
}