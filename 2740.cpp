/*
baekjoon #2740 https://www.acmicpc.net/problem/2740
2022.12.16
*/
#include <cstdio>

int main()
{
    int n,m,k;
    int A[101][101],B[101][101];
    int AB[101][101]={0};

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&A[i][j]);
        }
    }

    scanf("%d %d",&m,&k);
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            scanf("%d",&B[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int sum=0;
            for(int l=0;l<m;l++){
                sum+=A[i][l]*B[l][j];
            }
            AB[i][j]=sum;
        }
    }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            printf("%d ",AB[i][j]);
        }
        printf("\n");
    }

    return 0;
}
