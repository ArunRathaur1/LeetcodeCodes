#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int l=nums.size();
        for(int i=0;i<l;i++){
            q.push({nums[i],i});
        } 
        while(k--){
            pair<int,int>x=q.top();
            q.pop();
            q.push({x.first*multiplier,x.second});
        }  
        while(!q.empty()){
            pair<int,int>x=q.top();
            nums[x.second]=x.first;
            q.pop();
        } 
        return nums;
    }
};