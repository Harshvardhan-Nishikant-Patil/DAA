#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct 
{
    int v;
    int w;
    float d;
}item;

void in(item items[],int sz)
{
    cout<<"Entered Total Size : " << sz<<endl;
    cout<<"Enter Item's Value/Price and Weight : "<<endl;
    for(int i=0;i<sz;i++)
    {
        cout<<"Enter Value/Price:"<<i+1<<"V : ";
        cin>>items[i].v;
        cout<<"Enter Weight : "<<i+1<<"W : ";
        cin>>items[i].w;
    }
}

void dis(item items[],int sz)
{
    cout<<"Values/Price : ";
    for(int i=0;i<sz;i++)
    {
        cout<<items[i].v<<"\t";
    }
    cout<<"Values/Price : ";
    for(int i=0;i<sz;i++)
    {
        cout<<items[i].w<<"\t";
    }
    cout<<endl;
}

bool cmp(item i1,item i2)
{
    return (i1.d>i2.d);
}

float knp(item items[],int sz,int n)
{
    int ttlwt=0;
    float fnlval=0;
    for(int i=0;i<sz;i++)
    {
        items[i].d=(float)items[i].v/(float)items[i].w;
    }
    sort(items,items+sz,cmp);
    cout<<"Values : ";
    for(int i=0;i<sz;i++)
    {
        cout<<items[i].v<<"\t";
    }
    cout<<"Weight : ";
    for(int i=0;i<sz;i++)
    {
        cout<<items[i].w<<"\t";
    }
    cout<<"Ratio : ";
    for(int i=0;i<sz;i++)
    {
        cout<<items[i].d<<"\t";
    }
    cout<<endl;
    for(int i=0;i<sz;i++)
    {
        if(ttlwt+items[i].w<=n)
        {
            fnlval+=items[i].v;
            ttlwt+=items[i].w;;
        }
        else
        {
            int z=n-ttlwt;
            fnlval+=(z*items[i].d);
            ttlwt+=z;
            break;
        }
    }
    cout<<"Total Weight of bag : "<<ttlwt<<endl;
    return fnlval;
    
}

int main()
{
    int n;
    int p;
    cout<<"Enter No. of Items you want to Enter : ";
    cin>>p;
    cout<<endl;
    item items[p];
    in(items,p);
    cout<<"Entered Data : "<<endl;
    dis(items,p);
    cout<<"Enter Size of Bag";
    cin>>n;
    float mx=knp(items,p,n);
    cout<<"Max Value : "<<n<<endl;
    cout<<"Weight is : "<<mx<<endl;
    return 0;
}