#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
struct edgstr
{
    char src,dst;
    int cst;
};
int main()
{
    int v,e;
    cout<<"Enter No. Vertex and Edge";
    cin>>v>>e;
    map<char,pair<int,char>> vtxgrp;
    vector<struct edgstr> edglst;
    cout<<"Enter Vertex Name:";
    bool flag=true;
    char srcc;
    for(int i=0;i<v;i++)
    {
        char a;
        cin>>a;
        if(flag)
        {
            flag=false;
            srcc=a;
        }
        vtxgrp[a]=(i==0)?make_pair(0,'*'):make_pair(INF,' ');
    }
    cout<<"Enter Edges:"<<endl;
    for(int i=0;i<e;i++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        struct edgstr tmp={a,b,c};
        edglst.push_back(tmp);
    }
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(vtxgrp[edglst[j].dst].first>vtxgrp[edglst[j].src].first + edglst[j].cst)
            {
                vtxgrp[edglst[j].dst].first=vtxgrp[edglst[j].src].first+edglst[j].cst;
                vtxgrp[edglst[j].dst].second=edglst[j].src;
            }
        }
    }
    bool ncy=false;
    for(int j=0;j<e;j++)
    {
        if(vtxgrp[edglst[j].dst].first>vtxgrp[edglst[j].src].first+edglst[j].cst)
        {
            ncy=true;
        }
    }
    if(ncy)
    {
        cout<<"Negative Cycle"<<endl;
        return 0;
    }
    for(auto i:vtxgrp)
    {
        cout<<i.first<<" "<<i.second.first<<" : ";
        char x=i.first;
        while(x!=srcc)
        {
            cout<<x<<"<=="<<endl;
            x=vtxgrp[x].second;
        }
        cout<<srcc<<endl;
    }
    return 0;
}
