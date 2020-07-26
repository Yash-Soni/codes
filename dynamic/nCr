#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,r;
    cin>>n>>r;
    cout<<nCrModp(n, r)<<"\n";
  }
  return 0;
}

int nCrModp(int n, int r) 
{ 
//   int num;
  if(r>n)
    return 0;
  if(n==0 || n==1)
    return 1;
  vector<int> vec(2,1);
  
  int j=2, num;
  while(j<=n)
  {
    vector<int> tem;
    tem.push_back(1);
    for(int i=1; i<j;i++)
    {
        num = (vec[i-1]+vec[i])%1000000007;
        tem.push_back(num);
    }
    tem.push_back(1);
    vec.clear();
    vec = tem;
    j++;
  }
  num = vec[r];
  return num;
} 
