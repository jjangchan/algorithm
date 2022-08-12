//
// Created by jjangchan on 2022/08/03.
//

#ifndef MAIN_CPP_MYHASHMAP_H
#define MAIN_CPP_MYHASHMAP_H

#include "MyLinkedList.h"

#include <string>
#include <vector>
#include <type_traits>

template <typename K, typename V>
class HashMap{
private:
    static int const max_list_count = 5;
    linkedlist::MyLinkedList<K,V> *list[max_list_count];
public:
    class Iterator{
    private:
        std::vector<std::pair<K,V>> data;
        int size;
        int index;
    public:
        Iterator(std::vector<std::pair<K,V>>& _data, int _size) : size(_size){
            data = _data; // deep copy
            index = 0;
        }
        Iterator(const Iterator& iter) : size(iter.size){
            data = iter.data; // deep copy
            index = iter.index;
        }

        Iterator& operator=(const Iterator& iter){
            data = iter.data; // deep copy
            index = iter.index;
            size = iter.size;
            return (*this);
        }
        Iterator(int _size) : size(_size){}
        Iterator(){}

        ~Iterator(){}

        Iterator& operator++(){
            index++;
            return (*this);
        }

        K get_key(){
            return data[index].first;
        }

        V get_value(){
            return data[index].second;
        }


        bool operator!=(const Iterator& iter){
            return (iter.size != index);
        }



    };
    friend Iterator;
    HashMap(){
        for(int i = 0; i < max_list_count; i++)
            list[i] = new linkedlist::MyLinkedList<K,V>();
    }
    ~HashMap(){
        for(int i = 0; i < max_list_count; i++)
            delete list[i];
    }

public:
    void put(K key, V value) {
        int code = this->hash(key);
        linkedlist::Node<K, V>* node = list[code]->get_head();
        node = find_key(key, node);

        // key is contain
        if (node != nullptr) {
            node->value = value;
        }
        else {
            list[code]->add(key, value);
        }
    }

    V get(K key) {
        int code = hash(key);
        linkedlist::Node<K,V>* node = list[code]->get_head();
        node = find_key(key, node);
        return node->value;
    }

    Iterator begin(){
        std::vector<std::pair<K,V>> data;
        for(int i = 0; i < max_list_count; i++){
            list[i]->get_key_value(data);
        }
        Iterator temp(data, data.size());
        return temp;
    }

    Iterator end(){
        int size =0;
        for(int i = 0; i < 5; i++)
            size += list[i]->length();
        Iterator temp(size);
        return temp;
    }

private:
    int hash(K key){
        int hash_value = -1;
        int cal = 0;
        if constexpr(std::is_same_v<K, int>){
            cal = key;
        }else {
            for(char c : key) cal += static_cast<int>(c);
        }
        hash_value = cal % max_list_count;
        return hash_value;
    }

    linkedlist::Node<K, V>* find_key(K key, linkedlist::Node<K,V>* current){
        linkedlist::Node<K, V>* node = current;
        while(node != nullptr){
            if(node->key == key) break;
            node = node->next;
        }
        return node;
    }
};

#endif //MAIN_CPP_MYHASHMAP_H
