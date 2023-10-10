//
// Created by 26236 on 2023/10/10.
//

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 0, i = 0;
    while (i < nums.size()){
        int curr = nums[i];
        int count = 0; // the count of the number appeared
        while (i < nums.size() && nums[i] == curr){
            count++;
            i++;
        }// counting the number of the element
        nums[k++] = curr;
        if (count > 1){
            nums[k++] = curr;
        }
    }
    return k;
}

void printIntVector(const std::vector<int>& intVector, int k) {
    for (int i = 0; i < k; i++){
        cout<<intVector[i]<<" ";
    }
    std::cout << std::endl;
}

int main(){
    vector<int> vec = {0,1,1,1,2,3,3,5,7,9,9,9};
    vector<int> vec2 = {1,1,1,2,2,3};
    int k = removeDuplicates(vec2);
    printIntVector(vec2, k);
    cout<<k<<endl;

    return 0;
}
