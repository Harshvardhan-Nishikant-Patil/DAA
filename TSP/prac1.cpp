#include<bits/stdc++.h>
using namespace std;

int row(vector<vector<int>> &mat)
{
    int c=0;
    for(int i=0;i<mat.size();i++)
    {
        int mn=INT_MAX;
        for(int j=0;j<mat.size();j++)
        {
            if(mat[i][j]!=-1)
            {
                mn=min(mn,mat[i][j]);
            }
        }
            if(mn==INT_MAX)
            {
                mn=0;
            }
            for(int j=0;j<mat.size();j++)
            {
                if(mat[i][j]!=-1)
                {
                    mat[i][j]-=mn;
                }
        }
        c+=mn;
    }
    return c;
}

int col(vector<vector<int>> &mat)
{
    int c=0;
    for(int i=0;i<mat.size();i++)
    {
        int mn=INT_MAX;
        for(int j=0;j<mat.size();j++)
        {
            if(mat[i][j]!=-1)
            {
                mn=min(mn,mat[j][i]);
            }
        }
        if(mn==INT_MAX)
        {
            mn=0;
        }
        for(int j=0;j<mat.size();j++)
        {
            if(mat[j][i]!=-1)
            {
                mat[j][i]-=mn;
            }
        }
        c+=mn;
    }
    return c;
}

void chnmat(int row,int col,vector<vector<int>> &mat)
{
    for(int i=0;i<mat.size();i++)
    {
    mat[i][col]=-1;
    mat[row][i]=-1;
    }
    mat[col][row]=-1;
    mat[col][0]=-1;
}

void dis(vector<vector<int>> &mat)
{
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat.size();j++)
        {
            cout<<<setw(3)<<mat[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n,0))
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    int r=row(mat);
    int c=col(mat);
    cout<<"Initial: "<<r+c<<endl;
    vector<pair<int,int>> pth;
    pth.push_back({0,r+c});
    set<int> vld;
    for(int i=1;i<n;i++)
    {
        vld.insert(i);
    }
    while(vld.size())
    {
        pair<int,int> minn={INT_MAX,INT_MAX};
        vector<vector<int>> min_mat;
        for(int i=1;i<n;i++)
        {
            if(vld.find(i)==vld.end())
            {
                continue;
            }
            vector<vector<int>> tmpmat=mat;
            chnmat(pth.back().first,i,tmpmat);
            r=row(tmpmat);
            c=col(tmpmat);
            int c=r+c+mat[pth.back().first][i]+pth.back().second;
            dis(tmpmat);
            cout<<pth.back().first<<"TO"<<i<<":"<<c<<endl;
            if(c<minn)
            {
                minn={i,c};
                min_mat=tmpmat
            }
        }
        mat=min_mat;
        pth.push_back(minn);
        vld.erase(minn.first);
    }
    cout<<"Path"<<endl;
    for(auto i:pth)
    {
        cout<<i.first+1<<" ";
    }
    cout<<1<<endl;
    cout<<"Final:"<<pth.back().second<<endl;
    return 0;
}