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
    void inverting(TreeNode* root){
        if(root==NULL)return;
        swap(root->left,root->right);
        inverting(root->left);
        inverting(root->right);
        
    }
    TreeNode* invertTree(TreeNode* root) {
        inverting(root);
        return root;
    }
};