//
// Created by jjangchan on 2022/04/01.
//

#ifndef MAIN_CPP_MYLINKEDLIST_H
#define MAIN_CPP_MYLINKEDLIST_H

#include <iostream>
#include <vector>

namespace linkedlist {
    template<typename K, typename V>
    class Node {
    public:
        K key;
        V value;
        Node<K, V>* next;
        Node(K _key, V _value) : key(_key), value(_value), next(nullptr){}
    };

    template<typename K, typename V>
    class MyLinkedList {
    private:
        int size = 0;
        Node<K,V>* head  = nullptr;
    public:
        MyLinkedList(){}
        ~MyLinkedList(){
            while(head != nullptr){
                Node<K,V> *current_node = head;
                head = current_node->next;
                delete current_node;
            }
        }

        void add(K key, V value){
            if(head == nullptr){
                head = new Node<K,V>(key, value);
            }else{
                Node<K,V> *current = head;
                while(current->next != nullptr){ current = current->next;}
                current->next = new Node<K,V>(key, value);
            }
            size++;
        }

        void get_key_value(std::vector<std::pair<K,V>>& v){
            Node<K, V>* n = this->head;
            while(n!= nullptr){
                v.push_back({n->key, n->value});
                n = n->next;
            }
        }

        V get(const K& key) {
            Node<K, V>* cursor = this->head;
            while (cursor->key != key) {
                cursor = cursor->next;
            }
            return cursor->value;
        }

        int length() const{ return this->size; }
        Node<K,V>* get_head(){return head;};
    };
}
#endif //MAIN_CPP_MYLINKEDLIST_H
