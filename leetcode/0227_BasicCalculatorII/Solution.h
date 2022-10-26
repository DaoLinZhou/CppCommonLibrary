//
// Created by jiatang on 2022/10/25.
//

#ifndef CPPCOMMONLIBRARY_SOLUTION_H
#define CPPCOMMONLIBRARY_SOLUTION_H

// build abstract syntax tree to parse the expression
#include "../commonHeader.h"

struct Node{
    string symbol;
    Node* left;
    Node* right;
    Node(const string& s){
        symbol = s;
    }

    int traverse(){
        if(symbol[0] >= '0' && symbol[0] <= '9')
            return stoi(symbol);

        int lv = left->traverse();
        int rv = right->traverse();

        if(symbol == "+"){
            return lv + rv;
        }
        if(symbol == "/"){
            return lv / rv;
        }
        if(symbol == "-"){
            return lv - rv;
        }
        return lv * rv;

    }
};

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        string new_s = "";
        for(auto c: s){
            if(c != ' '){
                new_s += c;
            }
        }
        auto root = readADExpression(new_s, i);

        return root->traverse();

    }


    Node* readTDExpression(string& s, int& i){
        auto l_val = new Node(readNextInt(s, i));

        while( i < s.size() && (s[i] == '*' || s[i] == '/') ){
            string sym = readNextSymbol(s, i);
            auto r_val = new Node(readNextInt(s, i));
            auto new_root = new Node(sym);
            new_root->left = l_val;
            new_root->right = r_val;
            l_val = new_root;
        }
        return l_val;
    }

    Node* readADExpression(string& s, int& i){

        auto l_val = readTDExpression(s, i);
        while( i < s.size() && (s[i] == '+' || s[i] == '-') ){
            string sym = readNextSymbol(s, i);
            auto r_val = readTDExpression(s, i);
            auto new_root = new Node(sym);
            new_root->left = l_val;
            new_root->right = r_val;
            l_val = new_root;
        }

        return l_val;
    }


    string readNextSymbol(string& s, int& i){

        while(i < s.size() && s[i] == ' '){
            i++;
        }
        if (i >= s.size()) return "";
        string ret = "";
        ret += s[i];
        i++;

        return ret;
    }

    string readNextInt(string& s, int& i){

        while(i < s.size() && s[i] == ' '){
            i++;
        }

        string ret = "";
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            ret += s[i];
            i++;
        }
        return ret;
    }

};
#endif //CPPCOMMONLIBRARY_SOLUTION_H
