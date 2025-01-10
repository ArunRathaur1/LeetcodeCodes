/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // TreeNode* Tree(vector<int>values,int left,int right){
    //     if(left>right)return NULL;
    //     int mid=(left+right)/2;
    //     TreeNode* root=new TreeNode(values[mid]);
    //     root->left=Tree(values,left,mid-1);
    //     root->right=Tree(values,mid+1,right);
    //     return root;
    // }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* prev=NULL;
        ListNode* slowprev=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            prev=slowprev;
            slowprev=slowprev->next;
        }
        TreeNode* root=new TreeNode(slowprev->val);
        if(prev!=NULL){
            prev->next=NULL;
            root->left=sortedListToBST(head);
        }
        root->right=sortedListToBST(slowprev->next);
        return root;
    }
};