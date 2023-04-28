/*
baekjoon #16139 https://www.acmicpc.net/problem/16139
2023.04.28
*/

#include <cstdio>
#include <cstring>

int main()
{
    int cnt[200001][30]={0};
    int q,front,rear;
    char str[200001];
    char target;

    scanf("%s",str);
    getchar();

    for(int i=0;i<strlen(str);i++){
        for(int j=0;j<'z'-'a';j++){
            cnt[i][j]=(i>0 ? cnt[i-1][j]:0);
            if((int)str[i]-'a'==j) cnt[i][j]++;
        }
    }

    scanf("%d",&q);
    getchar();
    for(int i=0;i<q;i++){
        scanf("%c %d %d",&target,&front,&rear);
        getchar();
        if(front>0) printf("%d\n",cnt[rear][target-'a']-cnt[front-1][target-'a']);
        else printf("%d\n",cnt[rear][target-'a']);
    }

    return 0;
}