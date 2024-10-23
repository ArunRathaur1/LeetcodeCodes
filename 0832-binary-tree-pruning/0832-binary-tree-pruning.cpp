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
    void PruneTree(TreeNode* &root){
        if(root==NULL)return ;
        PruneTree(root->left);
        PruneTree(root->right);
        if(root->left==NULL&& root->right==NULL&& root->val==0){
            root=NULL;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        PruneTree(root);
        return root;
    }
};