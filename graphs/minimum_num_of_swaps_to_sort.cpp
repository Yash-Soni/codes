int minSwaps(int arr[], int N){
    /*Your code here */
    pair<int, int> arrpos[N];
    vector<bool> visited(N, false);
    for(int i=0; i<N; i++)
    {
        arrpos[i] = make_pair(arr[i], i);
    }
    sort(arrpos[], arrpos[]+N);
    
    int cycle=0, swaps, k=0, ind;
    
    for(int i=0; i<N; i++)
    {
        if(visited[i] == true || i == arrpos[i].second)
        {
            continue;
        }    
        else
        {
            ind = arrpos[i].second;
            k=0;
            while(visited[ind] == false)
            {
                visited[ind] = true;
                k++;
                ind = a[ind].second;
            }
            if(k>0)
                cycle += k-1;
        }
    }
    return cycle;
}
