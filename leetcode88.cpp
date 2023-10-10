//
// Created by 26236 on 2023/10/9.
//

#include <bits/stdc++.h>
using namespace std;

// double pointer, backward, so no element would be missed out
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = n-1;
    int j = n-1;
    int k = n+m-1;
    while (j >=0){
        if (i>= 0 && nums1[i] >= nums2[j]){ // because i can be subtracted to minus
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }

}