//
// Created by 26236 on 2023/3/2.
//
#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include "leetcode15.h"
using namespace std;


/* a time out solution */
//vector<vector<int>> threeSum(vector<int>& nums){
//    int n = nums.size();
//    vector<vector<int>> res;
//    set<vector<int>> res_set;
//    vector<int> curr;
//    if (n == 3){
//        if (nums[0] + nums[1] + nums[2] != 0){
//            return res;
//        }
//        else{
//            res = {{nums[0],nums[1],nums[2]}};
//            return res;
//        }
//    }
//    else{
//        for (int i = 0; i < n; i++){
//            for (int j = i + 1; j < n; j++){
//                for (int k = j + 1; k < n; k++){
//                    if (nums[i] + nums[j] + nums[k] == 0){
//                        if (nums[i] <= nums[j] && nums[j] <= nums[k]){
//                            curr.push_back(nums[i]);
//                            curr.push_back(nums[j]);
//                            curr.push_back(nums[k]);
//                        }
//                        else if(nums[j] <= nums[i] && nums[i] <= nums[k]){
//                            curr.push_back(nums[j]);
//                            curr.push_back(nums[i]);
//                            curr.push_back(nums[k]);
//                        }
//                        else if(nums[k] <= nums[i] && nums[i] <= nums[j]){
//                            curr.push_back(nums[k]);
//                            curr.push_back(nums[i]);
//                            curr.push_back(nums[j]);
//                        }
//                        else if(nums[i] <= nums[k] && nums[k] <= nums[j]){
//                            curr.push_back(nums[i]);
//                            curr.push_back(nums[k]);
//                            curr.push_back(nums[j]);
//                        }
//                        else if(nums[k] <= nums[j] && nums[j] <= nums[i]){
//                            curr.push_back(nums[k]);
//                            curr.push_back(nums[j]);
//                            curr.push_back(nums[i]);
//                        }
//                        else if(nums[j] <= nums[k] && nums[k] <= nums[i]){
//                            curr.push_back(nums[j]);
//                            curr.push_back(nums[k]);
//                            curr.push_back(nums[i]);
//                        }
//                        res_set.insert(curr);
//                        curr.clear();
//                    }
//                }
//            }
//        }
//        vector<vector<int>> res(res_set.begin(), res_set.end());
//        return res;
//    }
//}

vector<vector<int>> threeSum(vector<int>& nums){
    set<vector<int>> resSet;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int j, k;
    for (int i = 0; i < n; i++){
        j = i + 1;
        k = n - 1;
        while (j < k){
            if (nums[i] + nums[j] + nums[k] == 0){
                resSet.insert({nums[i], nums[j],nums[k]});
                j++;
                k--;
            }
            else if (nums[i] + nums[j] + nums[k] > 0){
                k--;
            }
            else{
                j++;
            }
        }
    }
    for(vector<int> combination : resSet){
        res.push_back(combination);
    }
    return res;
}

//int main(){
//    // nums = [-1,0,1,2,-1,-4]
//    vector<int> nums = {-1,0,1,2,-1,-4};
//    vector<vector<int>> main_res = threeSum(nums);
//    printf("the size of return %d", main_res.size());
//
//    return 0;
//}
