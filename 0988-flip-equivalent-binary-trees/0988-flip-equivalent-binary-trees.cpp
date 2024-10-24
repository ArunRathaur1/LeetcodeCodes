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
    bool GetValue(TreeNode* root1,TreeNode* root2){
        if(root1==NULL and root2==NULL)return true;
        if(root1==NULL|| root2==NULL)return false;
        if(root1->val!=root2->val)return false;
        bool value1=GetValue(root1->left,root2->left)|| GetValue(root1->left,root2->right);
        bool value2=GetValue(root1->right,root2->right)|| GetValue(root1->right,root2->left);
        return value1&& value2;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
       return GetValue(root1,root2);
    }
};