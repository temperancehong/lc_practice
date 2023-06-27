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


unordered_map<int, vector<TreeNode*>> memo;
vector<TreeNode*> allPossibleFBT(int n){
    if (n%2 == 0){
        return {};
    }
    else if (n == 1){
        return memo[1] = {new TreeNode()};
    }
    else{
        vector<TreeNode*> res;
        for (int i = 1; i < n; i=i+2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            for (auto l : left){
                for (auto j: right){
                    res.push_back(new TreeNode(0, l, j));
                }
            }
        }
        return memo[n] = res;
    }
}



// using top down strategy
//vector<TreeNode*> allPossibleFBT(int n) {
//    if (n%2 == 0){
//        vector<TreeNode*> res;
//        return res;
//    }
//    else if (n == 1){
//        TreeNode* firstTree = new TreeNode();
//        vector<TreeNode*> res;
//        res.push_back(firstTree);
//        return res;
//    }
//    else if (n == 3){
//        vector<TreeNode*> res;
//        TreeNode* basic1 = new TreeNode();
//        TreeNode* basic2 = new TreeNode();
//        TreeNode* firstTree = new TreeNode(0, basic1, basic2);
//        res.push_back(firstTree);
//        return res;
//    }
//    else{
//        vector<TreeNode*> base_vec = allPossibleFBT(n-2);
//        vector<TreeNode*> res_vec;
//        for (auto tNode:base_vec){
//            // iterate through every node that is from previous, add it to left or right child to the basic tree
//            TreeNode* basic1 = new TreeNode();
//            TreeNode* basic2 = new TreeNode();
//            TreeNode* add1 = new TreeNode(0, basic1, tNode);
//            TreeNode* add2 = new TreeNode(0, tNode, basic2);
//            res_vec.push_back(add1);
//            res_vec.push_back(add2);
//        }
//
//
//        return res_vec;
//    }
//}

