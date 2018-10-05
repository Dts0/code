#include<iostream>
#include<vector>

using namespace std;

inline int getSum(vector<int>& piles){
	int sum=0;
	for(int i : piles){
		sum+=i;
	}
	return sum;
}
inline int getHours(vector<int>& piles,int K){
	int hours=0;
	for(int i : piles){
		if(i%K==0)
			hours+=i/K;
		else
			hours+=(i/K + 1);
	}
//	cout<<K<<" : "<<hours<<endl;
	return hours;
}
int findMax(vector<int>& piles){
	int max=-1;
	for(int i : piles){
		if(i>max){
			max=i;
		}
	}
	return max;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
		if(piles.empty())
			return 0;
        int minSpeed=getSum(piles)/H +findMax(piles);
		while(1){
			if(getHours(piles,minSpeed-1)<=H){
				--minSpeed;
			} else {
				return minSpeed;
			}
		}
    }
};

int main(){
	Solution s;
	vector<int> piles{30,11,23,4,20};
	cout<<s.minEatingSpeed(piles,6)<<endl;
	return 0;
}
