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
    void preordertravel(TreeNode* root,TreeNode* &ListNode){
        if(root==NULL)return ;
        TreeNode* newnode=new TreeNode(root->val);
        ListNode->left=NULL;
        ListNode->right=newnode;
        ListNode=newnode;
        preordertravel(root->left,ListNode);
        preordertravel(root->right,ListNode);
    }
    void flatten(TreeNode* root) {
        if(root==NULL)return ;
        TreeNode* ListNode=new TreeNode(0);
        TreeNode* tem=ListNode;
        preordertravel(root,ListNode);
        root->left=NULL;
        root->right=tem->right->right;
    }
};