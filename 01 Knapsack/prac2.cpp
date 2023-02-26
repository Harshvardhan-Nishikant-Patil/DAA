#include<bits/stdc++.h>
using namespace std;
struct itmpr
{
    int i,p,w;
    float f;
};
bool csrt(struct itmpr &a,struct itmpr &b)
{
    return a.f>b.f;
}
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
            
        }
    }
}