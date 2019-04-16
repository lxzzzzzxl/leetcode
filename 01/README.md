# LeetCode-01 两数之和

## 题目描述

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那**两个**整数，并返回他们的数组下标。  
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

    给定 nums = [2, 7, 11, 15], target = 9  
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]

## 解决方案
### 方法一：暴力解法
这是一道难度等级为简单的题，相信大家上来秒想的就是暴力解法，我也不例外  

思路：  
遍历每个元素 x，并查找是否存在一个值与 target - x 相等的目标元素。

代码详解：

```C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *a = (int*)malloc(sizeof(int)*2);   //定义返回数组并申请内存空间（上面Note有提示了）
    for(i = 0; i<numsSize; i++)             //遍历每个数组元素
    {
        for(j = i+1; j<numsSize; j++)       //查找目标元素
        {
            if(nums[i]+nums[j] == target)   //查找成功，将元素下标存入返回数组
            {
                a[0] = i;
                a[1] = j;
                return a;                   //返回数组
            }             
        }
    }
    return 0;
}
```
