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
        ListNode* cur = head;
        vector<int> val;

        while(cur){
            val.push_back(cur->val);
            cur = cur->next;
        }

        sort(val.begin(), val.end());

        ListNode* prev = new ListNode(val[0]);
        ListNode* result = prev;
        for(int i=1; i<val.size(); i++){
            ListNode* cur = new ListNode(val[i]);
            prev->next = cur;
            prev = cur;
        }

        return result;
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