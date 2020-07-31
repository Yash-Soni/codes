#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(int x, int y, int n, int m)
{
    if((x>=n || x<0) || (y>=m || y<0))
        return false;
        
    return true;
}

int find(vector<vector<int>> &matrix, vector<vector<bool>> &visi, queue<pair<pair<int, int>, int>> &q)
{
    int n = matrix.size(), m = matrix[0].size();
    int x, y, moves,maxmoves = 0;
    // visi[x][y] = true;
    while(q.size())
    {
        auto it = q.front();
        x = it.first.first;
        y = it.first.second;
        if(visi[x][y] == false)
            visi[x][y] = true;
        moves = it.second;
        maxmoves = max(moves, maxmoves);
        q.pop();
        if(matrix[x][y] == 0)
        {
            // visi[x][y] = true;
            continue;
        }
        else if(matrix[x][y] == 1)
        {
            matrix[x][y] = 2;
            // visi[x][y] = true;
        }
        int updown[] = {1, 0, -1, 0};
        int leftright[] = {0, 1, 0, -1};
        for(int k=0; k<4; k++)
        {
            int n1 = x+updown[k];
            int n2 = y+leftright[k];
            
            if(check(n1, n2, n, m))
            {
                if(visi[n1][n2] == false && matrix[n1][n2] != 0)
                {
                    // cout<<"\nn1 "<<n1<<" n2 "<<n2<<" moves "<<moves;
                    if(matrix[n1][n2] == 1)
                    {   
                        // matrix[n1][n2] = 2;
                        q.push(make_pair(make_pair(n1, n2), moves+1));
                    }
                    else
                        q.push(make_pair(make_pair(n1, n2), moves));
                    
                }
                visi[n1][n2] = true;
            }
        }
    }
    return maxmoves;
}

int rotOranges(vector<vector<int>> &matrix, int R, int C)
{
    // Your code goes here
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(R, vector<bool> (C, false));
    int moves, mn = INT_MIN;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(matrix[i][j] == 2)
            {
                if(visited[i][j] == false)
                {
                    q.push(make_pair(make_pair(i, j), 0));
                    // cout<<"\n here moves= "<<moves;
                }
                
            }
        }
    }
    moves = find(matrix, visited, q);
    if(mn < moves)
        mn = moves;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            
            if(matrix[i][j] == 1)
                return -1;
        }
    }
    return mn;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int R, C;
	    cin>>R>>C;
	    vector<vector<int>> matrix(R, vector<int> (C));
	    for(int i=0; i<R; i++)
	    {
	        for(int j=0; j<C; j++)
	            cin>>matrix[i][j];
	    }
	   // for(int i=0; i<R; i++)
	   // {
	   //     for(int j=0; j<C; j++)
	   //         cout<<matrix[i][j]<<" ";
	   //     cout<<"\n";
	   // }
	    
	    cout<<rotOranges(matrix, R, C)<<"\n";
	}
	return 0;
}
