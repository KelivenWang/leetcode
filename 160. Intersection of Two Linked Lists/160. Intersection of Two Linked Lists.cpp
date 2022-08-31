// reference https://www.youtube.com/watch?time_continue=347&v=IpBfg9d4dmQ&feature=emb_title
// reference https://bclin.tw/2022/06/19/leetcode-160/
#include<iostream>
using namespace std;

// Defintion for singly-linked list
struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
/*
listA = [4,1,8,4,5][5,6,1,8,4,5]
listB = [5,6,1,8,4,5][4,1,8,4,5]
*/
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * ptrA;
        ListNode * ptrB;
        ptrA = headA;
        ptrB = headB;

        if((headA==nullptr) || (headB==nullptr)){
            return nullptr;
        }

        while(ptrA!=ptrB){
            if(ptrA==nullptr){
                // listA 走到尾巴了
                ptrA = headB;
            }else{
                ptrA = ptrA->next;
            }

            if(ptrB==nullptr){
                // listB 走到尾巴了
                ptrB = headA;
            }else{
                ptrB = ptrB->next;
            }
        }
        return ptrA;
    }
};

int main(){
    Solution solution;
    // listA = [4,1,8,4,5], 
    ListNode four1(4);
    ListNode one(1);
    ListNode eight(8);
    ListNode four2(4);
    ListNode five(5);
    ListNode * heada;
    heada = &four1;
    four1.next = &one;
    one.next = &eight;
    eight.next = &four2;
    four2.next = &five;
    // listB = [5,6,1,8,4,5], 
    ListNode * headb;
    ListNode five1b(5);
    ListNode six(6);
    ListNode oneb(1);
    ListNode eightb(8);
    ListNode fourb(4);
    ListNode five2b(5);
    headb = &five1b;
    five1b.next = &six;
    six.next = &oneb;
    oneb.next = &eightb;
    eightb.next = &fourb;
    fourb.next = &five2b;

    ListNode * getans;
    getans = solution.getIntersectionNode(heada,headb);
    ListNode * ptr;
    ptr = getans;

    while(ptr){
        cout<<ptr->val<<" ";
        ptr = getans->next;
        getans = getans->next;
    }
    delete ptr;
    cout<<endl;
    system("pause");
    return 0;
}