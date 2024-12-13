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
    void inorder(TreeNode* root,vector<int>&ar){
        if(root==NULL)return ;
        inorder(root->left,ar);
        ar.push_back(root->val);
        inorder(root->right,ar);
    }
    vector<int>mergersorted(vector<int>list1,vector<int>list2){
        int i1=0,i2=0;
        int l1=list1.size(),l2=list2.size();
        vector<int>ans;
        while(i1<l1&& i2<l2){
            if(list1[i1]>list2[i2]){
                ans.push_back(list2[i2]);
                i2++;
            }
            else{
                ans.push_back(list1[i1]);
                i1++;
            }
        }
        while(i1<l1){
            ans.push_back(list1[i1]);
            i1++;
        }
        while(i2<l2){
            ans.push_back(list2[i2]);
            i2++;
        }
        return ans;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>list1,list2;
        inorder(root1,list1);
        inorder(root2,list2);
        return mergersorted(list1,list2);
    }
};