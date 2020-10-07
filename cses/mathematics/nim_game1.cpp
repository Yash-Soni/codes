#include<bits/stdc++.h>

using namespace std;

#define intt    long int
#define veci    vector<int>
#define ll      long long
#define ff      first
#define ss      second
#define pb      push_back
#define mk      make_pair
#define mpi     map<int,int>
#define mod     1000000007  //1e9+7
#define w(t)    int t;  cin>>t; while(t--)
#define take_in_vec(n)     intt x; veci vec; for(intt i=0; i<n; i++) {cin>>x;     vec.pb(x);}

void fastr()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int updn4[4] = {1, 0, -1, 0};
int leri4[4] = {0, 1, 0, -1};

int updn8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int leri8[8] = {1, 0, -1, 1, -1, 1, 0, -1};

bool check(int n, int m, int x, int y)
{
    if((x<n && x>=0) && (y<m && y>=0))
        return true;
    return false;
}

int main()
{
    fastr();
    w(t)
    {
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0; i<n; i++)
            cin>>vec[i];
        int a = 0;
        for(int i=0; i<n; i++)
            a ^= vec[i];
        if(a != 0)
            cout<<"first\n";
        else
        {
            cout<<"second\n";
        }
    }
    return 0;
}
