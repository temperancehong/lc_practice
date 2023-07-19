//
// Created by 26236 on 2023/7/19.
//


#include <bits/stdc++.h>
using namespace std;

// solution of complexity n * m
//int countNegatives(vector<vector<int>>& grid) {
//    int count = 0;
//    int n, m;
//    n = grid.size();
//    m = grid[0].size();
//    int row_max = n;
//    int column_max = m;
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++){
//            if (grid[i][j] < 0){
//                count++;
//            }
//        }
//    }
//    return count;
//}

// solution with binary search complexity nlogm
int countNegatives(vector<vector<int>>& grid) {
    int count = 0;
    int n = grid[0].size();
    int index = 0;
    for (auto row : grid){
        // find the first non negative index
        index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
        count += n - index;
    }
    return count;
}
