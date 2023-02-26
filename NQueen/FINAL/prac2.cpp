#include<iostream>
using namespace std;

void pr(int n,int *cl)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cl[i]==j)
            {
                cout<<i+1<<" ";
                cout<<"\t";
            }
            else
            {
                cout<<0<<" ";
                cout<<"\t";
            }
        }
        cout<<endl;
    }
}

bool pls(int q,int c,int *cl)
{
    int j=0;
    while(j<q)
    {
        if((cl[j]==c)||(abs(c-cl[j])==abs(q-j)))
        {
            return false;
        }
        j++;
    }
    return true;
}

bool nq(int q,int n,int *cl)
{
    if(q==n)
    {
        //pr(n,cl);
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(pls(q,i,cl))
        {
            cl[q]=i;
            cout<<"Queen Is placed Here:"<<q+1<<endl;
           pr(n,cl);
            cout<<endl;
            if(nq(q+1,n,cl))
            {
                return true;
            }
            cout<<"Queen Is Can't be Here:"<<q+2<<endl;
            cl[q]=-1;
            pr(n,cl);
            cout<<endl;
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter no. of queens"<<endl;
    cin>>n;
    if(n<4)
    {
        cout<<"Enter >3"<<endl;
        return 0;
    }
    int cl[n];
    for(int i=0;i<n;i++)
    {
        cl[i]=-1;
    }
    if(nq(0,n,cl))
    {
        cout<<"done"<<endl;
    }
    else
    {
        cout<<"not done"<<endl;
    }
    return 0;
}