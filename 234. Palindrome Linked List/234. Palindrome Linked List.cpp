// reference https://blog.csdn.net/liuxiao214/article/details/77803348

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
// 使用反轉鏈錶。 不同的是不反轉整個鏈表，只反轉回文的後半段鏈表。 然後就是判斷出哪裡是回文的中間位置。
private:
    ListNode * reverselist(ListNode * head){
        // 用來反轉list用的 反轉後面一半
        ListNode * pre = nullptr; // 反轉列表過後的起點
        ListNode * next = nullptr; // 是要反轉列表目前node的 next pointer

        while(head){
            // 只要head不為空，則先將head->next保存在next節點中。
            // 然後head->next指向pre，然後head節點保存在pre中。 
            // 最後head保存next節點。 遍歷結束，返回pre節點，即完成反轉
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

public:
    bool isPalindrome(ListNode* head) {
        
        if(head==nullptr || head->next==nullptr){
            return true;
        }
        // 判斷回文中間位置。 設置一個慢指標slow，一個快指標fast
        ListNode * slow;
        ListNode * fast;
        slow = head;
        fast = head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
        // 只要fast->next和fast->next->next不為空，則slow往前走一步，fast往前走兩步，
        // slow = slow->next，fast = fast->next->next，
        // 這樣當不滿足遍歷條件、結束遍歷時，slow剛好指在中間位置，如果長度是計數，則剛好中間，
        // 長度是偶數， 則中間前一個
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 將slow->next開始反轉
        slow->next = reverselist(slow->next);
        slow = slow->next;

        while(slow){
            // 判斷是否是回文。 這時，可同時遍歷head和slow，判斷二者值是否相等即可，
            // 不相等直接返回false。 遍歷結束后，返回true
            if(slow->val != head->val){
                return false;
            }

            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};

int main(){
    // head = [1,2,2,1]
    ListNode aa(1);
    ListNode bb(0);
    ListNode cc(1);
    ListNode * head;

    head = &aa;
    aa.next = &bb;
    bb.next = &cc;

    Solution solution;
    cout<<solution.isPalindrome(head)<<endl;
    return 0;
}


/**
 * @brief 原本解法
 * 
 * if(head==nullptr || head->next==nullptr){
            // pointer is null or pointer only have one element
            return true;
        }

        vector<int> vt;
        ListNode * ptr;
        ptr = head;
        while(ptr){
            vt.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        int len = vt.size() / 2;
        for(int i=0; i<len; i++){
            if(vt[i] != vt[(vt.size()-1-i)]){
                // 不要用 2*len 來代替vt.size()
                return false;
            }
        }
        return true;
 * 
 */