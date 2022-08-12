//
// Created by jjangchan on 2022/08/04.
//

#ifndef MAIN_CPP_MYSET_H
#define MAIN_CPP_MYSET_H

namespace SET {
    template<typename T>
    struct Node {
    private:
        T data;
        Node *left;
        Node *right;
    public:
        Node(T _data, Node *_left, Node *_right) {
            data = _data;
            left = _left;
            right = _right;
        }

        ~Node() {}

        T get_data() {
            return data;
        }

        void set_data(T _data) {
            data = _data;
        }

        Node *get_left() {
            return left;
        }

        void set_left(Node *_left) {
            left = _left;
        }

        Node *get_right() {
            return right;
        }

        void set_right(Node *_right) {
            right = _right;
        }

        // is leaf node?
        bool is_leaf() {
            return left == nullptr && right == nullptr;
        }
    };

    template<typename T>
    class BinaryTree {
    private:
        Node<T> *root;
    public:
        BinaryTree() {
            root = nullptr;
        }

        ~BinaryTree() {}

        // set root node
        void set_root(Node<T> *_root) {
            root = _root;
        }

        // get root node
        Node<T> *get_root() {
            return root;
        }

        // 중위 순회(In-order Traversal)
        void inorder(T* data) {
            int i = 0;
            inorder(root, data, i);
        }

        void inorder(Node<T> *node, T* data, int& index) {
            if (node != nullptr) {
                inorder(node->get_left(), data, index);
                *(data+index) = node->get_data();
                index++;
                inorder(node->get_right(), data, index);
            }
        }

        // 전체 노드 개수 구하기
        int length() {
            return is_empty() ? 0 : length(root);
        }

        int length(Node<T> *node) {
            if (node == nullptr) return 0;
            return 1 + length(node->get_left()) + length(node->get_right());
        }

        bool is_empty() {
            return root == nullptr;
        }

    };

// set(이진탐색트리) (이진트리 상속)
    template<typename T>
    class Set : protected BinaryTree<T> {
    public:

        class Iterator{
        private:
            T* data;
            int size;
            int index;
        public:
            Iterator(T* _data, int _size) : size(_size){
                data = new T[size];
                for(int i = 0; i < size; i++) data[i] = _data[i];
                index = 0;
            }
            Iterator(const Iterator& iter) : size(iter.size){
                data = new T[size];
                for(int i = 0; i < size; i++) data[i] = iter.data[i];
                index = iter.index;
            }

            Iterator& operator=(const Iterator& iter){
                data = new T[iter.size];
                for(int i = 0; i < iter.size; i++) { data[i] = iter.data[i];}
                index = iter.index;
                size = iter.size;
                return (*this);
            }
            Iterator(int _size) : data(nullptr), size(_size){}
            Iterator(){}

            ~Iterator(){
                if(data != nullptr){
                    delete[] data;
                    data = nullptr;
                }
            }

            Iterator& operator++(){
                index++;
                return (*this);
            }

            T operator*(){
                return *(data+index);
            }

            bool operator!=(const Iterator& iter){
                return (iter.size != index);
            }



        };

        friend Iterator;
        Set() {}
        ~Set() {}

        Iterator begin(){
            T* data = new T[this->length()];
            this->inorder(data);
            Iterator temp(data, this->length());
            delete[] data;
            return temp;
        }

        Iterator end(){
            Iterator temp(this->length());
            return temp;
        }

        // 탐색
        Node<T> *search(T key) {
            return searchIter(this->get_root(), key);
        }

        // 삽입
        void insert(T key) {
            if (this->is_empty()) {
                Node<T> *node = new Node<T>(key, nullptr, nullptr);  // 새로운 key를 가지는 node 생성
                this->set_root(node);
            } else {
                insert_recur(this->get_root(), key);
            }
        }

    private:
        // 탐색 (반복)
        Node<T> *searchIter(Node<T> *node, T key) {
            while (node != nullptr) {
                if (key == node->get_data()) return node;     // key == root 노드의 data
                else if (key < node->get_data()) node = node->get_left();   // key < root 노드의 data
                else if (key > node->get_data()) node = node->get_right();  // key > root 노드의 data
            }
            return nullptr;    // 탐색이 실패한 경우 NULL 반환
        }

        // 삽입 (순환)
        void insert_recur(Node<T> *node, T key) {
            Node<T> *newNode = new Node<T>(key, nullptr, nullptr);  // 새로운 key를 가지는 node 생성

            if (key == node->get_data()) {         // 트리에 이미 key값을 가지는 node가 있는 경우
                return;
            } else if (key < node->get_data()) {    // key < root 노드의 data
                if (node->get_left() == nullptr) {
                    node->set_left(newNode);
                } else {
                    insert_recur(node->get_left(), key);
                }
            } else if (key > node->get_data()) {    // key > root 노드의 data
                if (node->get_right() == nullptr) {
                    node->set_right(newNode);
                } else {
                    insert_recur(node->get_right(), key);
                }
            }
        }

    };
}

#endif //MAIN_CPP_MYSET_H
