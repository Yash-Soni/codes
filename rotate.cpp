#include<iostream>
#include<string.h>
using namespace std;
int main()
 {
	//code
	int i,n,m,t;
	cin>>t;
    string s1,s2,tem,res;
	getchar();
	while(t--)
	{
        cin>>s1;
	    cin>>s2;
	    n = s1.length();
	    m = s2.length();
	    int flag =0,j,k;
	    if(n != m)
	    {
	        flag = 1;
	    }
	    else
	    {
	        for(i=0; i<n; i++)
	        {
	            tem = tem+s1[i];
	            j = i+1;
	            while(j!=n)
	            {
	                res = res+s1[j];
	                j++;
	            }
	            res = res+tem;
	            k = res.compare(s2);
	            if(k == 0)
	            {
					flag = 0;
	                break;
	            }
	            else
	            {
					flag = 1;
	                //tem.clear();
	                res.clear();
	            }
	        }
	    }
	    if(flag == 0)
	    {
	        cout<<"1\n";
	    }
	    else
	        cout<<"0\n";
		s1.clear();
        s2.clear();
		tem.clear();
		res.clear();
		getchar();
	}
	return 0;
}