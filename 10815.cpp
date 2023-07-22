/*
 * 2023.07.22
 * baekjoon #10815 https://www.acmicpc.net/status?user_id=doriten&problem_id=10815&from_mine=1
 *
 */
#include <cstdio>
#include <algorithm>

int main()
{
    int n,m;
    int card[500001]={0};

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&card[i]);
    }
    std::sort(card,card+n);

    scanf("%d",&m);
    for(int t=0;t<m;t++){
        int target;
        scanf("%d",&target);

        //처음과 끝만 따로 살펴봄(더 나은 방법도 있을듯?)
        if(card[0]==target || card[n-1]==target){
            printf("1 ");
            continue;
        }
        //이분 탐색
        int front=0,rear=n-1,mid;
        int ch=0;
        /*
         * target이상의 원소는 T, 미만의 원소는 F라고 가정한다면
         * 가장 작은 T를 찾아 target과 비교한다(target과 다를 수도 있으니까)
         */
        while(front+1<rear){
            mid=(front+rear)/2;
            if(card[mid]>=target) rear=mid;
            else front=mid;
        }
        if(card[rear]==target) ch=1;
        else ch=0;
        printf("%d ", ch);
    }

    return 0;
}
