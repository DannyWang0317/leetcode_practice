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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head || !head->next) return head;

        ListNode* cur = head;
        int count = 0;

        while(cur->next){
            count++;
            cur = cur->next;
        }
        count++;

        k = k % count;
        if (k == 0) return head;   
        cur = head;

        for(int i=0; i<count-k-1; i++){
            cur = cur->next;
        }
        ListNode* newHead = cur->next;
        ListNode* result = newHead;
        cur->next = nullptr;
        for(int i=0; i<k-1; i++){
            newHead = newHead->next;
        }
        newHead->next = head;

        return result;
    }
};


int main(){
    Solution s;

    ListNode* head = new ListNode(0);
    ListNode* tail = head;

    tail->next = new ListNode(1);
    tail = tail->next;

    tail->next = new ListNode(2);
    tail = tail->next;

    tail->next = new ListNode(3);
    tail = tail->next;

    tail->next = new ListNode(4);
    tail = tail->next;
    tail->next = nullptr;

    ListNode* result = s.rotateRight(head, 3);

    for(int i=1; i<=5; i++){
        cout << "ListNode " << i << ": " << result->val << endl;
        result = result->next;
    }

    return 0;
}