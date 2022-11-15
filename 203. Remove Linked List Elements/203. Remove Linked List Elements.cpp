#include<iostream>
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyhead = new ListNode(0); // creat a "dummy node" pointer to a new space 
        dummyhead->next = head;
        ListNode *current = dummyhead; // creat a current pointer to head pointer

        while(current->next != nullptr){
            if(current->next->val == val){
                // delete a node
                ListNode *temp = current->next; // creat temp pointer to pointer a node that need delete
                current->next = current->next->next; // current node pointer to next and next

                // release a node that need to delete
                delete temp;
            }else{
                current = current->next;
            }
        }
        head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};