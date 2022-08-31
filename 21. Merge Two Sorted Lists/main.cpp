#include <iostream>
#include <list>
#include <array>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // init one dummy node
        ListNode dummy(0);
        // init pointer temp pointed to dummy
        ListNode *temp = &dummy;

        while((list1 != NULL) && (list2 != NULL)){
            if(list1->val < list2->val){
                // let temp->next pointer to list(now)
                temp->next = list1;
                // move list1 pointer to next value
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        
        // if only list1 remaining temp->next pointer to remaining list1 values
        if(list1){
            temp->next = list1;
        }
        if(list2){
            temp->next = list2;
        }
        return dummy.next;
    }
};


int main()
{
    int list1[] = {1,2,4};
    int list2[] = {1,3,4};
    int Lengthlist1 = sizeof(list1) / sizeof(int);
    int Lengthlist2 = sizeof(list2) / sizeof(int);
    
    ListNode * head;
    ListNode * trail;
    head = new ListNode;
    trail = new ListNode;
    head = trail;
    for(int i=0; i<Lengthlist1; i++){
        ListNode * newnode;
        newnode = new ListNode;

        newnode->val = list1[i];
        trail->next = newnode;
        trail = newnode;
    }
    ListNode * head2 = new ListNode;
    ListNode * trail2 = new ListNode;
    head2 = trail2;
    for(int i=0; i<Lengthlist2; i++){
        ListNode * newnode = new ListNode;

        newnode->val = list2[i];
        trail2->next = newnode;
        trail2 = newnode;
    }

    ListNode * getAns = new ListNode;
    Solution solution;

    // remove first init node value = 0;
    head = head->next; 
    head2 = head2->next;
    getAns = solution.mergeTwoLists(head, head2);

    ListNode * ptr;
    ptr = getAns;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    delete ptr;
    cout<<endl;
    return 0;
}
