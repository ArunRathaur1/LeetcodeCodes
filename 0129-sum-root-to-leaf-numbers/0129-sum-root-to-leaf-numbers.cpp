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
    void answer(TreeNode* root,int number,int &total){
        if(root->left==NULL&& root->right==NULL){
            total=total+number*10+root->val;
           return;
        }        
        if(root->left)answer(root->left,number*10+root->val,total);
        if(root->right)answer(root->right,number*10+root->val,total);       
    }
    int sumNumbers(TreeNode* root) {
        int s=0;
        int total=0;
        answer(root,s,total);
        return total;
    }
};