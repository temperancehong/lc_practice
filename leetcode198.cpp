//
// Created by 26236 on 2023/10/22.
//

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    //[rob1, rob2, nums[i]]
    int rob1=0, rob2=0;
    for (int i=0; i < n; i++){
        int tmp = max(nums[i]+rob1, rob2);
        rob1=rob2;
        rob2=tmp;
    }
    return rob2;
}



void printIntVector(const std::vector<int>& intVector, int k) {
    for (int i = 0; i < k; i++){
        cout<<intVector[i]<<" ";
    }
    std::cout << std::endl;
}

int main(){
    vector<int> nums = {1,1};
    int res = rob(nums);
    cout<<res<<endl;
    return 0;
}