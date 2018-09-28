/*

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

*/

#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		/*
		if(x<0 || (x%10==0 && x!=0))
			return false;

		int tmp=0;
		while(x>tmp){
			tmp=tmp*10+x%10;
			x/=10;
		}

		return x==tmp || x==tmp/10;
		*/
		string str=to_string(x);
		string str0=str;
		reverse(str.begin(),str.end());
		return str == str0;
    }
};

int main(){
	Solution s;

	cout<<s.isPalindrome(121)<<endl;
	cout<<s.isPalindrome(-121)<<endl;
	cout<<s.isPalindrome(123)<<endl;
	cout<<s.isPalindrome(0)<<endl;
	cout<<s.isPalindrome(120)<<endl;
}
