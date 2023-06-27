//
// Created by 26236 on 2023/6/27.
//

/*
 * Full Binary Tree Theorems
The total number of nodes is 2i + 1 . The number of internal nodes is (n – 1) / 2 . The number of leaves is (n + 1) / 2 .
 */

#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {

    }

