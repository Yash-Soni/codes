void dfs(vector<int> A[], int i, int j, vector<vector<bool>> &visited)
{
    // cout<<i<<" "<<j<<" N "<<N<<" M "<<M;
    int N = visited.size();
    int M = visited[0].size();
    if((i >= N || i<0) || (j<0 || j>=M))
    {
        return;
    }
    if(A[i][j] == 0 || visited[i][j] == true)
        return;
    // cout<<" hi\n";
    if(A[i][j] == 1 && visited[i][j] == false)
        visited[i][j] = true;
    // else if(A[i][j] == 0 || visited[i][j] == true)
        // return;

    dfs(A, i+1, j, visited);
    dfs(A, i+1, j-1, visited);
    dfs(A, i+1, j+1, visited);
    dfs(A, i, j+1, visited);
    dfs(A, i-1, j+1, visited);
    dfs(A, i-1, j-1, visited);
    dfs(A, i, j-1, visited);
    dfs(A, i-1, j, visited);
    
    return;
}

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    int numofIslands=0;
    vector<vector<bool>> visited(N, vector<bool> (M, false));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(A[i][j] == 1 && visited[i][j] == false)
            {
                dfs(A, i, j, visited);
                numofIslands++;
            }
        }
    }
    return numofIslands;
}
