#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		//vector<int> non_zeroes;
		int cnt=0;
        for(int it : nums){
            if(it!=0){
				nums[cnt]=it;
				//non_zeroes.push_back(it);
				++cnt;
            }
        }
		for(int i=cnt;i<nums.size();++i){
			nums[i]=0;
		}
/*
		for(int i=0;i<non_zeroes.size();++i){
			nums[i]=non_zeroes[i];
		}

        for(int i=non_zeroes.size();i<nums.size();++i){
            nums[i]=0;
        }
		*/
    }
};


int main(){
	Solution s;
	vector<int> v{0,2,0,4,0,12};
	s.moveZeroes(v);

	for(auto it : v){
		cout<<it<<" ";
	}
	cout<<endl;

	return 0;
}
