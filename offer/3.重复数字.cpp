#include <iostream>

using namespace std;
void inline swap(int& a,int& b){
	int tmp=a;
	a=b;
	b=tmp;
}

bool duplicate(int nums[],int length,int* duplication){
	if(nums==nullptr || length<=0 ){
		cout<<"非法指针或长度"<<endl;
		return false;
	}
	for(int i=0;i<length;++i){//合法性检验
		if(nums[i]<0 || nums[i]>length-1){
			cout<<"数字 "<<nums[i]<<" 不符合要求。(索引:"<<i<<")"<<endl;
			return false;
		}
	}
	for(int i=0;i<length;++i){
		while(nums[i]!=i){
			if(nums[i]==nums[nums[i]]){//如果已经有了，说明有重复，返回该值
				if(duplication)
					*duplication=nums[i];
				else cout<<"非法的输出值指针"<<endl;
				return true;
			}
			swap(nums[i],nums[nums[i]]);
		}
	}
	return false;
}

int main(){
	int nums[]={1,2,3,4,3};
	int result;
	if(duplicate(nums,5,&result))
		cout<<result<<endl;
	return 0;
}
