#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthest = 0;
        int current_end = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            farthest = max(farthest, i + nums[i]);

            // 到了這一步的範圍頂端，就必須跳一下
            if(i == current_end){
                jumps++;
                current_end = farthest;

                // 如果已經能到終點就不用再算
                if(current_end >= nums.size() - 1) break;
            }
        }
        return jumps;
    }
};


int main(){
    Solution s;
    vector<int> nums = {2,3,1,1,4};

    int result = s.jump(nums);
    cout << "result: " << result << " step" << endl;

    return 0;
}