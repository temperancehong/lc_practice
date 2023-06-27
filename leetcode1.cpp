//
// Created by 26236 on 2023/5/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main(){
    vector<int> my_vector = {2,7,11,5};
    vector<int> res = twoSum(my_vector, 9);
    for (int i=0; i < res.size(); i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}
vector<int> twoSum(vector<int>& nums, int target){
    vector<int> res;
    for (int i=0; i < nums.size(); i++){
        for (int j = i+1; j < nums.size(); j++){
            if (nums[i] + nums[j] == target){
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}