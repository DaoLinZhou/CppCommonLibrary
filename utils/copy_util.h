//
// Created by Daolin on 2019/10/10.
// 参考 https://www.gomcu.com/c-fstrea/

#ifndef ALGORITHM_COPY_UTIL_H
#define ALGORITHM_COPY_UTIL_H

#include <string>
#include <fstream>

bool copy(const std::string& from, const std::string& to){
    std::ofstream fout(to, std::ios::binary);
    std::ifstream fin(from, std::ios::binary);

    if(fout.fail() || fin.fail())
        return false;

    /// 缓冲区复制
    fout << fin.rdbuf();

    fin.close();
    fout.close();
    return true;
}

bool copy_2(const std::string& from, const std::string& to){
    std::ofstream fout(to, std::ios::binary);
    std::ifstream fin(from, std::ios::binary);

    if(fout.fail() || fin.fail())
        return false;

    char c;
    /// 取消流默认跳过空白符的输入格式, 使得空白符也成为字符的一种
    fin.unsetf(std::ios::skipws);
    /// 逐个字符进行复制
    while(fin>>c)
        fout << c;

    fin.close();
    fout.close();
    return true;
}

bool copy_3(const std::string& from, const std::string& to, int size = 1024){
    std::ofstream fout(to, std::ios::binary);
    std::ifstream fin(from, std::ios::binary);

    if(fout.fail() || fin.fail())
        return false;

    /// 取消流默认跳过空白符的输入格式, 使得空白符也成为字符的一种
    fin.unsetf(std::ios::skipws);

    /// 批量进行读取
    char* c = new char[size];

    while(fin.read(c, size))
        fout.write(c, fin.gcount());

    fin.close();
    fout.close();
    delete[] c;
    return true;
}

#endif //ALGORITHM_COPY_UTIL_H
