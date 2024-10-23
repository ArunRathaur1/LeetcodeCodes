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
    void InOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL)return ;
        InOrder(root->left,ans);
        ans.push_back(root->val);
        InOrder(root->right,ans);
    }
    void GetNode(TreeNode* root,TreeNode* &valueNode,int value){
        if(root==NULL)return;
        GetNode(root->left,valueNode,value);
        GetNode(root->right,valueNode,value);
        if(root->val==value){
            valueNode=root;
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        InOrder(root,ans);
        vector<int>ar=ans;
        int size=ar.size();
        int v1=0,v2=0;
        sort(ans.begin(),ans.end());
        int n=ar.size();
        for(int i=0;i<n;i++){
            if(ar[i]!=ans[i]){
                v1=ar[i];
                v2=ans[i];
                break;
            }
        }
        cout<<v1<<" "<<v2;
        TreeNode* r1=NULL;
        TreeNode* r2=NULL;
        GetNode(root,r1,v1);
        GetNode(root,r2,v2);
        r1->val=v2;
        r2->val=v1;

    }
};