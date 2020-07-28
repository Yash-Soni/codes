bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return (a.first.first*a.first.second) > (b.first.first*b.first.second);
}

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    int num = 3*n;
    vector<pair<pair<long int, long int>, long int>> vec;
    for(int i=0; i<n; i++)
    {
        int n1, n2, n3;
        n1 = max(length[i], width[i]);
        n2 = min(length[i], width[i]);
        vec.push_back(make_pair(make_pair(n1, n2), height[i]));
        n1 = max(length[i], height[i]);
        n2 = min(length[i], height[i]);
        vec.push_back(make_pair(make_pair(n1, n2), width[i]));
        n1 = max(width[i], height[i]);
        n2 = min(width[i], height[i]);
        vec.push_back(make_pair(make_pair(n1, n2), length[i]));
    }
    
    sort(vec.begin(), vec.end(), cmp);
    // for(auto i:vec)
    // {
    //     cout<<i.first.first<<" "<<i.first.second<<"-> "<<i.second<<"\n";
    // }
    vector<int> seq, hsum;
    for(int i=0; i<num; i++)
    {
        hsum.push_back(vec[i].second);
    }
    for(int i=1; i<num; i++)
    {
        int j=0;
        while(j<i)
        {
            if((vec[j].first.first > vec[i].first.first) && (vec[j].first.second > vec[i].first.second))
            {
                if(hsum[i] < hsum[j]+vec[i].second)
                {
                    hsum[i] = hsum[j]+vec[i].second;
                    // seq[i] = j;
                }
            }
            // else 
            //     break;
            j++;
        }
    }
    
    // cout<<dp[0]<<" ";
    return *max_element(hsum.begin(), hsum.end());
}
