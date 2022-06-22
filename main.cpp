#include "datastructure/MySort.h"

int main() {
    std::vector<int> v = {8,9, 10, 11,2, 1, 3};
    quick_sort(v, 0, v.size()-1);
    for(auto d : v) std::cout << d << " ";
    return 0;
}