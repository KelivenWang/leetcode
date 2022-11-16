#include<iostream>
using namespace std;

class MyLinkedList {

// 建立一個 節點 的結構
struct Node{
    int value;
    Node *next;
    
    Node(int value) : value(value), next(nullptr){};
};
private:

    Node *dummyhead; // 建立一個虛擬頭節點
    int nodeLength = 0;

public:
    MyLinkedList() {
        // 初始化 linked list
        dummyhead = new Node(0);
        nodeLength = 0;
    }
    
    int get(int index) {
        // 獲取 index 的節點
        if(index<0 || index>nodeLength-1){
            return -1;
        }

        // 建立目前指向的指標
        Node *current = dummyhead->next;
        while(index--){
            current = current->next;
        }
        return current->value;
    }
    
    void addAtHead(int val) {
        // 從頭節點加入新節點
        Node *newnode = new Node(val);
        newnode->next = dummyhead->next;
        dummyhead->next = newnode;  
        nodeLength++;

    }
    
    void addAtTail(int val) {
        // 從尾巴加入新節點
        Node *newnode = new Node(val);
        Node *current = dummyhead;

        while(current->next!=nullptr){
            current = current->next;
        }

        current->next = newnode;
        nodeLength++;
    }
    
    void addAtIndex(int index, int val) {
        // 在位置 = index 前的地方加入節點
        if(index<0 || index>nodeLength){
            return;
        }

        Node *newnode = new Node(val);
        Node *current = dummyhead;

        while(index--){
            current = current->next;
        }

        newnode->next = current->next;
        current->next = newnode;
        nodeLength++;

    }
    
    void deleteAtIndex(int index) {
        // 刪除第 index 的節點
        if(index<0 || index>=nodeLength){
            return;
        }

        Node *current = dummyhead;
        while(index--){
            current = current->next;
        }

        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
        nodeLength--;
    }
};

    /**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){

    MyLinkedList* obj = new MyLinkedList();

    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);

    int param_1 = obj->get(1);
    cout<<param_1<<endl;

    obj->deleteAtIndex(1);

    int param_2 = obj->get(1);
    cout<<param_2<<endl;
    
    system("pause");
}