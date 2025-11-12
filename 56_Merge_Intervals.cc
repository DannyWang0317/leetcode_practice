#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        vector<int> tmp;
        result.push_back(intervals[0]);
        int i = 0;

        for(int j=1; j<intervals.size(); j++){
            if(intervals[j][0] <= result[i][1] && intervals[j][1] > result[i][1]){
                tmp = {result[i][0], intervals[j][1]};
                result.pop_back();
                result.push_back(tmp);
            }
            else if(intervals[j][0] <= result[i][1] && intervals[j][1] <= result[i][1]){
                continue;
            }
            else{
                tmp = intervals[j];
                result.push_back(tmp);
                i++;
            }
        }

        return result;
    }
};

int main(){
    vector<vector<int>> v = {{1,3},{0,2},{2,3},{4,6},{4,5},{5,5},{0,2},{3,3}};
    Solution s;

    cout << "original vector: " << endl;
    for(vector w : v){
        cout << "[" << w[0] << ", " << w[1] << "]" << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());
    cout << "sorted vector: " << endl;
    for(vector w : v){
        cout << "[" << w[0] << ", " << w[1] << "]" << " ";
    }
    cout << endl;

    vector<vector<int>> result = s.merge(v);
    cout << "merge intervals: " << endl;
    for(vector w : result){
        cout << "[" << w[0] << ", " << w[1] << "]" << " ";
    }

    return 0;
}