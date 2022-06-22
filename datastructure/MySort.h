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
    int second_pointer = begin;
    for(int i = begin+1; i < end; i++){
        if(data[i]*x <= data[end]*x){
            T temp = data[i];
            data[i] = data[second_pointer], data[second_pointer++] = temp;
        }
    }
    T temp = data[end];
    data[end] = data[second_pointer], data[second_pointer] = temp;
    return second_pointer;
}

template <typename T>
void quick_sort(std::vector<T>& data, int begin, int end, bool asc = true){
    if(begin < end){
        int x = (asc) ? 1 : -1;
        int position = get_quick_position(data, begin, end, x);
        quick_sort(data, begin, position-1, asc); // left pivot
        quick_sort(data, position+1, end, asc); // right pivot
    }
}

// {3, 1, 5, 2, 10} -> 1st {1, 3, 5, 2, 10}

#endif //MAIN_CPP_MYSORT_H
