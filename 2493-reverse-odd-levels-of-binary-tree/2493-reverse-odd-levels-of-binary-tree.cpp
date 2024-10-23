/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void oddLevel(TreeNode* left,TreeNode* right,int level){
        if(left==NULL || right==NULL)return ;
        if(level%2!=0){
           swap(left->val,right->val);
        }
            oddLevel(left->left,right->right,level+1);
            oddLevel(left->right,right->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)return root;
        oddLevel(root->left,root->right,1);
        return root;
        
    }
};