#include<bits/stdc++.h>
using namespace std;

//-------------------copied from LeetCode problem 98(I had done it already)--------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int my_min(TreeNode* root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root->val;
}
int my_max(TreeNode* root){
    while(root->right != nullptr){
        root = root->right;
    }
    return root->val;
}

bool isValidBST(TreeNode* root) {
    if(root == nullptr) {return true;}
    else if(root->left !=nullptr || root->right !=nullptr){
        if(root->left != nullptr && (root->val <= my_max(root->left) || (root->val <= root->left->val || !isValidBST(root->left)))){return false;}
        if(root->right != nullptr && (root->val >= my_min(root->right) || (root->val >= root->right->val || !isValidBST(root->right)))){return false;}
        return true;
    }else return true;      
}




