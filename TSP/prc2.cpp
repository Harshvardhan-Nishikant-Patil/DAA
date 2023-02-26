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
                mn=min(mn,mat[i][j]);
        }
        if(mn==INT_MAX)
            mn=0;
        for(int j=0;j<mat.size();j++)
        {
            if(mat[i][j]!=-1)
                mat[i][j]-=mn;
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
            if(mat[j][i]!=-1)
                mn=min(mmn,mat[j][i]);
        }
        if(mn==INT_MAX)
            mn=0;
        for(int j=0;j<mat.size();j++)
        {
            if(mat[j][i]!=-1)
                mat[j][i]-=mn;
        }
        c+=mn;
    }
return c;
}
void dis(vector<vector<int>> &mat)
{
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat.size();j++)
        {
            cout<<setw(3)<<mat[i][j];
        }
        cout<<endl;
    }
}
void chmat(int row,int col,vector<vector<int>> &mat)
{
    for(int i=0;i<mat.size();i++)
    {
        mat[i][col]=-1;
        mat[row][i]=-1;
    }
    mat[col][row]=-1;
    mat[col][0]=-1;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<in>> mat(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    int r=row(mat);
    int c=col(mat);
    vector<pair<int, int>> path;
    path.push_back({0, r + c});
    set<int> valid;
    for (int i = 1; i < n; i++)
    {
        valid.insert(i);
    }
    while (valid.size())
    {
        pair<int, int> minimum = {INT_MAX, INT_MAX};
        vector<vector<int>> minMatrix;

        for (int i = 1; i < n; i++)
        {
            if (valid.find(i) == valid.end())
                continue;
            vector<vector<int>> tmpMatrix = mat;
            changeMatrix(path.back().first, i, tmpMatrix);
            r = row(tmpMatrix);
            c = column(tmpMatrix);
            int cost = r + c + mat[path.back().first][i] + path.back().second;
            display(tmpMatrix);
            cout << path.back().first << " TO " << i << " : " << cost << endl;
            if (cost < minimum.second)
            {
                minimum = {i, cost};
                minMatrix = tmpMatrix;
            }
        }
          mat = minMatrix;
        path.push_back(minimum);
        valid.erase(minimum.first);
}

    cout<<"PATH : ";
    for(auto i: path)
    {
        cout<<i.first+1<<" ";
    }
    cout<<1<<endl;

    cout << "FINAL : " << path.back().second << endl;

    return 0;e
}