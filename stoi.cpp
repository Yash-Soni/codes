 #include<iostream>
 #include<string.h>
 using namespace std;
 
int myAtoi(string str)
{
        int i,n,j,size,flag =0;
        n = str.length();
        string z;
        j =0;
        for(i=0;i<n;i++)
        {
            if((str[i] == 32) &&(flag == 0))
            {
                continue;               
            }
            else if(str[i] > 47 && str[i] < 58)
            {
                z = z+str[i];
                j++;
                if(flag == 0)
                    flag = 2;
                else if(flag == 1)
                    flag = 1;
            }
            else if( str[i] == 45 || str[i] == 43)
            {
                if((str[i] == 45)&&(flag == 0))
                {
                    flag =1;
                }
                else if((str[i] == 43) &&(flag == 0))
                {
                    flag =2;
                }
                else
                {
                    if(flag == 1)   flag = 1;
                    else if(flag == 2)   flag = 2;
                    break;
                }
            }
            else
            {              
                break;
            }
        }
        long long int x =0;
        for(i=0;i<j;i++)
        {
            x = x*10;
            x += (z[i]-48);
            if(x > INT_MAX)
                break;
        }
        if(flag == 1)
        {
            x = x*(-1);
            if(x < INT_MIN)
                x = INT_MIN;
        }
        else if(flag == 0 || flag == 2)
        {
            if(x > INT_MAX)
                x = INT_MAX;
        }
        return x;
}


    int main()
    {
        string s;
        int i,t;
        cin>>t;
        while(t--)
        {
            getchar();
            getline(cin,s);
            i = myAtoi(s);
            cout<<i<<"\n";
        }
        return 0;
    }