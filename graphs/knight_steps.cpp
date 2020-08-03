int bfs(int N, vector<vector<bool>> &visited, queue<pair<pair<int, int>,int>> &q, int target[])
{
    if(q.size() == 0)
        return 0;
    int n1, n2, moves;
    n1 = q.front().first.first;
    n2 = q.front().first.second;
    
    if((n1>N || n1<0) || (n2>N || n2<0))
        return INT_MAX;
    if(visited[n1][n2] == true)
        return INT_MAX;
        
    while(q.size())
    {
        auto it = q.front();
        q.pop();
        n1 = it.first.first;
        n2 = it.first.second;
        moves = it.second;
        
        if(n1 == target[0] && n2 == target[1])
            return moves;
        
        int updn[8] = {2, 2, -2, -2, 1, 1, -1, -1};
        int lr[8] = {1, -1, 1, -1, 2, -2, 2, -2};
        
        moves++;
        for(int k=0; k<8; k++)
        {
            int num1 = n1+updn[k];
            int num2 = n2+lr[k];
            if((num1>N || num1<0) || (num2>N || num2<0))
                continue;
            if(visited[num1][num2] == false)
            {
                visited[num1][num2] = true;
                q.push(make_pair(make_pair(num1, num2), moves));
            }
        }
    }
}

int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    // code here
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(N+1, vector<bool> (N+1, false));
    q.push(make_pair(make_pair(knightPos[0], knightPos[1]), 0));
    
    int count = bfs(N, visited, q, targetPos);
    
    return count;
}
