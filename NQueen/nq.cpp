#include<bits/stdc++.h>
#define n 4
using namespace std;

void pr(int a[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool pl(int a[n][n],int r,int c)
{
    int i,j;
    for(i=0;i<c;i++)
    {
        if(a[r][i])
            return false;
    }
    for(i=r,j=c;i>=0 && j>=0; i--,j--)
    {
        if(a[i][j])
            return false;
    }
    for(i=r,j=c;j>=0 && i<n;i++,j--)
    {
        if(a[i][j])
            return false;
    }
    return true;
}

bool nq(int a[n][n],int c)
{
    if(c>=n)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(pl(a,i,c))
        {
            a[i][c]=1;
            if(nq(a,c+1))
                return true;
    
    a[i][c]=-1;
    }
}
return false;
}

bool slnq()
{
    int a[n][n]={{0,0,0,0},
                 {0,0,0,0 },
                 {0,0,0,0 },
                 {0,0,0,0 }
                 };
    if(nq(a,0)==false)
    {
        cout<<"No Solution Exist"<<endl;
        return false;
    }
    pr(a);
    return true;
}

int main()
{
    slnq();
    return 0;
}