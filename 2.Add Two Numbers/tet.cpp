#include<iostream>
#include<stdlib.h>
using namespace std;

#include<iostream>
#include<vector>

struct ListNode {
    
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {
    }   // Initialize the current node value as the default value 0, The pointer is null 
	ListNode(int x) : val(x), next(nullptr) {
    }    // Initialize the current node value to x, The pointer is null 
	ListNode(int x, ListNode *next) : val(x), next(next) {
    }    // Initialize the current node value to x, The next grade point is next

};
//class Need to be in main In front of 
class Solution {
    
public:
	ListNode* removeElements(ListNode* head, int val) {
    
		if (head == nullptr) return NULL;
		ListNode *H = new ListNode;
		H->next = head;
		ListNode *p = H;// new head
		// It's modified here p,H And it will change 
		while (p->next != nullptr) {
    
			//H->next = p;
			if (p->next->val == val) {
    			
				p->next = p->next->next;
			}
			else
			{
    
				p = p->next;
			}
		}
		return H->next->next;
	}
};
int main() {
    
	Solution solution;
	int nums[] = {
     1, 2, 6, 3, 4, 5, 6 };
	int length = sizeof(nums) / sizeof(int);
	ListNode *head=new ListNode;
	ListNode *H = new ListNode;
	head = H;
	//head = (ListNode)malloc(sizeof(ListNode));
	// Assign values to the linked list 
	for (int i = 0;i < length; i++) {
    
		ListNode *p = new ListNode;// Header , The default value is 0
		p->val = nums[i];
		//p->next = nullptr;
		H->next = p;
		H = p;
	}
	int val = 6;
	head = solution.removeElements(head, val);
	return 0;
}