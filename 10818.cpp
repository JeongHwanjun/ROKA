/*
baekjoon #10818 https://www.acmicpc.net/problem/10818
2022.08.18
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    int min=1000001,max=-1000001;
    int tmp;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        min=tmp<min ? tmp:min;
        max=tmp>max ? tmp:max;
    }

    cout<<min<<' '<<max;

    return 0;
}