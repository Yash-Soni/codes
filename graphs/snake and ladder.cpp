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

---------------------------------------------------------------------------------
	
	Leetcode solution:

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        vector<bool> visited(n*n+1, false);
        int row, col, num, moves=0, minmoves = n*n;
        q.push(1);
        while(q.size() != 0)
        {
            int count = q.size();
            for(int i=0; i<count; i++)
            {
                num = q.front();
                q.pop();
                
                if(num == n*n)
                {
                    minmoves = min(minmoves, moves);
                    return minmoves;
                }
                
                for(int k=1; k<=6; k++)
                {
                    int next_step = num+k;
                    if(next_step > n*n)
                    {
                        break;
                    }
                    // cout<<next_step<<" ";
                    if(visited[next_step] == false)
                    {    
                        visited[next_step] = true;
                        row = n - (next_step-1)/n - 1;
                        col = (n-row)%2 == 0 ? n - (next_step-1)%n - 1 : (next_step-1)%n;
                        // cout<<board[row][col]<<" , row "<<row<<" col "<<col<<"\n";
                        if(board[row][col] == -1)
                            q.push(next_step);
                        else
                        {
                            q.push(board[row][col]);
                        }
                    }
                }
            }
            moves++;
        }
        return minmoves == n*n ? -1 : minmoves;
    }
};

