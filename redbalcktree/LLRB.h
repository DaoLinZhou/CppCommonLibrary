//
// Created by Daolin on 2020/6/28.
//

#ifndef ALGORITHM_LLRB_H
#define ALGORITHM_LLRB_H

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename Key, typename Value>
class LLRB{
private:

    const static bool RED;
    const static bool BLACK;

    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;
        bool color;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            left = NULL;
            right = NULL;
            color = RED; // 总是先设置为红色, 因为2-3树插入节点一定要和叶子节点融合
        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
            this->color = node->color;
        }
    };

    Node* root;
    int count;

public:
    LLRB() {
        root = NULL;
        count = 0;
    }

    ~LLRB(){
        destroy(root);
    }

    int getSize(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Key key, Value value){
        root = insert(root, key, value);
        root->color = BLACK;
    }

    bool contain(Key key){
        return contain(root, key);
    }

    Value* search(Key key){
        Node* node = search(root, key);
        if(node == NULL)
            return NULL;
        return &(node->value);
    }

    Key minimum(){
        assert(count != 0);
        Node* minNode = minimum(root);
        return minNode->key;
    }

    Key maximum(){
        assert(count != 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }

    void removeMin(){
        if (root) root->color = RED;
        root = removeMin(root);
        if (root) root->color = BLACK;
    }

    void removeMax() {
        if (root) root->color = RED;
        root = removeMax(root);
        if (root) root->color = BLACK;
    }

    void remove(Key key){
        if (root && !isRed(root->left) && !isRed(root->right))
            root->color = RED;
        if(contain(key))
            root = remove(root, key);
        if (root)
            root->color = BLACK;
    }

private:

    //   node                     x
    //  /   \     左旋转         /  \
    // T1   x   --------->   node   T3
    //     / \              /   \
    //    T2 T3            T1   T2
    Node* leftRotate(Node* node){
        Node* x = node->right;

        // 左旋转
        node->right = x->left;
        x->left = node;

        x->color = node->color;
        node->color = RED;

        return x;
    }

    //     node                   x
    //    /   \     右旋转       /  \
    //   x    T2   ------->   y   node
    //  / \                       /  \
    // y  T1                     T1  T2
    Node* rightRotate(Node* node){
        Node* x = node->left;

        // 右旋转
        node->left = x->right;
        x->right = node;

        x->color = node->color;
        node->color = RED;

        return x;
    }

    // 颜色反转
    void flipColors(Node* node){
        node->color = !node->color;
        node->left->color = !node->left->color;
        node->right->color = !node->right->color;
    }

    bool isRed(Node* node){
        if(node == nullptr) // null 为黑色节点
            return BLACK;
        return node->color;
    }

    Node* insert(Node* node, Key key, Value value){
        if(node == NULL) {
            count++;
            return new Node(key, value);    // 默认插入红色节点
        }
        if(node->key == key)
            node->value = value;
        else if(node->key < key)
            node->right = insert(node->right, key, value);
        else
            node->left = insert(node->left, key, value);

        // 是否需要左旋转
        if(isRed(node->right) && !isRed(node->left))
            node = leftRotate(node);
        // 是否需要右旋转
        if(isRed(node->left) && isRed(node->left->left))
            node = rightRotate(node);
        // 是否需要颜色翻转
        if(isRed(node->left) && isRed(node->right))
            flipColors(node);
        return node;
    }

    // 查找以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node* node, Key key) {
        if(node == NULL)
            return false;
        if(key == node->key)
            return true;
        else if(key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right,key);
    }

    // 在以node为根的二叉搜索树中查找key所对应的value
    Node* search(Node* node, Key key) {
        if(node == NULL)
            return NULL;
        if(node->key == key)
            return node;
        else if(node->key > key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // 与后序遍历基本一致
    void destroy(Node* node) {
        if(node == NULL)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
        count --;
    }

    Node* minimum(Node* node){
        if(node->left == NULL)
            return node;
        return minimum(node->left);
    }

    Node* maximum(Node* node){
        if(node->right == NULL)
            return node;
        return maximum(node->right);
    }

    Node* balance(Node* node){
        // 是否需要左旋转
        if(isRed(node->right))
            node = leftRotate(node);
        // 是否需要右旋转
        if(isRed(node->left) && isRed(node->left->left))
            node = rightRotate(node);
        // 是否需要颜色翻转
        if(isRed(node->left) && isRed(node->right))
            flipColors(node);
        return node;
    }

    Node* moveRedLeft(Node* node){
        flipColors(node);   // 无论node.right是什么节点都要先flipColors一下
        if(isRed(node->right->left)){  // 当 node.right 是3节点时, 会有双红冲突
            node->right = rightRotate(node->right);
            node = leftRotate(node);
            flipColors(node);
        }
        return node;
    }

    Node* moveRedRight(Node* node){
        flipColors(node);
        if(isRed(node->left->right)){
            node->left = leftRotate(node->left);
            node = rightRotate(node);
            flipColors(node);
        }
        return node;
    }

    Node* removeMin(Node* node){
        // 删除节点
        if(node->left == NULL){
            delete node;
            count --;
            return nullptr;
        }
        // 重点: 保持 node.left 和 node.left.left 中有一个为红色
        if(!isRed(node->left) && !isRed(node->left->left))
            node = moveRedLeft(node);

        // 递归调用
        node->left = removeMin(node->left);
        return balance(node);
    }

    Node* removeMax(Node* node){
        if(isRed(node->left))   // 临时旋转为右倾
            node = rightRotate(node);

        if(node->right == NULL){
            delete node;
            count --;
            return nullptr;
        }

        if(!isRed(node->right) && !isRed(node->right->left))
            node = moveRedRight(node);

        node->right = removeMax(node->right);
        return balance(node);
    }

    Node* remove(Node* node, Key key){
        if(node->key > key) {
            if(!isRed(node->left) && !isRed(node->left->left))
                node = moveRedLeft(node);
            node->left = remove(node->left, key);
        } else {
            if (isRed(node->left))
                node = rightRotate(node);
            if (node->key == key && (node->right == nullptr)) {
                delete node;
                count--;
                return nullptr;
            }
            if (!isRed(node->right) && !isRed(node->right->left))
                node = moveRedRight(node);
            if (node->key == key) {
                Node *predecessor = minimum(node->right);
                node->value = predecessor->value;
                node->key = predecessor->key;
                node->right = removeMin(node->right);
            } else{
                node->right = remove(node->right, key);
            }
        }
        return balance(node);
    }

//    Node* remove(Node* node, Key key){
//
//        if(node->key > key) {
//            if(!isRed(node->left) && !isRed(node->left->left))
//                node = moveRedLeft(node);
//            node->left = remove(node->left, key);
//        } else if(node->key < key) {
//            if (isRed(node->left))
//                node = rightRotate(node);
//            if (!isRed(node->right) && !isRed(node->right->left))
//                node = moveRedRight(node);
//            node->right = remove(node->right, key);
//        } else {
//            if(node->left == nullptr){ // node是叶子节点, 且 node 一定为红色
//                delete node;
//                count --;
//                return nullptr;
//            }
//
//            if(!isRed(node->left) && !isRed(node->left->left))
//                node = moveRedLeft(node);
//            if(node->key == key) {  // moveRedLeft之后node可能改变了, 所以要再判断一下
//                Node *predecessor = maximum(node->left);
//                node->value = predecessor->value;
//                node->key = predecessor->key;
//                node->left = removeMax(node->left);
//            }else{
//                node->left = remove(node->left, key);
//            }
//        }
//        return balance(node);
//    }

//    Node* remove(Node* node, Key key){
//        if(node->key < key) {
//            if (isRed(node->left))
//                node = rightRotate(node);
//            if (!isRed(node->right) && !isRed(node->right->left))
//                node = moveRedRight(node);
//            node->right = remove(node->right, key);
//        } else {    // 首先必须确定contains(key)
//            if(node->left == nullptr){  // 如果为叶子节点, 则它一定是我们要删除的node
//                delete node;
//                count --;
//                return nullptr;
//            }
//            // 如果不是叶子节点则一定要维护这个性质
//            if(!isRed(node->left) && !isRed(node->left->left))
//                node = moveRedLeft(node);
//            if(node->key == key) { // 找到了, 则用predecessor代替
//                Node *predecessor = maximum(node->left);
//                node->value = predecessor->value;
//                node->key = predecessor->key;
//                node->left = removeMax(node->left);
//            }else{  // 没找到则继续向下查找
//                node->left = remove(node->left, key);
//            }
//        }
//        return balance(node);
//    }


};

template <typename Key, typename Value>
const bool LLRB<Key, Value>::RED = true;

template <typename Key, typename Value>
const bool LLRB<Key, Value>::BLACK = false;


#endif //ALGORITHM_LLRB_H
