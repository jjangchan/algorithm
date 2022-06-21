#include "datastructure/MySort.h"

int main() {
    std::vector<int> v = {1,10, 0, 200000, 12,20, 100, 32};
    merge_sort(v, false);

    for(auto d : v){
      std::cout << d << " ";
    }
    return 0;
}