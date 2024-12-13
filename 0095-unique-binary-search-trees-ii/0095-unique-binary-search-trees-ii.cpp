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
    vector<TreeNode*> generate(int l,int r){
        if(l<1||l>r)return {NULL};
        if(l==r){
            vector<TreeNode*>tem;
            TreeNode* head=new TreeNode(l);
            tem.push_back(head);
            return tem;
        } 
        vector<TreeNode*>ans;
        for(int i=l;i<=r;i++){
            vector<TreeNode*>leftpart=generate(l,i-1);
            vector<TreeNode*>rightpart=generate(i+1,r);
            for(int j=0;j<leftpart.size();j++){
                for(int k=0;k<rightpart.size();k++){
                    TreeNode* tem2=new TreeNode(i);
                    tem2->left=leftpart[j];
                    tem2->right=rightpart[k];
                    ans.push_back(tem2);
                }
            }
        }
        return ans;
          
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
};