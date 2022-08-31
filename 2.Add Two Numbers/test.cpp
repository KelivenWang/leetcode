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
 
int main()
{
    ListNode * trail;
    ListNode * head;
    trail = nullptr;
    head = nullptr;
    

    int l1[] = {2,4,5};
    int lengthl1 = sizeof(l1) / sizeof(int);

    for(int i=0; i<lengthl1; i++){
        trail = new ListNode(l1[i],trail);
        if(i==0){
            head = trail;
        }
    }

    ListNode * ptr;
    ptr = head;

    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    delete ptr;
    cout<<endl;
    return 0;

}