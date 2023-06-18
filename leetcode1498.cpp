//
// Created by 26236 on 2023/5/6.
//
#include <bits/stdc++.h>
using namespace std;
int numSubseq(vector<int>& nums, int target);

int main(){
    vector<int> nums0{3,5,6,7}, nums1{3,3,6,8}, nums2{2,3,3,4,6,7};
    int t0 = 9, t1 = 10, t2 = 12;


}

int numSubseq(vector<int>& nums, int target){
    int first_number = nums[0];
    int last_number = nums[-1];
    int last_number_index = nums.size() - 1; // last number of the first half of vectors
    for (int i = 0; i < nums.size(); i++){
        if (first_number + nums[i] > target){
            if (i != 0){
                last_number_index = i - 1;
                break;
            }
            else{ // if the first number is not satisfied, the answer is straightly 0
                return 0;
            }
        }
        else if (i == nums.size()-1){
            // the last one adds less than the target
            last_number_index = i;
        }
    }
    int first_number_index = 0; // the beginning index of the second half of vectors
    for (int j = 0; j < nums.size(); j++){
        if (last_number + nums[j])
    }


}