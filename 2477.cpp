/*
2022.10.28
baekjoon 2477
*/
#include <cstdio>

using namespace std;

int main()
{
    bool HV[6];
    int len[6];
    int k;
    int tmp;
    int MT=-1,MF=-1,t,f;

    scanf("%d",&k);

    for(int i=0;i<6;i++){
        scanf("%d %d",&tmp,&len[i]);
        HV[i]=tmp>2 ? true:false;
        if(HV[i]) MT=len[i]>MT ? len[i]:MT;
        else MF=len[i]>MF ? len[i]:MF;
    }

    for(int i=0;i<6;i++){
        if(HV[i]){
            if(len[i]<MT){
                if(len[(i+5)%6]<MF && len[(i+7)%6]<MF){
                    t=len[i];
                }
            }
        }
        else{
            if(len[i]<MF){
                if(len[(i+5)%6]<MT && len[(i+7)%6]<MT){
                    f=len[i];
                }
            }
        }
    }

    printf("%d",k*(MT*MF-t*f));

    return 0;
}