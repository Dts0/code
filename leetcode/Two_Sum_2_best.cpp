/*

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.


*/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.find(complement) != map.end() && map[complement] != i)
            {
                return vector<int> {map[complement]+1, i+1};
            }
            map.emplace(nums[i], i);
        }
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
    REQUIRE( (s.twoSum(v1, 9) == std::vector<int>{1, 2}) );

    std::vector<int> v2{0, 4, 4, 5};
    REQUIRE( (s.twoSum(v2, 8) == std::vector<int>{2, 3}) );

    std::vector<int> v3{-3, 3, 4, 90};
    REQUIRE( (s.twoSum(v3, 0) == std::vector<int>{1, 2}) );


	return 0;
}
