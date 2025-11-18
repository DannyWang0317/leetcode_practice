#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution{
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int curSum){
        if(!root) return 0;

        curSum = curSum * 10 + root->val;
        
        if(!root->left && !root->right){
            return curSum;
        }

        return dfs(root->left, curSum) + dfs(root->right, curSum);
    }
};

int main(){
    Solution s;
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node9 = new TreeNode(9, node5, node1);
    TreeNode* node4 = new TreeNode(4, node9, node0);

    int result = s.sumNumbers(node4);
    cout << "ans: " << result << endl;

    return 0;
};