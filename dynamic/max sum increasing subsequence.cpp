#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, x;
	    cin>>n;
	    vector<int> vec;
	    for(int i=0; i<n; i++)
	    {
	        cin>>x;
	        vec.push_back(x);
	    }
	    long int sum = 0, max_sum = 0;
	    vector<int> dp;
	    vector<int> sequence;
        dp = vec;
        for(int i=0; i<n; i++)
        {
            sequence.push_back(i);
        }
        // cout<<"\n";
	    for(int i=1; i<n; i++)
	    {
	        for(int j=0; j<i; j++)
	        {
	            if(vec[j] < vec[i])
	            {   
                    // cout<<dp[i]<<" "<<dp[j]<<"\n";
                    if(dp[i] < vec[i] + dp[j])
    	            {
                        dp[i] = max(dp[i], dp[j] + vec[i]);
                        sequence[i] = j;
                    }
                    
	            }
	        }
	    }
        max_sum = *max_element(dp.begin(), dp.end());
	    cout<<max_sum<<"\n";
	    // for(int i=0; i<out.size(); i++)
	    // {
	    //     cout<<vec[out[i]]<<" ";
	    // }
        // cout<<"\n";
	}
	
	return 0;
}
