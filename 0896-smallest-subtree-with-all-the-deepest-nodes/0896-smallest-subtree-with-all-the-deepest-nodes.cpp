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
    int find_height(TreeNode* root){
        if(root==NULL)return 0;
        return max(find_height(root->left),find_height(root->right))+1;
    }
    TreeNode* findNode(TreeNode* root){
        if(root==NULL)return NULL;
        int x1=find_height(root->left);
        int x2=find_height(root->right);
        if(x1>x2){
            return findNode(root->left);
        }
        else if(x2>x1){
            return findNode(root->right);
        }
        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return findNode(root);
    }
};