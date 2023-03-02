//
// Created by 26236 on 2023/3/2.
//

/* only using insertion sorts */

#include "solutions75.h"
#include <vector>
#include <iostream>
using namespace std;

void sortColors(vector<int>& nums){
    int tmp;
    for (int i = 1; i < nums.size(); i++){
        for (int j = i; (j > 0) && (nums[j] < nums[j-1]); j--){
            tmp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = tmp;
        }
    }
}
