#include<bits/stdc++.h>
using namespace std;
struct impr
{
    int i,p,w;
    float f;
};
bool csrt(struct impr &a,struct impr &b)
{
    return a.f>b.f;
}
int main()
{
    vector<struct impr> itt;
    int n=4;
    int p[n]={15,10,9,5};
    int w[n]={1,5,3,4};
    int cap=8;
    for(int i=0;i<n;i++)
    {
        struct impr ti={i+1,p[i],w[i],(double) p[i]/(double) w[i]};
        itt.push_back(ti);
    }
    sort(itt.begin(),itt.end(),csrt);
    int tmp=cap;
    double pr=0;
    vector<double> picked(n,0);
    for(int i=0;i<itt.size();i++)
    {
        if(tmp>=itt[i].w)
        {
            tmp-=itt[i].w;
            pr+=itt[i].p;
            picked[i]=1;
        }
        else
        {
            picked[i]=(double) tmp/(double) itt[i].w;
            pr+=((double)tmp/(double)itt[i].w)*(double) itt[i].p;
            tmp-=((double)tmp/(double) itt[i].w)*(double) itt[i].w;
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