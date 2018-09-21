#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    //input
    int K;
    cin>>K;
    vector<int> vec;
    int value;
    for (int i=0; i<K; ++i)
    {
        cin>>value;
        vec.push_back(value);
    }
    
    //Process
    int first=0,last=0,sum=0,max=-1;
    int flag_max=0;//flag represent whether max has been rewrite
    int flag=0;//sum归零一次，有可能后续子数列会出现大于当前max的数列
    int maybe_first=0;//可能成为最大子列和的第一个结点
    for (int i=0; i<vec.size(); ++i)
    {
        sum+=vec[i];
        if (sum>max)//更新最大子列和
        {
            flag_max=1;
            if (flag==0)//sum更新为0后再次出现大于之前max的最大子列和，更新最大子列和的第一个结点
            {
                first=maybe_first;
                flag=1;
            }
            max=sum;
            last=i;//每次出现新的最大子列和都要更新该子列的最后一个结点
        }else if(sum<0)//sum出现小于0的情况，后续子列若出现更大的子列和，则该子列的第一个结点保存为maybe_first
        {
            maybe_first=i+1;
            sum=0;
            flag=0;
        }
    }
    
    //Output
    if (flag_max==0)
    {
        cout<<"0"<<' '<<vec[0]<<' '<<vec[vec.size()-1];
    }else
    {
        cout<<max<<' '<<vec[first]<<' '<<vec[last];
    }
    
    
    
    return 0;
}

