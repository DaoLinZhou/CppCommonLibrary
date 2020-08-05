//
// Created by Daolin on 2020/8/1.
//

#ifndef ALGORITHM_SKIPLIST_H
#define ALGORITHM_SKIPLIST_H

#include <stdexcept>

template<typename K, typename V>
struct Node{
    K key;
    V value;
    Node** nexts;

    Node(){}

    Node(const K& key, const V& value, int n){
        this->key = key;
        this->value = value;
        nexts = new Node*[n];
        for(int i = 0; i < n; i++){
            nexts[i] = nullptr;
        }
    }
};

template<typename K, typename V>
class SkipList{
    typedef Node<K, V> Node;
private:
    int size;
    Node* first;
    double p; // 添加一层的概率
    const static int MAX_LEVEL;
    int level; // 有效层数

public:

    SkipList(double p = 0.5){
        assert(0 < p && p < 1);
        first = new Node();
        first->nexts = new Node*[MAX_LEVEL];
        for(int i = 0; i < MAX_LEVEL; i++){
            first->nexts[i] = nullptr;
        }
        this->p = p;
        level = 0;
        size = 0;
    }

    ~SkipList(){
        destroy(first);
        size = 0;
        level = 0;
        first = nullptr;
    }


    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void put(K key, V value){

        Node* node = first;
        Node* preNode[MAX_LEVEL];

        // 寻找前驱节点
        for(int i = level-1; i >= 0; i--){
            while (node->nexts[i] != nullptr && node->nexts[i]->key < key){
                node = node->nexts[i];
            }
            if(node->nexts[i] != nullptr && node->nexts[i]->key == key){
                node->nexts[i]->value = value;
                return;
            }
            preNode[i] = node;
        }

        // 创建节点
        int nodeLevel = getNodeLevel();
        Node* element = new Node(key, value, nodeLevel);

        // 插入节点
        for(int i = 0; i < nodeLevel; i++){
            if(i >= level){
                first->nexts[i] = element;
            } else {
                element->nexts[i] = preNode[i]->nexts[i];
                preNode[i]->nexts[i] = element;
            }
        }
        level = std::max(level, nodeLevel);
        size++;
    }

    V get(K key){
        Node* node = first;
        for(int i = level-1; i >= 0; ){
            if(node->nexts[i] == nullptr || node->nexts[i]->key > key){
                i--;
            } else if(node->nexts[i]->key == key){
                return node->nexts[i]->value;
            } else {
                node = node->nexts[i];
            }
        }
        throw std::runtime_error("element not in the list");
    }

    bool contain(K key){
        Node* node = first;
        for(int i = level-1; i >= 0; ){
            if(node->nexts[i] == nullptr || node->nexts[i]->key > key){
                i--;
            } else if(node->nexts[i]->key == key){
                return true;
            } else {
                node = node->nexts[i];
            }
        }
        return false;
    }

    V remove(K key){
        if(!contain(key)){
            throw std::runtime_error("element not in the list");
        }
        Node* node = first;
        Node* preNode[MAX_LEVEL];

        // 计算删除节点的层数
        int targetLevel = 0;

        // 寻找前驱节点
        for(int i = level-1; i >= 0; i--){
            while (node->nexts[i] != nullptr && node->nexts[i]->key < key){
                node = node->nexts[i];
            }
            if(node->nexts[i] != nullptr && node->nexts[i]->key == key){
                preNode[i] = node;
                targetLevel = std::max(targetLevel, i);
            }
        }

        // 获得待删除节点
        Node* target = node->nexts[0];

        // 把节点从list中剥离并删除
        for(int i = 0; i <= targetLevel; i++){
            preNode[i]->nexts[i] = preNode[i]->nexts[i]->nexts[i];
        }
        V ret = target->value;
        delete target;

        // 维护 size 和 level
        size--;
        for(int i = level-1; first->nexts[i] == nullptr && level >= 0; i--){
            level--;
        }

        return ret;
    }

private:
    int getNodeLevel(){
        int count = 1;
        while (rand() <= p * RAND_MAX && count < MAX_LEVEL){
            count++;
        }
        return count;
    }

    void destroy(Node* n){
        if(n == nullptr) return;
        destroy(n->nexts[0]);
        delete n;
    }

};

template<typename K, typename V>
const int SkipList<K, V>::MAX_LEVEL = 32;

#endif //ALGORITHM_SKIPLIST_H
