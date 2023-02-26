#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
struct egstr
{
    cha src,dst;
    int cst;
};
int main()
{
    int v,e;
    cin>>v>>e;
    map<char,pair<int,char>> vrtgrp;
    vector<struct egstr> eedglst;
    cout<<"Enter Vertex"<<endl;
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
        vrtgrp[a]=(i==0)?make_pair(0,'*'):make_pair(0,' ');
    }
    cout<<"Edges"<<endl;
    for(int i=0;i<e;i++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        struct egstr tp={a,b,c};
        eedglst.push_back(tp);
    }
    for(auto i:vrtgrp)
    {
        cout<<i.first<<" "<<i.second.first<<" : ";
        char x=i.first;
        while(x!=srcc)
        {
            cout<<x<<"<--";
            x=vrtgrp[x].second;
        }
    }
    cout<<srcc;
}