#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int M, N, K;

int Check(vector<int> &v)
{
    int i=0;
    int num=1;
    int cap=M+1;
    stack<int> sta;
    sta.push(0);
    while(i<N)
    {
        while(v[i]>sta.top() && sta.size()<cap)
            sta.push(num++);
        if(v[i++]==sta.top())
            sta.pop();
        else
            return 0;
    }
    return 1;
}

int main()
{
    vector<int> vec(N,0);
    scanf("%d%d%d",&M,&N,&K);

    for(int i=0; i<K; i++)
    {
        for(int j=0; j<N; j++)
        {
            int number;
            scanf("%d",&number);
            vec.push_back(number);
        }
        if(Check(vec))
            printf("YES\n");
        else
            printf("NO\n");

        vec.clear();
    }
    return 0;
}

