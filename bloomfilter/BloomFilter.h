//
// Created by Daolin on 2020/7/31.
//

#ifndef ALGORITHM_BLOOMFILTER_H
#define ALGORITHM_BLOOMFILTER_H

#include <cassert>
#include <cmath>

using std::log;

template<typename T>
class BloomFilter{
private:
    /**
     * 二进制向量的长度(一共有多少个二进制位)
     */
    int bitSize;

    /**
     * 二进制向量, 一个 long long 是 64 位
     */
    long long* bits;

    /**
     * 哈希函数的个数
     */
    int hashFuncNum;

public:
    /**
     * @param n 数据规模
     * @param p 误判率, 取值范围 (0, 1)
     */
    BloomFilter(int n, double p){
        assert(n > 0 && p > 0 && p < 1);
        double ln2 = log(2);
        // 求出二进制向量长度
        bitSize = -(n * log(p)) / (ln2 * ln2);
        // 求出哈希函数的个数
        hashFuncNum = bitSize * ln2 / n;
        // bit数组的长度
        int longSize = (sizeof(long long)*8);
        bits = new long long[(bitSize+longSize-1) / longSize];
    }

    void put(T value){
        int hash1 = hash<T>()(value);
        int hash2 = hash1 >> 16;

        for(int i = 0; i < hashFuncNum; i++){
            // 每次根据 hash1 和 hash2 计算出一个不同的hash
            int combinedHash = hash1 + (i * hash2);
            if(combinedHash < 0){
                combinedHash = ~combinedHash; // 位取反, 去负号
            }
            int index = combinedHash % bitSize;
            setBit(combinedHash % bitSize);
        }
    }

    bool contains(T value){
        int hash1 = hash<T>()(value);
        int hash2 = hash1 >> 16;

        for(int i = 0; i < hashFuncNum; i++){
            // 每次根据 hash1 和 hash2 计算出一个不同的hash
            int combinedHash = hash1 + (i * hash2);
            if(combinedHash < 0){
                combinedHash = ~combinedHash; // 位取反, 去负号
            }
            int index = combinedHash % bitSize;
            if(!get(index)) return false;
        }
        return true;
    }

private:
    void setBit(int index){
        long long value = 1 << (index % 64);
        bits[index/64] |= value;
    }

    bool get(int index){
        long long value = 1 << (index % 64);
        return bits[index/64] & value;
    }

};

#endif //ALGORITHM_BLOOMFILTER_H
