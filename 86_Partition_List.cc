#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode* next): val(x), next(next){};
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        
        ListNode* cur = head;
        ListNode* small = new ListNode();
        ListNode* smallHead = small;
        ListNode* big = new ListNode();
        ListNode* bigHead = big; 

        while(cur){
            if(cur->val < x){
                small->next = cur;
                small = small->next;
            }
            else{
                big->next = cur;
                big = big->next;
            }
            cur = cur->next;
        }

        big->next = nullptr;
        small->next = bigHead->next;

        return smallHead->next;
    }
};


int main(){
    Solution s;
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    tail->next = new ListNode(4);
    tail = tail->next;

    tail->next = new ListNode(3);
    tail = tail->next;

    tail->next = new ListNode(2);
    tail = tail->next;

    tail->next = new ListNode(5);
    tail = tail->next;

    tail->next = new ListNode(2);
    tail = tail->next;

    ListNode* result = s.partition(head, 3);

    for(int i=0; i<6; i++){
        cout << "ListNode " << i << ": " << result->val << endl;
        result = result->next;
    }

    return 0;
}