#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string res = "";
        int magicNum = 2*(numRows - 1);
        for (int row = 0; row < numRows; ++row) {
            int initRowStep = magicNum - row*2; // 每行的起始步长
            if (initRowStep == 0) {             // 步长为0，重置为magicNum
                initRowStep = magicNum;
            }
            int step = initRowStep;
            for (int idx = row; idx < s.size(); ) {
                res += s[idx];
                idx += step;
                step = magicNum - step;
                if (step == 0) {
                    step = magicNum;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "0123456789";
    int n = 4;
    string res = s.convert(str,n);
    cout << res << endl;
    return 0;
}
