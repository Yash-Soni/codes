#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minPalParti(string &s, int i, int j)
{
    if(i>j)
        return 0;
    int n= s.length();
    vector<vector<bool>> palincount(n, vector<bool>(n, false));
    for(int i=0;i<n; i++)
        palincount[i][i] = true;
    for(int i=0;i<n-1; i++)
    {
        palincount[i][i+1] = (s[i] == s[i+1])?true:false;
    }
    for(int len = 3; len<=n; len++)
    {
        int j = len-1, i =0;
        while(j<s.length())
        {
            if((s[i] == s[j]) && palincount[i+1][j-1])
                palincount[i][j] = true;
            // else
            //     palincount[i][j] = false;
            i++;
            j++;
        }
    }
    
    vector<int> count(n, INT_MAX);
    for(int i=0; i<n; i++)
    {
        if(palincount[0][i] == true)
            count[i] = 0;
        else
        {
            for(int j=0; j<i; j++)
            {
                if(palincount[j+1][i] && (count[i] > (count[j]+1)))
                    count[i] = 1+count[j];
            }
        }
    }
    return count[n-1];
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<minPalParti(s, 0, s.length()-1)<<"\n";
	}
	return 0;
}
