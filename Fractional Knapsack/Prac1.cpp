#include<bits/stdc++.h>
using namespace std;
struct Itempair
{
    int i,p,w;
    float f;
};

bool csort(struct Itempair &a,struct Itempair &b)
{
    return a.f>b.f;
}

int main()
{
    vector<struct Itempair> itm;
    int n=4;
    int p[n]={15,10,9,5};
    int w[n]={1,5,3,4};
    int cap=8;
    for(int i=0;i<n;i++)
    {
        struct Itempair itv={i+1,p[i],w[i],(double) p[i]/(double) w[i]};
        itm.push_back(itv);
    }
    sort(itm.begin(),itm.end(),csort);
    int tmp=cap;
    double profit=0;
    vector<double> picked(n,0);
    for(int i=0;i<itm.size();i++)
    {
        if(tmp>=itm[i].w)
        {
            tmp-=itm[i].w;
            profit+=itm[i].p;
            picked[i]=1;
        }
        else
        {
            picked[i]=(double) tmp/(double) itm[i].w;
            profit+=((double) tmp/(double) itm[i].w)*(double) itm[i].p;
            tmp-=((double) tmp/(double) itm[i].w)*(double) itm[i].w;
            break;
        }
    }


    for(double i:picked)
    {
        cout<<i<<" ";
        cout<<"\t";

    }
    cout<<endl;
     cout<<"Profit:"<<profit<<endl;
        cout<<"Weight:"<<cap<<endl;
    return 0;
}