#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution{
public:
    ListNode* sortList(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return mergeSort(left, right);
    }

    ListNode* mergeSort(ListNode* left, ListNode* right){
        ListNode dummyNode;
        ListNode* tail = &dummyNode;

        while(left && right){
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            }else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if(left){
            tail->next = left;
        }else{
            tail->next = right;
        }

        return dummyNode.next;
    }
};



int main(){
    Solution s;

    ListNode* head = new ListNode(4);
    ListNode* tail = head;
    tail->next = new ListNode(2);
    tail = tail->next;
    tail->next = new ListNode(1);
    tail = tail->next;
    tail->next = new ListNode(3);

    ListNode* result = s.sortList(head);

    for(int i=0; i<4; i++){
        cout << "ListNode " << i << ":" << result->val << endl;
        result = result->next;
    }

    return 0;
}