class Solution(object):
    def lenLongestFibSubseq(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        s=set()
        for i in arr:
            s.add(i)
        p=len(arr)
        ans=0
        for i in range(0,p,1):
            for j in range(i+1,p,1):
                a=arr[i]
                b=arr[j]
                count=2
                while (a+b) in s:
                    c=a+b
                    a=b
                    b=c
                    count=count+1
                ans=max(ans,count)
        
        if ans>2: return ans
        return 0
        