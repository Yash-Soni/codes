class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long long number=0;
        bool negative=false, num=false;
        for(int i=0; i<n; i++) {
          if(!num) {

            if(s[i] == ' ') {
              continue;
            } else if(s[i] == '-') {
              negative=true;
              num=true;
            } else if(s[i] == '+') {
              negative = false;
              num=true;
            } else if(s[i]>=48 && s[i]<=57) {
              num=true;
              number += (s[i]-'0');
            } else return 0;
          } else {
            if(s[i]>=48 && s[i]<=57) {
              number *= 10;
              number += (s[i]-'0');
              if(number > INT_MAX) break;
            } else break;
          }
        }
        if(negative) number *= (-1);
        if(number < INT_MIN) return INT_MIN;
        if(number > INT_MAX) return INT_MAX;
        return number;
    }
};
