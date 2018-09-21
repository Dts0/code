/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first=-1,second=-1;
    for(int i=0;i<nums.size();++i){
        //if(nums[i]<target){
            for(int j=0;j<i;++j){
                if(i!=j && nums[i]+nums[j]==target){
                    if(i>j){
                        first=j;second=i;
                    }
                    if(i<j){
                        first=i;second=j;
                    }
                }
        //    }
        }
    }
    return vector<int>{first,second};

    }
};
#define REQUIRE(sol) {\
    if(sol)\
    cout<<"passed"<<endl;\
    else cout<<"not passed"<<endl;\
}
int main(){

    Solution s;

    std::vector<int> v1{2, 7, 11, 15};
    REQUIRE( (s.twoSum(v1, 9) == std::vector<int>{0, 1}) );

    std::vector<int> v4{2, 15, 11, 7};
    REQUIRE( (s.twoSum(v4, 9) == std::vector<int>{0, 3}) );

    std::vector<int> v2{0, 4, 3, 0};
    REQUIRE( (s.twoSum(v2, 0) == std::vector<int>{0, 3}) );

    std::vector<int> v3{-3, 4, 3, 90};
    REQUIRE( (s.twoSum(v3, 0) == std::vector<int>{0, 2}) );
	return 0;
}
