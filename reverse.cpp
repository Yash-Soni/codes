#include<iostream>
#include<string.h>
using namespace std;
int main()
 {
	//code
	int i, n,t;
	string s;
	cin>>t;
	getchar();
	while(t--)
	{
	    getline(cin,s);
	    n = s.length();
	    int count;
	    char a[n];
	    int j=0,k=0, l=0;
	    for(i=0; i<n;i++)
	    {
	        if(((s[i] > 122) || (s[i] < 97))&&((s[i] <65)||(s[i] >90)))
	        {
	            while(j <= k)
	            {
	                swap(s[j], s[k]);
	                k--;
	                j++;
	            }
	            j=i+1;
	        }
	        else
	        {
	            k=i;
                continue;
            }
	    }
	    while(j <= k)
	    {
	       swap(s[j], s[k]);
	       k--;
	       j++;
	    }
	    j=n-1;  i=0;
	    while(i<=j)
	    {
	        swap(s[i], s[j]);
	        i++;    j--;
	    }
	    cout<<s<<"\n";
	}
	return 0;
}