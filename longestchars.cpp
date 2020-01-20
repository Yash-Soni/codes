#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
 {
	//code
	int i,n,t,m;
	cin>>t;
	while(t--)
	{
	    string s;
	    int count=0,max=0,a[26] ={0};
	    cin>>s;
	    n = s.length();
	    while(n > max)
	    {
	        for(i=0;i<n;i++)
	        {
	            a[s[i]-97]++;
	            if(a[s[i]-97] < 2)
	            {
	                count++;
	            }
	            else
	            {
	                if(max < count)
	                {
	                    //cout<<count<<" "<<s[i]<<"  "<<i<<"\n";
	                    max = count;
	                }
	                count = 1;
	                for(int j = 0;j<26;j++)		a[j] = 0;
	                a[s[i] - 97]++;
	            }
	        }
	        if(max < count)
	        {
                max = count;
	        }
	        reverse(s.begin(),s.end());
	        s.erase(n-1);
	        reverse(s.begin(),s.end());
	        n = s.length();
			count = 0;
	        for(int j = 0;j<26;j++)		a[j] = 0;
	    }
	    cout<<max<<"\n";
	}
	return 0;
}