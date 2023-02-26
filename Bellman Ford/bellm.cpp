#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
struct vrtstr
{
    char src,dst;
    int cst;
};
int main()
{
    int v,e;
    cout<<"Enter No. of Vertex and Edges"<<endl;
    cin>>v>>e;
    map<char,pair<int,char>> vrtgrp;
    vector<struct vrtstr> edglst;
    cout<<"Enter names:"<<endl;
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
        vrtgrp[a]=(i==0)?make_pair(0,'*'):make_pair(INF,' ');
    }
    cout<<"Enter edges"<<endl;
    for(int i=0;i<e;i++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        struct vrtstr tp={a,b,c};
        edglst.push_back(tp);
    }
    
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(vrtgrp[edglst[j].dst].first > vrtgrp[edglst[j].src].first + edglst[j].cst)
            {
                vrtgrp[edglst[j].dst].first = vrtgrp[edglst[j].src].first + edglst[j].cst;
                vrtgrp[edglst[j].dst].second=edglst[j].src;
            }
        }
    }

    //negative cycle

    bool cy=false;
    for(int i=0;i<e;i++)
    {
        if(vrtgrp[edglst[j].dst].first > vrtgrp[edglst[j].src].first + edglst[j].cst)
        {
            cy=true;
        }
    }

    if(cy)
    {
        cout<<'Negative Cycle:(';
        return 0;
    }
    for(auto i:vrtgrp)
    {
        cout<<i.first<<" "<<i.second.first<<" : ";
        char x=i.first;
        while(x!= srcc)
        {
            cout<<x<<'<--';
            x=vrtgrp[x].second;
        }
        cout<<srcc<<endl;
    }
    return 0;
}