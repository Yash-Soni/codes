class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int len = s.length();
    if(len==0 || len==1) return len;
    int substr=0, maxlen=0, i=0;
    string s1="";
    while(i<len) {
      if(s1.find(s[i]) < s1.length()) {
        substr=s1.length();
        maxlen = max(substr, maxlen);
        int index = s1.find(s[i]);
        s1.erase(0, index+1);
      }
      s1.push_back(s[i++]);
    }
    if(maxlen < s1.length()) {
      maxlen = s1.length();
    }
    return maxlen;
  }
};
