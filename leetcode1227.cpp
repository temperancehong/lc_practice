//
// Created by 26236 on 2023/6/28.
//

#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int n,m; // dimension
    n = matrix.size(); // rows
    m = matrix[0].size(); // cols
    int n_square = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == 1){
                n_square++;
                int k = i;
                int k2 = j;
                int width = 1;
                while (k + width <= n-1 && k2 + width <= m-1){
                    int square_flag = 1;
                    for (int l = k; l <= k+width; l++){
                        for (int ll = k2; ll <= k2+width; ll++){
                            square_flag = square_flag * matrix[l][ll];
                        }
                    }
                    n_square = n_square + square_flag;
                    width++;
                }
            }
        }
    }
    return n_square;
}

int main(){
    vector<vector<int>> test_matrix = {{0,1,1,1},
                                       {1,1,1,1},
                                       {0,1,1,1}};
    vector<vector<int>> test_matrix2 = {{1,0,1},
                                        {1,1,0},
                                        {1,1,0}};
    int res = countSquares(test_matrix);
    int res2 = countSquares(test_matrix2);
    cout<<res<<endl;
    cout<<res2<<endl;

    return 0;
}
