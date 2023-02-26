#include<bits/stdc++.h>
using namespace std;
struct itmpr
{
    int i,p,w;
    float f;
};
int main()
{
    vector<struct itmpr> itm;
    int n=4;
    int p[n]={15,10,9,5};
    int w[n]={1,5,3,4};
    int cap=8;
    vector<vector<int>> mat(n+1,vector<int>(cap+1,0));
    int r=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            if(j>=w[r])
            {
                mat[i][j]=mat[i-1][j-w[r]]+p[r];
            }
            else
            {
                mat[i][j]=mat[i-1][j];
            }
        }
        r++;
    }
    int i=n;
    int j=cap;
    vector<int> picked;
    while(i>0)
    {
        if(mat[i][j]!=mat[i-1][j])
        {
            picked.push_back(i);
            j-=w[i-1];
        }
        i--;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            cout<<setw(3)<<mat[i][j];
        }
        cout<<endl;
    }
    for(double i: picked)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Profit:"<<mat[n][cap];
    return 0;
}