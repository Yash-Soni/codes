#include<iostream>
#include<string.h>
using namespace std;
int main()
 {
	//code
	int i,j,n,t;
	
	cin>>t;
	while(t--)
	{
	    //queue<char> q;
	    cin>>n;
	    string s;
	    cin>>s;
	    //n = s.length();
	    int a[26] = {0},flag = 0;
	    char c,ch;
	    
		for(i=0;i<n;i++)
		{
			a[s[i]-97]++;
		}
		i=0;
		while(i<n)
		{
			if(a[s[i]-97] == 1)
			{
				c = s[i];
				flag = 1;
				break;
			}
			i++;
		}
		if(flag == 1)
		{
			cout<<c<<"\n";
		}
		else
		{
			cout<<"-1\n";
		}
	}
	return 0;
}