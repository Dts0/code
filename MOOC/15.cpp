#include <iostream>
#include <vector>

using namespace std;

#define Min_Value -10001 //比小根堆所有结点的值更小的值用来判断插入堆时已到达根结点
#define Max_Node 10000

void Insert_MinHeap(int value,vector<int> &Heap,int &size)//插入一个数值进入小根堆
{
    size++;//小根堆结点个数加一
    int sequence=size;//当前小根堆最后一个结点的位置
    while (Heap[sequence/2]>value)//向上判断插入位置
    {
        Heap[sequence]=Heap[sequence/2];
        sequence /=2;
    }
    Heap[sequence]=value;
}

int main()
{
    int N=0,M=0;
    int size=0;
    cin>>N>>M;
    int value=0;
    vector<int> Heap(Max_Node);
    Heap[0]=Min_Value;
    while (N--)
    {
        cin>>value;
        Insert_MinHeap(value, Heap, size);
    }
    
    int check_num=0,flag=0;
    while (M--)
    {
        cin>>check_num;
        flag=0;
        while (check_num!=0)
        {
            if (flag==0)
            {
                cout<<Heap[check_num];
                flag=1;
            }else
            {
                cout<<' '<<Heap[check_num];
            }
            check_num /=2;
        }
        if (M!=0)
        {
            cout<<endl;
        }
    }
    
    return 0;
}

