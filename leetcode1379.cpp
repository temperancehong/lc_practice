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

void preorder(TreeNode* cloned, TreeNode* target, TreeNode*& node){
    if (cloned == nullptr) return;
    if (cloned->val == target->val){
        node = cloned;
    }
    preorder(cloned->left, target, node);
    preorder(cloned->right, target, node);
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (cloned == nullptr || target == nullptr){
        return nullptr;
    }
    TreeNode* node = new TreeNode();
    preorder(cloned, target, node);
    return node;
}
