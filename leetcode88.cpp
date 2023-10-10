//
// Created by 26236 on 2023/10/9.
//

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = n-1;
    int j = n-1;
    int k = n+m-1;
    while (j >=0 && i >= 0){
        if (nums1[i] >= nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }

}