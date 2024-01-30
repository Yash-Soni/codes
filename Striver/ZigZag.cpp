class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if(numRows >= s.length() || numRows == 1) return s;
        int n = s.length(), i=0, j=0;
        
        for(int r=0; r<numRows; r++) {
          i = r;
          bool up=true;
          while(i<n) {
            result += s[i];
            if(r==0 || r == numRows-1) {
              i+= (2*(numRows-1));
            } else {
              if(up) {
                i += 2*(numRows - r - 1);
              } else {
                i += r*2;
              }
              up ^= true;
            }
          }
        }
        return result;
    }
};
