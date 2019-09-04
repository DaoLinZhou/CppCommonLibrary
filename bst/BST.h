//
// Created by Daolin on 2019/8/13.
//

#ifndef ALGORITHM_BST_H
#define ALGORITHM_BST_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <ctime>

using namespace std;

template <typename Key, typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            left = NULL;
            right = NULL;
        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node* root;
    int count;

public:
    BST() {
        root = NULL;
        count = 0;
    }

    ~BST(){
        destroy(root);
    }

    int getSize(){ return count; }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Key key, Value value){
        root = insert(root, key, value);
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

    /**
     * check the subNode is NULL or not NULL before change to subNode
     * @param key
     * @param value
     */
    void insertLoop(Key key, Value value){
        count++;
        if(root == NULL){
            root = new Node(key, value);
            return;
        }
        Node* node = root;
        while(node != NULL){
            if(node->key == key){
                node->value = value;
                count--;
                return;
            }else if(node->key > key){
                if(node->left != NULL)
                    node = node->left;
                else {
                    node->left = new Node(key, value);
                    return;
                }
            }else{
                if(node->right != NULL)
                    node = node->right;
                else{
                    node->right = new Node(key, value);
                    return;
                }
            }
        }
    }

    /**
     * find parent node first. Then insert node to the parent node
     * @param key
     * @param value
     */
    void insertLoop2(Key key, Value value){
        count++;
        if(root == NULL){
            root = new Node(key, value);
            return;
        }
        //node is the parent node before adding
        Node* node = NULL;
        Node* subTree = root;
        while(subTree != NULL){
            if(subTree->key == key){
                subTree->value = value;
                count--;
                return;
            }
            node = subTree;
            if(subTree->key > key)
                subTree = subTree->left;
            else
                subTree = subTree->right;
        }
        if(node->key > key)
            node->left = new Node(key, value);
        else
            node->right = new Node(key, value);
    }

    /**
     * 所谓遍历前中后, 指的就是什么时候访问当前节点
     */

    // 前序遍历, 先访问当前节点, 再依次递归访问左右子树
    void preOrder(){
        preOrderTraversal(root);
    }

    // 中序遍历, 先递归访问左子树, 在访问自身节点, 再访问右子树
    void inOrder(){
        inOrderTraversal(root);
    }

    // 后序遍历, 先递归访问左右子树, 再访问自身节点
    // 先把左右两个子树都遍历完成才做自己的事情,
    // 这个性质在某些操作上十分有用,
    // 例如: 在释放二分搜索树内存时
    void postOrder(){
        postOrderTraversal(root);
    }

    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            cout << node->value << endl;
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                 q.push(node->right);
        }
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
        if(root)
            root = removeMin(root);
    }

    void removeMax(){
        if(root)
            root = removeMax(root);
    }

    void remove(Key key){
        root = remove(root, key);
    }

    // 查找key的后继(比key大的最小的key), 递归算法
    // 如果不存在key的后继(key不存在, 或者key是整棵二叉树中的最大值), 则返回NULL
    Key* successor(Key key){
        Node* node = search(root, key);
        // 如果key所在的节点不存在, 则key没有前驱, 返回NULL
        if(node == NULL)
            return NULL;
        // 如果key所在的节点右子树不为空,则其右子树的最小值为key的后继
        if(node->right != NULL)
            return &(minimum(node->right)->key);
        // 否则, key的后继在从根节点到key的路径上, 在这个路径上寻找到比key大的最小值, 即为key的后继
        Node* sucNode = successorFromAncestor(root, key);
        return sucNode == NULL ? NULL : &(sucNode->key);
    }

    Key* predecessor(Key key){
        Node* node = search(root, key);
        if(node == NULL)
            return NULL;
        if(node->left != NULL)
            return &(maximum(node->left)->key);
        Node* preNode = predecessorFromAncestor(root, key);
        return preNode == NULL ? NULL : &(preNode->key);
    }

    Key* floor(Key key){
        if(count <= 0 || key < minimum())
            return NULL;
        Node* node = floor(root, key);
        return &(node->key);
    }

    Key* ceil(Key key){
        if(count <= 0 || key > maximum())
            return NULL;
        return &(ceil(root, key)->key);
    }

