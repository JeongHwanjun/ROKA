/*
baekjoon #6594 https://www.acmicpc.net/problem/6549
2023.02.12
2023.02.17
2023.02.18
*/

/*
#아이디어
left와 right로 분할, 각각 가장 최대 넓이를 구함
합병하며 mid를 추가로 구함(분할된 부분이 연결됐을때 생기는 새로운 직사각형)
left, mid, right중 최대값을 구함 -> 그게 해당 구간의 최대 넓이
mid에서 출발하는 두개의 포인터, 한쪽은 좌측으로, 한쪽은 우측으로만 감.
둘 중 다음 막대의 높이가 더 높은 것으로 감. 그렇게 해서 최소 막대*포인터 사이의 거리 = 넓이, mid의 값과 비교
그렇게 해서 최대 n번의 횟수 안에 mid의 최대값을 구함.
*/
#include <cstdio>

long long int ary[120000];

long long int divide(int left, int right);
long long int merge(long long int left, long long int right, long long int leftLmt, long long int rightLmt);

int main()
{
    int n;
    int i;
    
    while(true){
        scanf("%d",&n);
        if(!n) break;

        for(i=1;i<=n;i++){
            scanf("%lld",&ary[i]);
        }

        printf("%lld\n",divide(1,n));
    }
    
    return 0;
}

long long int divide(int left, int right)
{
    int mid=(right+left)/2;
    if(right-left>0){
        long long int leftMax=divide(left, mid);
        long long int rightMax=divide(mid+1,right);
        long long int midMax=merge(mid, mid+1,left,right);

        midMax=leftMax>midMax ? leftMax:midMax;
        midMax=rightMax>midMax ? rightMax:midMax;
        return midMax;
    }
    else{
        return ary[left];
    }
}

long long int merge(long long int left, long long int right, long long int leftLmt, long long int rightLmt)
{
    long long int height=ary[left]>ary[right] ? ary[right]:ary[left];
    long long int max=-1;

    while(left>=leftLmt && right<=rightLmt){
        height=height>ary[left] ? ary[left]:height;
        height=height>ary[right] ? ary[right]:height;

        long long int area=height*(right-left+1);
        max=area>max ? area:max;
		if(left<=leftLmt) right++;
		else if(right>=rightLmt) left--;
		else{
			if(ary[left-1]>ary[right+1]) left--;
			else right++;
		}
        
    }

    return max;
}
