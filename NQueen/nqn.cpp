#include<iostream>
using namespace std;
#define n 4


bool pl(int q,int cl,int c[])
{
    int j=0;
    while(j<q)
    {
        if(c[j]==cl || abs(c[j]-cl)==abs(j-q))
        {
            return false;
        }
        j++;
    }
    return true;
}





bool nq(int q,int n,int c[])
{
    for(int i=0;i<n;i++)
    {
        if(pl(n,i,c))
        {
            c[q]=i;
            if(q==n-1)
                return true;
            c[q]==-1;
        }
    }
    return false;
} 




int main()
{
   /* int n;
    cout<<"Enter No. of Queens"<<endl;
    cin>>n;
    while(n<4)
    {
        cout<<"Enter Value More than 3"<<endl;
        cin>>n;
    }*/
    int a[n][n]={0,0,0,0,
                 0,0,0,0,
                 0,0,0,0,
                 0,0,0,0};
    
    
    
    cout<<"It is As Per:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t\t",a[i][j]);
        }
        printf("\n");
    }

}