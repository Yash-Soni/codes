class Solution {
public:
    void solve(string s, string& palin) {
      int n=s.length();
      int maxlen=0;
      
      for(int mid=0; mid<n; mid++) {
        int len=0, x=0;
        cout<<"mid: "<<mid<<", s[mid]:"<<s[mid]<<endl;
        for(; mid-x>=0 && mid+x < n; x++) {
          if(s[mid-x] != s[mid+x]) {
            cout<<"s[mid-x]:"<<s[mid-x]<<", s[mid+x]"<<s[mid+x]<<endl;
            break;
          }  
          len=2*x+1;
          if(len > maxlen) {
            maxlen = len;
            palin = s.substr(mid-x, maxlen);
            cout<<"maxlen: "<<maxlen<<", index: "<<mid-x<<", palin: "<<palin<<endl;
          }
        }
      }
      for(int mid=0; mid<n-1; mid++) {
        int len=0, x=1;
        for(; mid-x+1>=0 && mid+x<n; x++) {
          if(s[mid-x+1] != s[mid+x]) {
            break;
          }
          len=2*x;
          if(len > maxlen) {
            maxlen = len;
            palin = s.substr(mid-x+1, maxlen);
            cout<<"maxlen: "<<maxlen<<", index: "<<mid-x<<", palin: "<<palin<<endl;
          }
        }
      }
    }

    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1) return s;
        string palin="";
        solve(s, palin);
        return palin;
    }
};
