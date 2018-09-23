/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;//进位标志
        ListNode* rear=NULL,* ptr=NULL,* head=NULL;
        
        while(l1!=NULL || l2!=NULL || carry!=0){
        	
            int num1=(l1==NULL)?0:l1->val;
            int num2=(l2==NULL)?0:l2->val;
            int carry_rear=carry;
            int sum=num1+num2+carry_rear;
            
            carry=sum/10;

            ptr=new ListNode(sum%10);

            if(rear!=NULL)
                rear->next=ptr;
            else head=ptr;

            rear=ptr;
            if(l1!=NULL)
                l1=l1->next;
            else num1=0;
            if(l2!=NULL)
                l2=l2->next;
            else num2=0;
        }
        return head;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

#define REQUIRE(sol) {\
    if(sol)\
    cout<<"passed"<<endl;\
    else cout<<"not passed"<<endl;\
}

int main() {
    Solution s;
    ListNode* l1_1 = stringToListNode("(1,3,5)");
    ListNode* l2_1 = stringToListNode("(2,4,6)");
    ListNode* l3_1 = stringToListNode("(3,7,1,1)");
    REQUIRE(  listNodeToString(s.addTwoNumbers(l1_1,l2_1))==listNodeToString(l3_1) );

    ListNode* l1_2 = stringToListNode("(2)");
    ListNode* l2_2 = stringToListNode("(3)");
    ListNode* l3_2 = stringToListNode("(5)");
    REQUIRE(  listNodeToString(s.addTwoNumbers(l1_2,l2_2))==listNodeToString(l3_2) );

    ListNode* l1_3 = stringToListNode("(9)");
    ListNode* l2_3 = stringToListNode("(1,9,9,9,9,9,9,9,9,9)");
    ListNode* l3_3 = stringToListNode("(0,0,0,0,0,0,0,0,0,0,1)");
    REQUIRE(  listNodeToString(s.addTwoNumbers(l1_3,l2_3))==listNodeToString(l3_3) );

    ListNode* l1_4 = stringToListNode("(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1)");
    ListNode* l2_4 = stringToListNode("(5,6,4)");
    ListNode* l3_4 = stringToListNode("(6,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1)");
    REQUIRE(  listNodeToString(s.addTwoNumbers(l1_4,l2_4))==listNodeToString(l3_4) );
/*
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);

        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    */
    return 0;
}
