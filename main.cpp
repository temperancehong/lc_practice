//
// Created by 26236 on 2023/3/2.
//
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "leetcode15.h"
#include "leetcode169.h"
#include "leetcode136.h"
using namespace std;

int main(){

//    //lc 15
//    vector<int> nums = {-1,0,1,2,-1,-4};
//    vector<vector<int>> main_res = threeSum(nums);
//    printf("the size of return %d", main_res.size());

//    //lc169
//    vector<int> nums = {2,2,1,1,1,2,2};
//    vector<int> nums = {8,8,7,7,7};
//    vector<int> nums = {3,2,3};
//    int major = majorityElement(nums);
//    printf("The major number is %d",major);

    //lc136
//    vector<int> nums = {1,2,1,2,3,3,4,6,5,5,6};
    vector<int> nums = {1,1,2,3,4,5,4,5,3,-1,2};
    int single = singleNumber(nums);
    printf("The number is : %d\n",single);
    return 0;


    return 0;
}
