/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/submissions/

reference
http://c.biancheng.net/view/1570.html
https://chowdera.com/2022/02/202202210659549301.html
https://blog.csdn.net/qq_43799400/article/details/122941144
https://blog.csdn.net/slandarer/article/details/91863177
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val; // init current value
    ListNode *next; // init next node's pointer

    ListNode() : val(0), next(nullptr) {
        // init current node value = 0, and pointer = nullptr
    }
    ListNode(int x) : val(x), next(nullptr) {
        // init current node value = x, and pointer = nullptr
    } 
    ListNode(int x, ListNode *next) : val(x), next(next) {
        // init current node value = x, and next pointer = next
    } 
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr; //p
        ListNode * ptr2; //q
        ListNode  * ptr3; //r
        ListNode * l3;
        l3 = new ListNode(0);

        ptr = l1; // l1 = head = num
        ptr2 = l2; // l2 = head2 = num2
        ptr3 = l3;
        
        int carry = 0;
        int sum = 0;
        int remainder = 0;

        // if two linked has number
        while(ptr && ptr2){
            sum = ptr->val + ptr2->val + carry;
            carry = sum / 10;
            remainder = sum % 10;
            ptr3->next = new ListNode(remainder);

            ptr = ptr->next;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }

        // two linked list only one has number or carry!=0
        while(ptr || ptr2 || carry!=0){
            sum = carry;
            if(ptr){
                sum = sum + ptr->val;
                ptr = ptr->next;
            }
            if(ptr2){
                sum  = sum + ptr2->val;
                ptr2 = ptr2->next;
            }
            carry = sum / 10;
            remainder = sum % 10;
            ptr3->next = new ListNode(remainder);
            ptr3 = ptr3->next;
        }
        return l3->next;
    }
    
};

int main(){
    cout<<endl;
    Solution solution;
    int l1[] = {2,4,3};
    int l2[] = {5,6,4};
    int lengthl1 = sizeof(l1) / sizeof(int);
    int lengthl2 = sizeof(l2) / sizeof(int);

    ListNode * head;
    ListNode * trail;
    ListNode * head2;
    ListNode * trail2;
    ListNode * getans;
    getans = new ListNode;
    head = new ListNode;
    trail = new ListNode;
    head2 = new ListNode;
    trail2 = new ListNode;
    head = trail; 
    head2 = trail2;

    for(int i=0; i<lengthl1; i++){
        ListNode * newnode;
        newnode = new ListNode;
        
        newnode->val = l1[i];
        trail->next = newnode; // put newnode to H
        trail = newnode;

    }

    for(int i=0; i<lengthl2; i++){
        ListNode * newndoe;
        newndoe = new ListNode;

        newndoe->val = l2[i];
        trail2->next = newndoe;
        trail2 = newndoe;

    }

    ListNode * ptr;
    ptr = head;
    ptr = ptr->next;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    delete ptr;
    cout<<endl;

    //ListNode * ptr;
    ptr = head2;
    ptr = ptr->next;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    delete ptr;
    cout<<endl;

    getans = solution.addTwoNumbers(head,head2);

    ptr = getans;
    ptr = ptr->next;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    delete ptr;
    cout<<endl;
    return 0;
}