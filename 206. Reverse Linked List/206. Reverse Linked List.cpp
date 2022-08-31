#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        vector<int> vt;
        
        head = head->next;
        while(head){
            vt.push_back(head->val);
            head = head->next;
        }

        ListNode * trail1 = new ListNode;
        ListNode * head1 ;
        head1 = trail1;
        int len = vt.size()-1;
        for(int i=len; i>=0; i--){
            if(i==0){
                ListNode * newnode = new ListNode;
                trail1->val = vt[i];
                trail1->next = newnode;
                trail1 = newnode;
            }else{
                ListNode * newnode = new ListNode;
                trail1->val = vt[i];
                trail1->next = newnode;
                trail1 = newnode;
            }
        }
        return head1;
    }
};

int main(){
    // head = [1,2,3,4,5]
    Solution solution;

    int num[] = {1,2,3,4,5};
    int length = sizeof(num) / sizeof(int);
    ListNode * trail = new ListNode;
    ListNode * head ;
    head = trail;

    for(int i=0; i<length; i++){
        ListNode * newnode = new ListNode;
        newnode->val = num[i];
        trail->next = newnode;
        trail = newnode;
    }
    
    ListNode * getans ;
    getans = solution.reverseList(head);
    ListNode * ptr;
    ptr = getans;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }cout<<endl;
    system("pause");
    return 0;
}