#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int NULL_VAL = -1;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val): val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            Node* prev = nullptr;
            for(int i=0; i<size; i++){
                Node* curr = q.front(); q.pop();
                if(prev) prev->next = curr;
                prev = curr;
                if(prev->left) q.push(prev->left);
                if(prev->right) q.push(prev->right);
            }
            if(prev) prev->next = nullptr;
        }

        return root;
    }
};

Node* createTree(vector<int> array){
    if(!array.size()) return nullptr;

    Node* root = new Node(array[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while(i < array.size()){
        Node* curr = q.front();
        q.pop();
        // left child
        if(i < array.size()){
            if(array[i] != NULL_VAL){
                curr->left = new Node(array[i]);
                q.push(curr->left);
            }
            i++;
        }
        // right child
        if(i < array.size()){
            if(array[i] != NULL_VAL){
                curr->right = new Node(array[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

void printLevelNext(Node* root) {
    if (!root) return;
    queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            Node* prev = nullptr;
            for(int i=0; i<size; i++){
                Node* curr = q.front(); q.pop();
                if(prev) prev->next = curr;
                prev = curr;
                if(prev->left) q.push(prev->left);
                if(prev->right) q.push(prev->right);
            }
            if(prev) prev->next = nullptr;
        }

        return;
    cout << "Node: " << root->val 
         << ", Next: " << (root->next ? to_string(root->next->val) : "NULL") << endl;
    printLevelNext(root->left);
    printLevelNext(root->right);
}

int main(){
    vector<int> tree = {1, 2, 3, 4, 5, NULL_VAL, 7};
    Node* root = createTree(tree);
    printLevelNext(root);

    Solution s;
    Node* result = s.connect(root);

    printLevelNext(result);



    return 0;
}