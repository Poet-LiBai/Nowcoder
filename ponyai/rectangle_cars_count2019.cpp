#include<iostream>
using namespace std;
 
const int offset= 500;
 
int add[1000][1000]={0};
int sum[1000][1000]={0};
int num[1000][1000]={0}; 
 
 
int main()
{
    int q;
    cin >> num[offset][offset] >> q;
    int x,y;
    int upperX=offset,lowerX=offset;
    int upperY=offset,lowerY=offset;
    int x1,y1,x2,y2,ans;
    bool flag=1;
    while(flag)
    {
        for(x=lowerX;x<=upperX;x++)
        {
            for(y=lowerY;y<=upperY;y++)
            {
                if(num[x][y]>=8)
                {
                    add[x][y]-=8;
                    add[x][y+1]+=1;
                    add[x+1][y+1]+=1;
                    add[x+1][y]+=1;
                    add[x+1][y-1]+=1;
                    add[x][y-1]+=1;
                    add[x-1][y-1]+=1;
                    add[x-1][y]+=1;
                    add[x-1][y+1]+=1;
                }
            }
        }
         
        for(x=lowerX-1;x<=upperX+1;x++)
            if(add[x][lowerY-1]!=0)
            {
                upperX+=1;
                upperY+=1;
                lowerX-=1;
                lowerY-=1;
                break;
            }
         
        flag=0;
        for(x=lowerX;x<=upperX;x++)
            for(y=lowerY;y<=upperY;y++)
            {
                num[x][y]+=add[x][y];
                add[x][y]=0;
                if(num[x][y]>=8)
                    flag=1;
            }
    }
     
    for(x=lowerX;x<=upperX;x++)
        for(y=lowerY;y<=upperY;y++)
            sum[x][y]=sum[x-1][y]+sum[x][y-1]-sum[x-1][y-1]+num[x][y];
     
    for(int i=0;i<q;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        x1+=offset;
        y1+=offset;
        x2+=offset;
        y2+=offset;
         
        if(x1>upperX||y1>upperY||x2<lowerX||y2<lowerY)
            ans=0;
        else
        {
            x1=max(x1,lowerX)-1;
            y1=max(y1,lowerY)-1;
            x2=min(x2,upperX);
            y2=min(y2,upperY);
            ans=sum[x2][y2]-sum[x1][y2]-sum[x2][y1]+sum[x1][y1];
        }
        cout<<ans<<endl;
    }
    return 0;
}