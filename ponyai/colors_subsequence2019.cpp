#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
int n,m;
int Car[30],Peo[30];
char C[1000010],P[1000010];
bool Check()
{
    for(int i=0;i<26;i++){
        if(Car[i]<Peo[i]){return false;}
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",C,P);
    int Cs = strlen(C),Ps=strlen(P);
    for(int i = 0; i< Cs;i++){
        ++Car[C[i]-'a'];
    }
    for(int i=0;i<Ps;i++){
        P[i] -= 'a';
    }
    int lp = 0 ;
    int rp = 0;
    long long ans= 0 ;
    ++Peo[P[0]];
    while(lp<Ps&&rp<Ps){
        if(Check()){
            ans += rp-lp+1;
            ++rp;
            ++Peo[P[rp]];
        }
        else{
            --Peo[P[lp]];
            ++lp;
            if(lp>rp){
                ++rp;
                ++Peo[P[rp]];
            }
        }
    }
    printf("%lld",ans);
    return 0;
}