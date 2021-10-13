#include <iostream>
#include <vector>

int main(){
    int* arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    int* new_arr = arr;
    std::cout << new_arr << std::endl;
    std::cout << &arr[0] << std::endl;

    return 0;
}






