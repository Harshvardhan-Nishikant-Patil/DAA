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
    cout<<"Enter Vertex and Edge"<<endl;
    cin>>v>>e;
    map<char,pair<int,char>> vrtxgrp;
    vector<struct edgstr> edlst;
    cout<<"Enter Name:"<<endl;
    for(int i=0;i<v;i++)
    {
        char a;
        cin>>a;
        vrtxgrp[a]=(i==0)?make_pair(0,'*'):make_pair(INF,' ');
    }
    cout<<"Enter Edge:"<<endl;
    for(int i=0;i<e;i++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        struct edgstr tmp={a,b,c};
        edlst.push_back(tmp);
    }
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(vrtxgrp[edlst[j].dst].first > vrtxgrp[edlst[j].src].first+edlst[j].cst)
            {
                vrtxgrp[edlst[j].dst].first = vrtxgrp[edlst[j].src].first+edlst[j].cst;
                vrtxgrp[edlst[j].dst].second=edlst[j].src;
            }
        }
    }
    bool ncyc=false;
    for(int j=0;j<e;j++)
    {
        if(vrtxgrp[edlst[j].dst].first>vrtxgrp[edlst[j].src].first+edlst[j].cst)
        {
            ncyc=true;
        }
    }
    if(ncyc)
    {
        cout<<"Negative Edgecycle Occured:("<<endl;
        return 0;
    }
    for(auto i:vrtxgrp)
    {
        cout<<i.first<<" "<<i.second.first<<" : ";
        char x=i.first;
        while(x!='1')
        {
            cout<<x<<"<--";
            x=vrtxgrp[x].second;
        }
        cout<<1<<endl;
    }
    return 0;
}
