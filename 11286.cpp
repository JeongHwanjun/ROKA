/*
baekjoon #11286 https://www.acmicpc.net/problem/11286
2022.08.28
2022.09.17
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int pheap[100100];
int nheap[100100];
int psize=0,nsize=0;

void push(int x);
void ppop();
void npop();
int abs(int n){return n>0 ? n : n*(-1);}
void swap(int &a, int &b);

int main()
{
    int n;
    

    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);

        if(x) push(x);
        else{
            if(!nsize && !psize) cout<<0<<endl;
            else if(!nsize && psize) ppop();
            else if(nsize && !psize) npop();
            else if(abs(pheap[1])<abs(nheap[1])) ppop();
            else npop();
        }
    }

    return 0;
}

void push(int x)
{
    if(x<0){
        nheap[++nsize]=x;

        int cur=nsize;
        while(cur>1){
            if(nheap[cur]>nheap[cur/2]){
                swap(nheap[cur],nheap[cur/2]);
                cur/=2;
            }
            else break;
        }
    }
    else{
        pheap[++psize]=x;

        int cur=psize;
        while(cur>1){
            if(pheap[cur]<pheap[cur/2]){
                swap(pheap[cur],pheap[cur/2]);
                cur/=2;
            }
            else break;
        }
    }
}

void ppop()
{
    printf("%d\n",pheap[1]);
    
    pheap[1]=pheap[psize];
    pheap[psize--]=0;

    int cur=1;
    while(cur*2<=psize){
        int l=cur*2,r=cur*2+1;

        if(r<=psize){
            if(pheap[l]>pheap[r]){
                if(pheap[cur]>pheap[r]){
                    swap(pheap[cur],pheap[r]);
                    cur=r;
                }
                else break;
            }
            else{
                if(pheap[cur]>pheap[l]){
                    swap(pheap[cur],pheap[l]);
                    cur=l;
                }
                else break;
            }
        }
        else if(pheap[l]<pheap[cur]){
            swap(pheap[l],pheap[cur]);
            cur=l;
        }
        else break;
    }
}

void npop()
{
    printf("%d\n",nheap[1]);
    
    nheap[1]=nheap[nsize];
    nheap[nsize--]=0;

    int cur=1;
    while(cur*2<=nsize){
        int l=cur*2,r=cur*2+1;

        if(r<=nsize){
            if(nheap[l]<nheap[r]){
                if(nheap[cur]<nheap[r]){
                    swap(nheap[cur],nheap[r]);
                    cur=r;
                }
                else break;
            }
            else{
                if(nheap[cur]<nheap[l]){
                    swap(nheap[cur],nheap[l]);
                    cur=l;
                }
                else break;
            }
        }
        else if(nheap[l]>nheap[cur]){
            swap(nheap[l],nheap[cur]);
            cur=l;
        }
        else break;
    }
}

void swap(int &a, int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}