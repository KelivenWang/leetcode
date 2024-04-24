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

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* temp;
        ListNode* curr = head;
        ListNode* pre = nullptr;
        while(curr){
            temp = curr->next; // 因為將原本的指針反轉，要先保留下一個要處理的節點
            curr->next = pre;  // 指針翻轉
            pre = curr; // pre指針往前
            curr = temp; // curr指針往前
        }
        return pre;
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