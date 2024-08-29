//
// Created by jjangchan on 2022/05/21.
//

#ifndef MAIN_CPP_MYSORT_H
#define MAIN_CPP_MYSORT_H

#include <vector>
#include <iostream>

template <typename T>
void insert_sort(T* data, int start, int end, bool asc = true){
    int x = asc ? 1 : -1;
    for(int i = start; i != end-1; i++){
        int min_index = i;
        for(int j = i+1; j != end; j++){
            if(data[min_index]*x > data[j]*x) min_index = j;
        }
        T temp = data[min_index];
        data[min_index] = data[i];
        data[i] = temp;
    }
}

template<typename T, typename Comp>
void insertion_sort(T begin, T end,
                    Comp __comp){
    int size = (end-begin);
    int i = 1;
    while(i < size){
        int j = 0, a = *(begin+i);
        bool is_comp = false;
        while(j <= i){
            int b = *(begin+j);
            if(is_comp) *(begin+j) = a, a = b;
            else if(__comp(a, b)){
                is_comp = true;
                *(begin+j) = a, a = b;
            }
            j++;
        }
        i++;
    }
}

template <typename T>
void selection_sort(T* data, int start, int end, bool asc = true){
    int x = asc ? 1: -1;
    for(int i = start+1; i != end; i++){
        int back = i-1;
        T key = data[i];
        while (back >= 0 && key*x < data[back]*x){
            data[back+1] = data[back];
            back -= 1;
        }
        data[back+1] = key;
    }
}

template<typename T, typename Comp>
void select_sort(T begin, T end,
                 Comp __comp){
    T start = begin, last = (end-1);
    int index = 0;
    while(start != last){
        T s_start = (start+1);
        int a = *start, comp_index = index+1, is = 0;
        while(s_start != end){
            if(!__comp(a, *s_start)){
                a = *s_start;
                is = comp_index;
            }
            s_start++, comp_index++;
        }
        if(is){
            *(begin+is) = *start;
            *start = a;
        }
        start++, index++;
    }
}

template <typename T>
void bubble_sort(T* data, int start, int end, bool asc = true){
   int x = (asc) ? 1 : -1;
   for(int i = end-1; i != start; i--) for(int j = start; j != i; j++){
       if(data[j]*x > data[j+1]*x){
           T temp = data[j];
           data[j] = data[j+1];
           data[j+1] = temp;
       }
   }
}

template<typename T, typename Comp>
void bubble_sort(T begin, T end,
                 Comp __comp){
    int size = end-begin;
    while(size){
        int i = 1;
        while(i < size){
            int a = *(begin+i), b = *(begin+(i-1));
            if(__comp(a, b)) *(begin+i) = b, *(begin+(i-1)) = a;
            i++;
        }
        size--;
    }
}

template<typename T, typename Comp>
void heap_sort(T begin, T end,
               Comp __comp){
    int size (end-begin), len = size;

    // heap 배열 생성
    std::vector<int> heap_array(size+1);
    int i = 1;
    while(i <= size){
        heap_array[i] = *(begin+(i-1));
        int swap_var = heap_array[i], swap_index = i;
        while(swap_index/2 && __comp(heap_array[swap_index/2], swap_var)){
            heap_array[swap_index] = heap_array[swap_index/2];
            heap_array[swap_index/2] = swap_var;
            swap_index /= 2;
        }
        i++;
    }

    for(int i : heap_array) std::cout << i <<  " ";
    std::cout << std::endl;

    // heap 정렬
    while(--len >= 2){
        *(begin+len) = heap_array[1];
        heap_array[1] = heap_array[len+1];
        int swap_var = heap_array[1], swap_index = 1;
        while(swap_index*2 <= len+1){
            bool left = __comp(swap_var, heap_array[swap_index*2]);
            bool right = swap_index*2+1 <= len+1 && __comp(swap_var, heap_array[swap_index*2+1]);

            if(!left && !right) break;
            if(left && right) left = __comp(heap_array[swap_index*2+1], heap_array[swap_index*2]);

            if(left){
                heap_array[swap_index] = heap_array[swap_index*2];
                heap_array[swap_index*2] = swap_var;
                swap_index *= 2;
            }else{
                heap_array[swap_index] = heap_array[swap_index*2+1];
                heap_array[swap_index*2+1] = swap_var;
                swap_index = swap_index*2+1;
            }
        }
    }
    *(begin+1) = heap_array[1], *begin = heap_array[2];
}


