#include<iostream>
#include<vector>

using namespace std;

int find(int val,vector<int>& nums){
	for(int i=0;i<nums.size();++i){
		if(nums[i]==val){
			return i;
		}
	}
	return -1;
}
int halfFind(int val,vector<int>& nums){
	int left=0,right=nums.size()-1;
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(val>nums[mid]){
			left=mid+1;
		} else if(val<nums[mid]){
			right=mid-1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main(){
	vector<int> nums;
	for(int i=0;i<100;++i){
		nums.push_back(i*i);
	}
	bool passed=true;
	for(int i : nums){
		if(halfFind(i,nums)!=find(i,nums)){
			cout<<"not passed,"<<i<<endl;
			passed=false;
		}
	}
	if(passed){
		cout<<"passed"<<endl;
	}

	return 0;
}
