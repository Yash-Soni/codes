class Solution {
public:
    double myPow(double x, int n) {
        if(x==0 || x==1) return x;
        if(n==0) return 1;
        double ans=1;
        int i=0;
        long long nn=n;
        if(nn<0) nn=-nn;
        
        while(nn>0) {
            if(nn%2==0) {
                x=x*x;
                nn/=2;
            } else {
                ans *= x;
                nn--;
            }
        }
        if(n<0) {
            ans = 1/ans;
        }
        return ans;
    }
};
