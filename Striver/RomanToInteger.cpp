class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        int arr[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int i=0, n=s.length();
        while(i<n) {
            if(i<n-1 && s[i] == 'I' && (s[i+1]=='V' || s[i+1] =='X')) {
                num=num-1;
            } else if(i<n-1 && s[i] == 'X' && (s[i+1]=='L' || s[i+1] =='C')) num=num-10;
            else if(i<n-1 && s[i] == 'C' && (s[i+1]=='D' || s[i+1] =='M')) num-=100;
            else {
                if(s[i]=='I') num++;
                else if(s[i]=='V') num+=5;
                else if(s[i]=='X') num+=10;
                else if(s[i]=='L') num+=50;
                else if(s[i]=='C') num+=100;
                else if(s[i]=='D') num+=500;
                else if(s[i]=='M') num+=1000;
            }
            i++;
        }
        return num;
    }
};
