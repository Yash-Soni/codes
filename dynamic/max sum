#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(int [], int)

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
    }
    cout<<maxSumSubarray(a, n)<<"\n";
  }
  return 0;
}

int maxSumSubarray(int A[], int n)
{
    //Your code here
    vector<int> dpforward(n, 0), dpback(n, 0);
    int curmax=A[0], maxnum=A[0];
    dpforward[0] = A[0];
    //imp assignment
    dpback[n-1] = A[n-1];
    for(int i=1; i<n; i++)
    {
        curmax = max(A[i], curmax+A[i]);
        maxnum = max(curmax, maxnum);
        
        dpforward[i] = curmax;
    }
    curmax = A[n-1];
    maxnum = A[n-1];
    
    for(int i=n-2; i>=0; i--)
    {
        curmax = max(A[i], curmax+A[i]);
        maxnum = max(curmax, maxnum);
        
        dpback[i] = curmax;
    }
    int num = maxnum, tem;
    for(int i=1; i<n-1; i++)
    {
        num = max(num, dpforward[i-1]+dpback[i+1]);
        // if(tem > num)
        //     num = tem;
    }
    return num;
}
