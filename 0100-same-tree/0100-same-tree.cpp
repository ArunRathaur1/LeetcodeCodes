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
    bool issame(TreeNode*p,TreeNode* q){
        if(p==NULL&& q==NULL)return true;
        if(p==NULL||q==NULL)return false;
        if(q->val==p->val){
            return issame(p->left,q->left)&&issame(p->right,q->right);
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return issame(p,q);
    }
};