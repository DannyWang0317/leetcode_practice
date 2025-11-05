# include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        string tmp;

        for(auto c : s){
            if(c == ' ' && tmp.empty()){
                continue;
            }
            else if(c == ' ' && !tmp.empty()){
                result = tmp + " " + result;
                tmp.clear();
            }
            else{
                tmp += c;
            }
        }
        
        if(tmp.empty()){
            result.pop_back();
            return result;
        }
        else{
            result = tmp + " " + result;
            result.pop_back();
            return result;
        }
    }
};

int main(){
    Solution s;
    string s_1 = "the sky is blue";
    string s_2 = " Hello World ";
    string s_3 = "a good   example";

    string result_1 = s.reverseWords(s_1);
    string result_2 = s.reverseWords(s_2);
    string result_3 = s.reverseWords(s_3);

    cout << "result 1: " << result_1 << endl;
    cout << "result 2: " << result_2 << endl;
    cout << "result 3: " << result_3 << endl;

    return 0;
}