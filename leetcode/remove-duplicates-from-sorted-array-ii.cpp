/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if(nums.size()==0)
			return 0;

		int pslow=0;
		int cnt=0;//计数值
		for(int pfast=1;pfast<nums.size();++pfast){
			if(nums[pfast]!=nums[pfast-1]){//如果与前一个数不相等，将慢指针传过来
				pslow=pfast;
			}
			if(pfast-pslow>=2){//同样数字最多2个，需要舍去多余部分
				++cnt;
			}
			nums[pfast-cnt]=nums[pfast];//原指针右移舍去了的位数
		}
		return nums.size()-cnt;
    }
};
int main(){
	Solution s;
	vector<int> v{1,1,2,2,2,2,3,3,5,5,5};
	int size = s.removeDuplicates(v);
	for(int i=0;i<size;++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
