#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void print(vector<T>& nums){
	for(auto i : nums){
		cout<<i<<" ";
	}
	cout<<endl;
}

#define _SWAP(_a,_b){\
	auto tmp=_a;_a=_b;_b=tmp;\
}

template<typename T>
void selectSort(vector<T>& nums){//选择排序
	if(nums.size()==0)
		return;
	int min_index=0;
	for(int i=0;i<nums.size();++i){
		for(int j=i;j<nums.size();++j){
			if(nums[j]<nums[min_index]){
				min_index=j;
			}
		}
		_SWAP(nums[i],nums[min_index]);
	}
}

template<typename T>
void dtsSort(vector<T>& nums){//自己用的一个神奇的排序
	for(int i=0;i<nums.size();++i){
		for(int j=0;j<i;++j)
			if(nums[i]<nums[j])
				_SWAP(nums[i],nums[j]);
	}
}

template<typename T>
void bubbleSort(vector<T>& nums){//冒泡排序
	for(int i=0;i<nums.size();++i){
		for(int j=0;j<nums.size()-i-1;++j){
			if(nums[j]>nums[j+1])
				_SWAP(nums[j],nums[j+1]);
		}
	}
}

template<typename T>
void insertSort(vector<T>& nums){//插入排序
	for(int i=1;i<nums.size();++i){
		for(int j=i;j>=1 && nums[j]<nums[j-1];--j){
			_SWAP(nums[j],nums[j-1]);
		}
	}
}

template<typename T>
void shellSort(vector<T>& nums){//希尔排序，进阶版的插入排序,O(nlogn)
	int h=1;
	while(h<nums.size()/3){//分为3部分
		h=3*h+1;
	}
	while(h>=1){
		for(int i=h;i<nums.size();++i){
			for(int j=i;j>=h && nums[j]<nums[j-h];j-=h){
				_SWAP(nums[j],nums[j-h]);
			}
		}
		h=h/3;
	}
}



template<typename T>
void qSort(vector<T>& nums){

}



int main(){
	vector<int> nums{2,4,5,3,1};
	vector<int> nums0(nums);
	vector<int> nums1(nums);
	vector<int> nums2(nums);
	vector<int> nums3(nums);

	selectSort(nums0);
	bubbleSort(nums1);
	insertSort(nums2);
	shellSort(nums3);

	print(nums0);
	print(nums1);
	print(nums2);
	print(nums3);

	return 0;
}
