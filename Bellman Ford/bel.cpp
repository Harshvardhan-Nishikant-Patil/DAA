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
    cout<<"Enter No. of Vertexs and Edges"<<endl;
    cin>>v>>e;
    map<char,pair<int,char>> vrtxgrp;
    vector<struct edgstr> edglst;

    cout<<"Enter Vertex Names:"<<endl;
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
        vrtxgrp[a]=(i==0)?make_pair(0,'*'):make_pair(INF,' ');
    }
    cout<<"Enter Edges"<<endl;
    for(int i=0;i<e;i++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        struct edgstr tp={a,b,c};
        edglst.push_back(tp);
    }
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(vrtxgrp[edglst[j].dst].first>vrtxgrp[edglst[j].src].first+edglst[j].cst)
            {
                vrtxgrp[edglst[j].dst].first=vrtxgrp[edglst[j].src].first+edglst[j].cst;
                vrtxgrp[edglst[j].dst].second=edglst[j].src;
            }
        }
    }
    bool nc=false;
    for(int j=0;j<e;j++)
    {
        if(vrtxgrp[edglst[j].dst].first>vrtxgrp[edglst[j].src].first+edglst[j].cst)
        {
            nc=true;
        }
    }
    if(nc)
    {
        cout<<"Negative Cycle:("<<endl;
        return 0;
    }
    for(auto i:vrtxgrp)
    {
        cout<<i.first<<" "<<i.second.first<<" : ";
        char x=i.first;
        while(x!=srcc)
        {
            cout<<" <-- ";
            x=vrtxgrp[x].second;
        }
        cout<<srcc<<endl;
    }
    return 0;
}