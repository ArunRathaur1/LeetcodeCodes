#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> pq;
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (auto it : freq) {
            pq.push({it.first, it.second});
        }

        string ans = "";

        while (!pq.empty()) {
            pair<int,int>x=pq.top();
            char ch=x.first;
            int count=x.second;
            pq.pop();
            int useCount = min(count, repeatLimit);
            ans.append(useCount, ch);
            if (count > repeatLimit) {
                if (pq.empty()) {
                    break;
                }
                pair<char,int> y=pq.top();
                int nextCount=y.second;
                int nextCh=y.first;
                pq.pop();
                ans += nextCh;
                nextCount--;

                if (nextCount > 0) {
                    pq.push({nextCh, nextCount});
                }

                pq.push({ch, count - repeatLimit});
            }
        }

        return ans;
    }
};