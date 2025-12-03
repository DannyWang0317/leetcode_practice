#include <iostream>
using namespace std;

class LinkedListNode{
public:
    int val;
    LinkedListNode* next;

    LinkedListNode(){
        this->val = 0;
        this->next = nullptr;
    }
    LinkedListNode(int node_val){
        this->val = node_val;
        this->next = nullptr;
    }
    LinkedListNode(int node_val, LinkedListNode* next_node){
        this->val = node_val;
        this->next = next_node;
    }


    static LinkedListNode* reverseLinkedList(LinkedListNode* head){
        LinkedListNode* prev = nullptr;
        LinkedListNode* cur = head;

        while(cur){
            LinkedListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }

};

void printList(LinkedListNode* node) {
    while (node) {
        cout << node->val << "  ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    LinkedListNode* node_1 = new LinkedListNode();
    LinkedListNode* node_2 = new LinkedListNode(10);
    LinkedListNode* node_3 = new LinkedListNode(100); 

    node_1->next = node_2;
    node_2->next = node_3;
    LinkedListNode* head = node_1;

    cout << "node 1: " << node_1->val << "  " << node_1->next << endl;
    cout << "node 2: " << node_2->val << "  " << node_2->next << endl;
    cout << "node 3: " << node_3->val << "  " << node_3->next << endl;

    printList(head);

    LinkedListNode* reverseHead = LinkedListNode::reverseLinkedList(head);

    printList(reverseHead);

    return 0;
}