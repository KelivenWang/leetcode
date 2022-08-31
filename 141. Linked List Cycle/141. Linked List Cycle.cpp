// reference https://blog.csdn.net/Mary19920410/article/details/65633185

#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head==nullptr){
            return false;
        }

        ListNode * ptr;
        ptr = head;

        // while(ptr){
            // cout<<ptr->val<<endl;
            // system("pause");
            // ptr = head->next;
            // head = head->next;
        // }

        ListNode * fast;
        ListNode * slow;
        fast = head;
        slow = head;

        while((fast->next!=nullptr)&&(fast->next->next!=nullptr)){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution solution;

    ListNode * head;
    ListNode three(3);
    ListNode two(2);
    ListNode zero(0);
    ListNode four(4);

    head = &three;
    three.next = &two;
    two.next = &zero;
    zero.next = &four;

    cout<<solution.hasCycle(head)<<endl;

    return 0;
}