//
// Created by Daolin on 2019/9/7.
//

#include <vector>
#include <algorithm>

using namespace std;

/**
 * 解题思路:
 * 两个指针, k, i
 * k <= i, k 指向下一个为0的元素
 * 如果i不为 0, 判断是否需要交换
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;  // 指向下一个0
        for(int i = 0; i < nums.size(); i++)
            if(nums[i])     // 如果i不为空
                if(i != k)  // 此时k指向第一个0的位置
                    swap(nums[k++], nums[i]);
                else    // 如果i和k指向同一个元素, 用不着swap
                    k++;
    }
};
