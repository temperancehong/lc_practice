//
// Created by 26236 on 2023/10/23.
//

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n=height.size();
    int left=0, right=n-1;
    int max_area=0;
    while (right > left){
        int area = (right-left)*min(height[right],height[left]);
        if (area>max_area) max_area = area;
        if (height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return max_area;
}