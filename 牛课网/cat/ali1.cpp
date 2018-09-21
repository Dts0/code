#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct stu{
    int id;
    int ability;
} stu;

bool sortFunc_max2min(const stu& stu1,const stu& stu2){
	return stu1.ability>stu2.ability;
}
bool sortFunc_max2min_abs(const stu& stu1,const stu& stu2){
	return abs(stu1.ability)>abs(stu2.ability);
}
int main(){
    int num;
    vector<stu> input;
    cin>>num;
    int i;
    int k,d;
    for(i=0;i<num;++i){
        stu tmp;
        tmp.id=i;
        cin>>tmp.ability;
        input.push_back(tmp);
    }
    cin>>k;
    cin>>d;
    
    int lastResult=0;
    int result=0;
    
    sort(input.begin(),input.end(),sortFunc_max2min_abs);
    
    for(vector<stu>::iterator it=input.begin();it!=input.begin()+k;++it){
        cout<<(*it).ability<<" ";
    }
}

