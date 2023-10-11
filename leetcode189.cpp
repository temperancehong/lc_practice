//
// Created by 26236 on 2023/10/11.
//

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    int n = nums.size();
    for (int i = 0; i < n-k; i++){
        nums.push_back(nums[i]);
    }
    nums.erase(nums.begin(), nums.begin()+n-k);
}