template <typename T>
std::ostream &operator<<(std::ostream& os, std::vector<T> data){
    os << " [ ";
    for(T d : data) os << d << " ";
    os << "] " << std::endl;
    return os;
}

template <typename T>
void merge_sort(std::vector<T> &data, bool asc = true){
    if(data.size() <= 1) return;
    int center = data.size()/2;
    std::vector<T> l_data(data.begin(), data.begin()+center);
    std::vector<T> r_data(data.begin()+center, data.end());

    merge_sort(l_data, asc);
    merge_sort(r_data, asc);

    /**
    std::cout << "(source)" << data;
    std::cout << "(left)" << l_data;
    std::cout << "(right)" << r_data;
    **/

    int s_index, l_index, r_index;
    int x = (asc) ? 1 : -1;
    s_index = 0, l_index = 0, r_index = 0;
    while(l_index < l_data.size() && r_index < r_data.size()){
        if(l_data[l_index]*x < r_data[r_index]*x){
           data[s_index] = l_data[l_index];
           l_index++;
        }else{
            data[s_index] = r_data[r_index];
           r_index++;
        }
        s_index++;
    }

    std::vector<T> &temp = (l_index < l_data.size()) ? l_data : r_data;
    for(int i = (l_index < l_data.size()) ? l_index : r_index; i < temp.size(); i++, s_index++)
        data[s_index] = temp[i];
}

template <typename T>
int get_quick_position(std::vector<T> &data, int begin, int end, int x){
    int second_pointer = begin-1;
    for(int i = begin; i < end; i++){
        if(data[i]*x <= data[end]*x){
            T temp = data[i];
            data[i] = data[++second_pointer], data[second_pointer] = temp;
        }
    }
    T temp = data[end];
    data[end] = data[++second_pointer], data[second_pointer] = temp;
    return second_pointer;
}

template <typename T>
void quick_sort(std::vector<T>& data, int begin, int end, bool asc = true){
    if(begin < end){
        int x = (asc) ? 1 : -1;
        int position = get_quick_position(data, begin, end, x);
        std::cout << "(" << position << ") ";
        for(auto d : data)
            std::cout << d << " ";
        std::cout << std::endl;
        quick_sort(data, begin, position-1, asc); // left pivot
        quick_sort(data, position+1, end, asc); // right pivot
    }
}

template<typename T, typename Comp>
int quick_sort_partition(T begin, T end, int left, int right,
                         Comp __comp) {
    int p = *(begin+left);
    int low = left+1, high = right;
    while(low < high){
        while(__comp(*(begin+low), p)) low++;
        while(__comp(p, *(begin+high))) high--;
        if(low < high){
            int temp = *(begin+high);
            *(begin+high) = *(begin+low), *(begin+low) = temp;
        }
    }
    *(begin+left) = *(begin+high), *(begin+high) = p;
    return high;
}

template<typename T, typename Comp>
void op_quick_sort(T begin, T end, int left, int right,
                   Comp __comp){
    if(left < right){
        int pivot = quick_sort_partition(begin, end, left, right, __comp);
        std::cout << pivot << " ) ";
        int size = end-begin;
        for(int i = 0; i < size; i++) std::cout << *(begin+i) << " ";
        std::cout << std::endl;
        op_quick_sort(begin, end, left, pivot-1, __comp);
        op_quick_sort(begin, end, pivot+1, right, __comp);
    }
}

template<typename T, typename Comp>
void quick_sort(T begin, T end,
                Comp __comp){
    int size = end-begin;
    op_quick_sort(begin, end, 0, size-1, __comp);
}

// {3, 1, 5, 2, 10} -> 1st {1, 3, 5, 2, 10}

#endif //MAIN_CPP_MYSORT_H
