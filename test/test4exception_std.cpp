#include<iostream>
#include<exception>
using namespace std;

const string egg="I don't like this number,so I decide to refuse it.";

class non_44_error: public logic_error{
public:
	explicit non_44_error(const string &s=egg):logic_error(s){}
};

int main(){
	int input;
	while(1){
	try{
		cout<<"Please type in a number between 1 and 99."<<endl;
		cin>>input;
		if(!cin.good()){
			cin.clear();
			cin.ignore();
			throw invalid_argument("The input should be a number!");
		}
		if(input>=100)
			throw length_error("The input should be less than 100!");
		if(input<0)
			throw out_of_range("The input should be Non-negative number!");
		if(input==44)
			throw non_44_error();
		cout<<"Your input is "<<input<<". there isn't any error\n";
	} catch(invalid_argument e){
		cout<<"*********************************"<<endl;
		cout<<"There is an invalid argument error occured"<<endl;
		cout<<"info:"<<e.what()<<endl;
		cout<<"*********************************"<<endl;
	} catch(length_error e){
		cout<<"*********************************"<<endl;
		cout<<"There is a length error occured"<<endl;
		cout<<"info:"<<e.what()<<endl;
		cout<<"*********************************"<<endl;
	} catch(out_of_range e){
		cout<<"*********************************"<<endl;
		cout<<"There is an out of range error occured"<<endl;
		cout<<"info:"<<e.what()<<endl;
		cout<<"*********************************"<<endl;
	} catch(non_44_error e){
		cout<<"*********************************"<<endl;
		cout<<"There is an error occured"<<endl;
		cout<<"info:"<<e.what()<<endl;
		cout<<"*********************************"<<endl;
	} catch(exception e){
		cout<<"*********************************"<<endl;
		cout<<"There is an undefined error occured"<<endl;
		cout<<"info:"<<e.what()<<endl;
		cout<<"*********************************"<<endl;
	}
		cout<<endl;
	}

	return 0;
}
