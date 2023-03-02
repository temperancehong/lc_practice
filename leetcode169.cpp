//
// Created by 26236 on 2022/12/14.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums){
    unordered_map<int, int> my_dict;
    if (nums.size() == 1){return nums[0];}
    for (int i = 0; i < nums.size(); i++){
        if (my_dict.find(nums[i])!= my_dict.end()){
            my_dict[nums[i]] ++;
            if (my_dict[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
        else{
            my_dict[nums[i]] = 1;
        }
    }
    return 0;
}


int main(){

    vector<int> nums = {2,2,1,1,1,2,2};
//    vector<int> nums = {8,8,7,7,7};
//    vector<int> nums = {3,2,3};
    int major = majorityElement(nums);
    printf("The major number is %d",major);
    return 0;
}
