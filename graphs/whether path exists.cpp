#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &vec, vector<vector<bool>> visi, int i, int j)
{
    int n = vec.size();
    // int m = visited[0].size();
    if((i<0 || i>= n) || (j<0 || j>=n))
        return false;
    if(vec[i][j] == 0)
        return false;
    if(vec[i][j] == 2)
    {
        // visi[i][j] = true;
        return true;
    }
    if(visi[i][j] == true && vec[i][j] == 3)
        return false;
    else if((visi[i][j] == false) &&(vec[i][j] == 3 || vec[i][j] == 1))
    {
        visi[i][j] = true;
        return ((dfs(vec, visi, i-1, j) || dfs(vec, visi, i+1, j)) || (dfs(vec, visi, i, j-1) || dfs(vec, visi, i, j+1)));
    }
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<vector<int>> vec(n, vector<int> (n));
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	            cin>>vec[i][j];
	    }
	    
	    vector<vector<bool>> visited(n, vector<bool> (n, false));
	    bool var, flag = false;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(vec[i][j] == 1)
	            {
	                var = dfs(vec, visited, i, j);
	                flag = true;
	                break;
	            }
	        }
	        if(flag)
	            break;
	    }
	    cout<<var<<"\n";
	}
	return 0;
}
