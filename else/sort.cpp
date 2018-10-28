#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void print(vector<T>& nums){
	for(auto i : nums){
		cout<<i<<" ";
	}
	cout<<endl;
}

#define _SWAP(_a,_b){\
	auto tmp=_a;_a=_b;_b=tmp;\
}

template<typename T>
void selectSort(vector<T>& nums){//选择排序
	if(nums.size()==0)
		return;
	for(int i=0;i<nums.size();++i){
		int min_index=i;//从第i个开始
		for(int j=i;j<nums.size();++j){
			if(nums[j]<nums[min_index]){
				min_index=j;
			}
		}
		_SWAP(nums[i],nums[min_index]);
	}
}

template<typename T>
void dtsSort(vector<T>& nums){//自己用的一个神奇的排序
	for(int i=0;i<nums.size();++i){
		for(int j=0;j<i;++j)
			if(nums[i]<nums[j])
				_SWAP(nums[i],nums[j]);
	}
}

template<typename T>
void bubbleSort(vector<T>& nums){//冒泡排序
	for(int i=0;i<nums.size();++i){
		for(int j=0;j<nums.size()-i-1;++j){
			if(nums[j]>nums[j+1])
				_SWAP(nums[j],nums[j+1]);
		}
	}
}

template<typename T>
void insertSort(vector<T>& nums){//插入排序
	for(int i=1;i<nums.size();++i){
		for(int j=i;j>=1 && nums[j]<nums[j-1];--j){
			_SWAP(nums[j],nums[j-1]);
		}
	}
}

template<typename T>
void shellSort(vector<T>& nums){//希尔排序，进阶版的插入排序,O(nlogn)
	int h=1;
	while(h<nums.size()/3){//分为3部分
		h=3*h+1;
	}
	while(h>=1){
		for(int i=h;i<nums.size();++i){
			for(int j=i;j>=h && nums[j]<nums[j-h];j-=h){
				_SWAP(nums[j],nums[j-h]);
			}
		}
		h=h/3;
	}
}

template<typename T>
//请忽略这个与排序无关的函数...不适用于归并排序和快速排序
static void merge(vector<T>& nums1,vector<T>& nums2){//将nums1和nums2合并，结果放入扩容后的nums1中
	int size1=nums1.size();
	nums1.resize(nums1.size()+nums2.size());
	for(int i=0;i<nums2.size();++i){
		nums1[size1+i]=nums2[i];
	}
}

//归并排序使用的合并函数
template<typename T>
//将数组nums中的begin到middle和middle+1到tail两个数组合并,并放回nums,使用的临时数组为temp
static void merge(vector<T>& nums,vector<T>& temp,int begin,int middle,int tail){
	//i为左侧数组的当前指针,j为右侧数组的当前指针,k为合并后数组(temp)的当前指针
	int i=begin,j=middle+1,k=begin;
	while(i!=middle+1 && j!=tail+1){
		if(nums[i]>nums[j]){
			temp[k++]=nums[j++];//增序排列,取小值
		}else{
			temp[k++]=nums[i++];
		}
	}
	//复制剩余部分
	while(i!=middle+1){
		temp[k++]=nums[i++];
	}
	while(j!=tail+1){
		temp[k++]=nums[j++];
	}
	//从临时数组复制到原数组
	for(int it=begin;it<=tail;++it){
		nums[it]=temp[it];
	}
}

template<typename T>
static void mergeSort(vector<T>& nums,vector<T>& temp,int begin,int tail){//归并排序递归子函数
	int middle=(begin+tail)/2;
	if(begin<tail){//当begin到tail之后时停止递归
		mergeSort(nums,temp,begin,middle);
		mergeSort(nums,temp,middle+1,tail);
		merge(nums,temp,begin,middle,tail);
	}
}
template<typename T>
//归并排序的思路：
//将每个数组拆分成两个子数组分别排序再合并
void mergeSort(vector<T>& nums){//归并排序入口
	vector<T> temp(nums.size());
	mergeSort(nums,temp,0,nums.size()-1);
}


//快速排序切分函数,并返回切分调整后的切分点的索引,该点左侧所有值比该点小,右侧所有值比该点大
template<typename T>
int partition(vector<T>& nums,int begin,int tail){
	int i=begin,j=tail+1;//将begin+1到tail的数字分为>val和小于val
	T val=nums[begin];//取第一个数为切分点,之后会把它调整到对应位置
	while(1){
		while(nums[++i]<val && i!=tail);//在i不到最后时,i右移
		while(val<nums[--j] && j!=begin);//在j不到开头时,j左移
		if(i>=j)//i,j相遇,跳出
			break;
		_SWAP(nums[i],nums[j]);//未相遇时,交换
	}
	_SWAP(nums[begin],nums[j]);//交换选择的点和当前j的位置(比nums[i]小的中最后一个)
	return j;
}


template<typename T>
void quickSort(vector<T>& nums,int begin,int tail){
	if(begin>=tail)
		return;
	int partIndex=partition(nums,begin,tail);
	quickSort(nums,begin,partIndex-1);//对切分点左侧快排
	quickSort(nums,partIndex+1,tail);//对切分点右侧快排
}
template<typename T>
void quickSort(vector<T>& nums){
	quickSort(nums,0,nums.size()-1);
}


void test(vector<int> nums){
	vector<int> nums0(nums);
	vector<int> nums1(nums);
	vector<int> nums2(nums);
	vector<int> nums3(nums);
	vector<int> nums4(nums);
	vector<int> nums5(nums);

	selectSort(nums0);
	bubbleSort(nums1);
	insertSort(nums2);
	shellSort(nums3);
	mergeSort(nums4);
	quickSort(nums5);

	print(nums);

	print(nums0);
	print(nums1);
	print(nums2);
	print(nums3);
	print(nums4);
	print(nums5);
}

int main(){
	test({2,4,5,3,1});
	test({});//空数组
	test({1,2,3,4,5});//已排序的数组
	test({2,4,5,3,1,2,3,3});

	return 0;
}
