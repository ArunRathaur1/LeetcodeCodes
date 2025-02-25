class Solution {
    public int myAtoi(String s) {
        int sign=0;
        long  number=0;
        int index=0;
        while(index<s.length()&&s.charAt(index)==' ')index++;
        if(index<s.length()&&s.charAt(index)=='-'){
            sign=1;
            index++;
        }
        else if(index<s.length()&&s.charAt(index)=='+'){
            index++;
        }
        int l=s.length();
        for(int i=index;i<l;i++){
            if(s.charAt(i)>='0'&& s.charAt(i)<='9'){
                number=number*10+(s.charAt(i)-'0');
            }
            else break;
            if(number*-1<=Integer.MIN_VALUE&& sign==1)return Integer.MIN_VALUE;
            else if(number>=Integer.MAX_VALUE&& sign==0)return Integer.MAX_VALUE;
            
        }
        if(sign==1){
            return -1*(int)number;
        }
        else{
            return (int)number;
        }

    }
}