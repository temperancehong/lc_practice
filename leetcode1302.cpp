//
// Created by 26236 on 2023/7/19.
//
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main_h;


// find the height of the tree
int height(TreeNode* root){
    int h;
    if (root == nullptr){
        return 0;
    }
    else{
        return max(1+height(root->left), 1+height(root->right));
    }
}

int sum_leaf(TreeNode* root, int i){
    if (root == nullptr){
        return 0;
    }
    if (i == main_h){
        return root->val; // if it's the farthest leaf, return the value
    }
    else{ //  if not, get the result of the child leaves
        return sum_leaf(root->left, i+1) + sum_leaf(root->right, i+1);
    }
}


int deepestLeavesSum(TreeNode* root) {
    main_h = height(root);
    if (root == nullptr){
        return 0;
    }
    return sum_leaf(root, 1); // starting to count from the first level
}