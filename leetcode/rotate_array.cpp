#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int s=nums.size();
		k%=s;
        if(k<=0)
			return;
		//vector<int> tmp(nums.begin()+(s-k),nums.begin()+(s));
		int tmp[k];
		for(int i=s-k;i<s;++i){
			tmp[i-(s-k)]=nums[i];
		}

		for(int i=s-k;i<s;++i){
			cout<<i<<" "<<i-(s-k)<<endl;
			tmp[i-(s-k)]=nums[i];
		}
		for(auto it : tmp){
			cout<<it<<" ";
		}
		cout<<endl;

		for(int i=s-1;i>k-1;--i){
			nums[i]=nums[i-k];
		}

		for(int i=0;i<k;++i){
			nums[i]=tmp[i];
		}
    }
};
int main(){
	Solution s;
	vector<int> v{1,2,3,4,5,6};
	s.rotate(v,2);

	for(auto it : v){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}
