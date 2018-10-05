#include<iostream>
#include<vector>

using namespace std;

#define _SWAP(_a,_b){\
	auto tmp=_a;_a=_b;_b=tmp;\
}

template<typename T>
void dtsSort(vector<T>& nums){
	for(int i=0;i<nums.size();++i){
		for(int j=0;j<i;++j)
			if(nums[i]<nums[j])
				_SWAP(nums[i],nums[j]);
	}
}

template<typename T>
void bubbleSort(vector<T>& nums){
	for(int i=0;i<nums.size();++i){
		for(int j=0;j<nums.size()-i-1;++j){
			if(nums[j]>nums[j+1])
				_SWAP(nums[j],nums[j+1]);
		}
	}
}
template<typename T>
void qSort(vector<T>& nums){

}

template<typename T>
void print(vector<T>& nums){
	for(auto i : nums){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> nums{2,4,5,3,1};
	bubbleSort(nums);

	print(nums);
	return 0;
}
