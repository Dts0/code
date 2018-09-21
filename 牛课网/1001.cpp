 #include<iostream>
 using namespace std;
class item{
public:
	long A,B,C;
	item(){A=0;B=0;C=0;}
};
int main(){
	int T=0;
	cin>>T;
	item items[T];
	for(int i=0;i<T;i++){
		cin>>items[i].A;
		cin>>items[i].B;
		cin>>items[i].C;
	}
	for(int i=0;i<T;i++){
		cout<<"Case #"<<i+1<<": ";
		if(items[i].A+items[i].B>items[i].C)
			cout<<"true";
		else cout<<"false";
		cout<<endl;
	}
	
	return 0;
}

