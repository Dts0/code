/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {//best,尾插法
		vector<int> ret(m+n);
		std::merge(nums1.begin(),nums1.begin()+m,nums2.begin(),nums2.begin()+n,ret.begin());
		sort(ret.begin(),ret.end());
		nums1=ret;
	}
    void merge_mine(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
            return;
        }
        if(n==0){
            return;
        }
        vector<int> ret(m+n);
        int pNums1=0,pNums2=0;
        for(int i=0;i<m+n;++i){
            if(nums1[pNums1]<nums2[pNums2] && pNums1<m || pNums2>=n){
                ret[i]=nums1[pNums1];
                ++pNums1;
               // cout<<pNums1-1<<endl;
            } else
            if(nums1[pNums1]>=nums2[pNums2] && pNums2<n || pNums1>=m){
                ret[i]=nums2[pNums2];
                ++pNums2;
               // cout<<pNums2-1<<endl;
            }
            //ret[i]=(nums1[pNums1]<nums2[pNums2])?nums1[pNums1++]:nums2[pNums2++];
        }
        nums1=ret;
    }
};

int main(){
	Solution s;
	vector<int> nums1{1,2,3,0,0,0},nums2{2,5,6};
	int m = 3, n = 3;
	s.merge(nums1,m,nums2,n);

	for(int it : nums1){
		cout<<it<<" ";
	}
	return 0;
}
