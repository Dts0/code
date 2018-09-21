#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    //Store the input
    int K;
    vector<int> vec;
    cin>>K;
    int value;
    for (int i=0; i<K; ++i)
    {
        cin>>value;
        vec.push_back(value);
    }
    
    //Process in time   //在线处理的方式求最大子列和，时间复杂度O（n）
    int sum=0;
    int max=0;
    for (int i=0; i<vec.size(); ++i)
    {
        sum+=vec[i];
        if (sum>max)
        {
            max=sum;
        }else if (sum<0)//sum小于0时，可以忽略掉当前的sum，可以简单理解为负数对于求和只会帮倒忙，所以忽略掉
        {
            sum=0;
        }
    }
    
    //Output
    cout<<max;
    
    
    return 0;
}

