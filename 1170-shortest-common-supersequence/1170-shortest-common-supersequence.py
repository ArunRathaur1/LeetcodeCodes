class Solution(object):
    def shortestCommonSupersequence(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        l1=len(str1)
        l2=len(str2)
        dp=[]
        for i in range(l1+1):
            p=[]
            for j in range( l2+1):
                p.append(0)
            dp.append(p)
        for i in range(1,l1+1):
            for j in range(1,l2+1):
                if str1[i-1]==str2[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j])
        ans=[]
        d=l1
        r=l2
        while(d>0 and r>0):
            if str1[d-1]==str2[r-1]:
                ans.append(str1[d-1])
                d=d-1
                r=r-1
            elif dp[d][r-1]>dp[d-1][r]:
                ans.append(str2[r-1])
                r=r-1
            else:
                ans.append(str1[d-1])
                d=d-1
        while(d>0):
            ans.append(str1[d-1])
            d=d-1
        while(r>0):
            ans.append(str2[r-1])
            r=r-1
        return "".join(reversed(ans))