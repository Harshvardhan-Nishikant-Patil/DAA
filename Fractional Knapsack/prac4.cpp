#include<bits/stdc++.h>
using namespace std;
struct itmprr
{
    int i,p,w;
    float f;
};
bool csrt(struct itmprr &a,struct itmprr &b)
{
    return a.f>b.f;
}
int main()
{
    vector<struct itmprr> itm;
    int n=4;
    int p[n]={10,20,2,5};
    int w[n]={3,4,1,2};
    int cap=7;
    for(int i=0;i<n;i++)
    {
        struct itmprr itmm={i+1,p[i],w[i],(double) p[i] / (double) w[i]};
        itm.push_back(itmm);
    }
    sort(itm.begin(),itm.end(),csrt);
    int tmp=cap;
    double pr=0;
    vector<double> picked(n,0);
    for(int i=0;i<itm.size();i++)
    {
        if(tmp>=itm[i].w)
        {
            tmp-=itm[i].w;
            pr+=itm[i].p;
            picked[i]=1;
        }
        else
        {
            picked[i]=(double)tmp/(double)itm[i].w;
            pr+=(picked[i]=(double)tmp/(double)itm[i].w)*(double)itm[i].p;
            tmp=(picked[i]=(double)tmp/(double)itm[i].w)*(double)itm[i].w;
            break;
        }
    }
    for(double i:picked)
    {
        cout<<i<<" "<<endl;
    }
    cout<<"Profit:"<<pr<<endl;
    cout<<"Weight:"<<cap<<endl;
    return 0;
}