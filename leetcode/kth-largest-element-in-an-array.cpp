#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> cpy(nums);
		sort(cpy.begin(),cpy.end());
		return cpy[cpy.size()-k];
    }
};

int main(){
	vector<int> nums{3,2,1,5,6,4};
	Solution s;
	cout<<s.findKthLargest(nums,2);
	return 0;
}
