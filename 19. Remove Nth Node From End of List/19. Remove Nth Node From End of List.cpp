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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr){
            return nullptr;
        }

        ListNode * dummyNode =  new ListNode();
        dummyNode->next = head;
        ListNode * fastPtr = dummyNode;
        ListNode * slowPtr = dummyNode;
        
        // 快指針要先走 n+1 步，慢指針才會剛好在之後同步往後
        // 移動時候，會剛好指在要刪除節點的前一個節點
        n++;
        while(n--){
            fastPtr = fastPtr->next;
        }

        while(fastPtr){
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }

        slowPtr->next = slowPtr->next->next;
        return dummyNode->next;
    }
};

int main(){
    ListNode one(1); 
    ListNode two(2);
    ListNode three(3);
    ListNode four(4);
    ListNode five(5);
    ListNode * head;

    head = &one;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;

    int n = 2;
    Solution solution;
    ListNode * getans;
    getans =  solution.removeNthFromEnd(head,n);

    ListNode * ptr;
    ptr = getans;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }cout<<endl;
    return 0;
}