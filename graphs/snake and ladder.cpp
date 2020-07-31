#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int> &adj, vector<bool> &visited, queue<pair<int, int>> &q, vector<int> &moves, int source)
{
    // int num;
    int n = adj.size();
    while(q.size()!=0)
    {
        auto it = q.front();
        int ind = it.first;
        int num = it.second;
        q.pop();
        for(int k=1; k<=6; k++)
        {
            if((ind+k)<n && visited[ind+k] == false)
            {
                int destination = max(ind+k, adj[ind+k]);
                q.push(make_pair(destination, num+1));
                visited[ind+k] = true;
                moves[destination] = min(num+1, moves[ind+k]);
            }
        }
    }
    return moves[30];
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,y;
	    cin>>n;
	    vector<int> adj(31, -1);
	    for(int i=0; i<n; i++)
	    {
	        cin>>x>>y;
	        adj[x] = y;
	    }
	    vector<bool> visited(31, false);
	    vector<int> moves(31,INT_MAX);
	    queue<pair<int, int>> q;
	    q.push(make_pair(1, 0));
	    visited[1] = true;
	    moves[1] = 0;
	    int num = bfs(adj, visited, q, moves, 1);
	    cout<<num<<"\n";
	}
	return 0;
}
