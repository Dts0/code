/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include<iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x==-2147483648) return 0;
        int ret=0;
        bool isNeg=false;
        if(x<=0) {isNeg=true;x=-x;}
        while(x>=10){
            int tmp=x%10;
            x/=10;
            ret=ret*10+tmp;
        }

        int tmp=x%10;
        x/=10;
        ret=ret*10+tmp;
        if(ret%10!=tmp)
                return 0;

        if(isNeg) ret=-ret;

        return ret;


    }
};


#define REQUIRE(sol) {\
    if(sol)\
    cout<<"passed"<<endl;\
    else cout<<"not passed"<<endl;\
}
int main(){
    Solution s;
    REQUIRE(s.reverse(123)==321);

    REQUIRE(s.reverse(-123)==-321);

    REQUIRE(s.reverse(-2147483648)==0);

    REQUIRE(s.reverse(1534236469)==0);
}
