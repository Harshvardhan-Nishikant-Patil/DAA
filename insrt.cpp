#include<iostream>
using namespace std;
void srt(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0 && t<=a[j])
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=t;
    }
}
void pr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    pr(a,n);
    srt(a,n);
    pr(a,n);
    return 0;
}