private:
    Node* insert(Node* node, Key key, Value value){
        if(node == NULL) {
            count++;
            return new Node(key, value);
        }
        if(node->key == key)
            node->value = value;
        else if(node->key < key)
            node->right = insert(node->right, key, value);
        else
            node->left = insert(node->left, key, value);
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

    void inOrderTraversal(Node* node){
        if(node == NULL)
            return;
        inOrderTraversal(node->left);
        cout << node->value << endl;
        inOrderTraversal(node->right);
    }

    void preOrderTraversal(Node* node){
        if(node == NULL)
            return;
        cout << node->value << endl;
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node){
        if(node == NULL)
            return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << endl;
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

    Node* minimumLoop(Node* node){
        while(node->left != NULL)
            node = node->left;
        return node;
    }

    Node* maximum(Node* node){
        if(node->right == NULL)
            return node;
        return maximum(node->right);
    }

    Node* removeMin(Node* node){
        if(node->left == NULL){
            Node* rightNode = node->right;
            delete node;
            count --;
            // 如果为空, 返回的也是空
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node){
        if(node->right == NULL){
            Node* leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node* remove(Node* node, Key key){
        if(node == NULL)
            return NULL;
        if(key > node->key){
            node->right = remove(node->right, key);
            return node;
        }else if(key < node->key){
            node->left = remove(node->left, key);
            return node;
        }else{
            if(node->left == NULL){
                Node* rightNode = node->right;
                delete node;
                count --;
                return rightNode;
            }
            if(node->right == NULL){
                Node* leftNode = node->left;
                delete node;
                count --;
                return leftNode;
            }
            Node* successor = new Node(maximum(node->left));
            count ++;

            successor->right = node->right;
            successor->left = removeMax(node->left);

            delete node;
            count --;
            return successor;
        }
    }

    Node* predecessorFromAncestor(Node* node, Key key){
        if(node->key == key)
            return NULL;
        if(key < node->key)
            return predecessorFromAncestor(node->left, key);
        else{
            assert(key > node->key);
            Node* tempNode = predecessorFromAncestor(node->right, key);
            if(tempNode)
                return tempNode;
            else
                return node;
        }
    }

    // 在以node为根的二叉搜索树中, 寻找key的祖先中,比key大的最小值所在节点, 递归算法
    // 算法调用前已保证key存在在以node为根的二叉树中
    Node* successorFromAncestor(Node* node, Key key){
        if(node->key == key)
            return NULL;
        if(key > node->key)
            // 如果当前节点小于key, 则当前节点不可能是比key大的最小值
            // 向下搜索到的结果直接返回
            return successorFromAncestor(node->right, key);
        else{
            assert(key < node->key);
            // 如果当前节点大于key, 则当前节点有可能是比key大的最小值
            // 向左继续搜索, 将结果存储到tempNode中
            Node* tempNode = successorFromAncestor(node->left, key);
            if(tempNode)
                return tempNode;
            else
                return node;
        }
    }

    Node* floor(Node* node, Key key){
        if(node == NULL)
            return NULL;
        if(node->key == key)
            return node;
        if(node->key > key)
            return floor(node->left, key);
        // 如果node->key < key
        // 则node有可能是key的floor节点, 也有可能不是(存在比node->key大但是小于key的其余节点)
        // 需要尝试向node的右子树寻找一下
        Node* tempNode = floor(node->right, key);
        if(tempNode)
            return tempNode;
        else
            return node;
    }

    Node* ceil(Node* node, Key key) {
        if (node == NULL)
            return NULL;
        if (node->key == key)
            return node;
        if (node->key < key)
            return ceil(node->right, key);
        Node* tempNode = ceil(node->left, key);
        return tempNode ? tempNode : node;
    }

};

#endif //ALGORITHM_BST_H
