#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
		int low = 1, high = pow(10, 9);
        while (low < high) {
            int mi = low + (high - low) / 2;
            if (!possible(piles, H, mi))
                low = mi + 1;
            else
                high = mi;
    	}
		return low;
	}
	bool possible(vector<int>& piles, int H, int K) {
        int time = 0;
        for (int p: piles)
            time += (p - 1) / K + 1;
        return time <= H;
    }

};

int main(){
	Solution s;
	vector<int> piles{30,11,23,4,20};
	cout<<s.minEatingSpeed(piles,6)<<endl;
	return 0;
}
