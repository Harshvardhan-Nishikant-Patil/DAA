#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct 
{
    int v;
    int w;
    float d;
} item;
void in(item items[],int szofitm)
{
    cout<<"Enter Total:"<<szofitm<<endl<<"Enter Item's Value/Price and Weight:"<<endl;
    for(int i=0;i<szofitm;i++)
    {
        cout<<"Enter : "<<i+1<<"V : ";
        cin>>items[i].v;
        cout<<"Enter : "<<i+1<<"W : ";
        cin>>items[i].w;
    }
}
void dis(item items[],int szofitm)
{
    int i;
    cout<<"Values: ";
    for(i=0;i<szofitm;i++)
    {
        cout<<items[i].v<<"\t";
    }
    cout<<endl<<"Weight: ";
    for(i=0;i<szofitm;i++)
    {
        cout<<items[i].w<<"\t";
    }
    cout<<endl;
}
bool cmp(item i1,item i2)
{
    return (i1.d > i2.d);
}
float knpsck(item items[],int szofitm,int n)
{
    int i,j;
    float fnlval=0;
    int ttlwt=0;
    for(i=0;i<szofitm;i++)
    {
        items[i].d=(float)items[i].v/items[i].w;
    }
    sort(items,items+szofitm,cmp);
    cout<<"Values : ";
    for(i=0;i<szofitm;i++)
    {
        cout<<items[i].v<<"\t";
    }
        cout<<endl<<"Weights : ";
    for(i=0;i<szofitm;i++)
    {
        cout<<items[i].w<<"\t";
    }
        cout<<endl<<"Ratio : ";
    for(i=0;i<szofitm;i++)
    {
        cout<<items[i].d<<"\t";
    }
    cout<<endl;
    for(i=0;i<szofitm;i++)
    {
        if(ttlwt+items[i].w<=n)
        {
            fnlval+=items[i].v;
            ttlwt+=items[i].w;
        }
        else
        {
            int z=n-ttlwt;
            fnlval+=(z*items[i].d);
            ttlwt+=z;
            break;
        }
    }
    cout<<"Total Weight in Bag : "<<ttlwt<<endl;
    return fnlval;
}
int main()
{
    int n;
    int p;
    cout<<"Enter No. of Items Youw wanted to Add:"<<endl;
    cin>>p;
    item items[p];
    in(items,p);
    cout<<"Entered Data: \n"<<endl;;
    dis(items,p);
    cout<<"Enter Weight Of Sack : \n";
    cin>>n;
    float mx=knpsck(items,p,n);
    cout<<"max Value for : "<<n<<endl<<"Weight is : "<<mx<<endl;;
    return 0;
}
