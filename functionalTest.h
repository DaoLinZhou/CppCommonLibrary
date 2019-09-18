//
// Created by Daolin on 2019/9/16.
//

#ifndef ALGORITHM_FUNCTIONALTEST_H
#define ALGORITHM_FUNCTIONALTEST_H

#include <functional>
#include <iostream>

using namespace std;


int add(int a, int b){return a+b;}
// 函数式编程
function<int(int, int)> test(int sum(int, int)){
    return sum;
}

int Test(){

    cout << endl << test(add)(1,4);

    return 0;
}

#endif //ALGORITHM_FUNCTIONALTEST_H
