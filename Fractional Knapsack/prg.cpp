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
    for(int i=0;i<n;i++)
    {
        struct itmpr itv={i+1,p[i],w[i],(double)p[i]/(double)w[i]};
        itm.push_back(itv);
    }
    sort(itm.begin(),itm.end(),csrt);
    int tmp=cap;
    double pr=0;
    vector<double> pick(n,0);
    for(int i=0;i<itm.size();i++)
    {
        if(tmp>=itm[i].w)
        {
            tmp-=itm[i].w;
            pr+=itm[i].p;
            pick[i]=1;
        }
        else
        {
            pick[i]=(double)tmp/(double)itm[i].w;
            pr+=((double)tmp/(double)itm[i].w)*(double)itm[i].p;
            tmp+=((double)tmp/(double)itm[i].w)*(double)itm[i].w;
            break;
        }
       
    }
    for(double i:pick)
    {
        cout<<i<<" ";
        cout<<endl;
    }
    cout<<pr;
    cout<<cap;
    return 0;

}