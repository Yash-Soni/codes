class Solution {
public:
    bool isPalindrome(string s) {
        int i,j,n;
        n = s.length();
        if(n == 0 || n==1)
            return true;
        for(i=0 ;i < n ; i++)
        {
            if((s[i] > 64 && s[i] < 91))
            {
                s[i] = s[i] + 32;
            }
            else if(s[i] > 96 && s[i] < 123)
            {
                continue;
            }
            else if(s[i] > 46 && s[i]<58)
                continue;
            else
            {
                if(i <= s.length()-1)
                {
                    s.erase(i,1);
                    i--;
                    n--;
                }
            }
        }
        j = s.length()-1;
        for(i=0,j; i<=j ;i++,j--)
        {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
};