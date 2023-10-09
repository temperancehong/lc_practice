//
// Created by 26236 on 2023/7/20.
//
// unsolved

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

int sumChildren(TreeNode* root){
    int res = 0;
    if (root->left != nullptr){
        res += root->left->val;
    }
    if (root->right != nullptr){
        res += root->right->val;
    }
    return res;
}

int sumGrandChildren(TreeNode* root){
    int res = 0;
    if (root->left != nullptr){
        res += sumChildren(root->left);
    }
    if (root->right != nullptr){
        res += sumChildren(root->right);
    }
    return res;
}

int sumEvenGrandparent(TreeNode* root) {
    int res = 0;
    if (root == nullptr){
        return res; // in this case it returns 0
    }
    if (root->val % 2 == 0){
        res += sumGrandChildren(root);
    }

}
