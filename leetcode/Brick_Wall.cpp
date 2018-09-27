/*

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Example:
Input:
[[1,2,2,1],
 [3,1,2],
 [1,3,2],
 [2,4],
 [3,1,2],
 [1,3,1,1]]
Output: 2
Explanation:

Note:
The width sum of bricks in different rows are the same and won't exceed INT_MAX.
The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000.

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> wallMap;
        int max_crossed=0,cnt_cols=wall.size();

        for(int i=0;i<wall.size();++i)
            for(int j=0,sum=0;j<wall[i].size()-1;++j){//注意不要算上最后一列，因为最后一列是边界，不考虑
                sum+=wall[i][j];
                max_crossed=max(max_crossed,++wallMap[sum]);
            }

        return cnt_cols-max_crossed;

    }
};

#define REQUIRE(sol) {\
    if(sol)\
    cout<<"passed"<<endl;\
    else cout<<"not passed"<<endl;\
}



int main(){
	Solution s;
	vector<vector<int>> wall={{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
	REQUIRE( s.leastBricks(wall) == 2);
}
