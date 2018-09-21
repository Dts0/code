#include<iostream>
using namespace std;

class Position{
	int x;
	int y;
	friend ostream& operator<<(ostream& os,const Position& n);
	friend Position operator*(const Position& lhs,const Position& rhs);
public:
	Position(int _x=0,int _y=0){
		x=_x;
		y=_y;
	}
};
ostream& operator<<(ostream& os,const Position& n){
	os<<"("<<n.x<<","<<n.y<<")";
}
Position operator*(const Position& lhs,const Position& rhs){
	return Position(lhs.x*rhs.x,lhs.y*rhs.y);
}

int main(){
	Position num0(2,3),num1(4,5);
	cout<<num0<<endl;
	cout<<num0*num1<<endl;

	Position num(3);
	cout<<num*4<<endl;
	cout<<4*num<<endl;
	return 0;
}
