#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool invalidArray = false;
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int n = array.size();
        if (n < 1) {
            invalidArray = true;
            return 0;
        }
        vector<int> curSum(n,0);
        curSum[0] = array[0];
        for (auto i = 1; i<n; ++i) {
            if (curSum[i-1] > 0) {
                curSum[i] = array[i] + curSum[i-1];
            } else {
                curSum[i] = array[i];
            }
        }
        int maxSum = curSum[0];
        for (int i=1; i<n; ++i) {
            maxSum = curSum[i]>maxSum ? curSum[i]: maxSum;
        }
        return maxSum;
    }
}; // 时间复杂度O(n),空间负载度O(n)

class Solution1 {
public:
    bool invalidArray = false;
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int n = array.size();
        if (n < 1) {
            invalidArray = true;
            return 0;
        }
        vector<int> curSum(n,0);
        curSum[0] = array[0];
        int maxSum = curSum[0];
        for (auto i = 1; i<n; ++i) {
            if (curSum[i-1] > 0) {
                curSum[i] = array[i] + curSum[i-1];
            } else {
                curSum[i] = array[i];
            }
            maxSum = curSum[i] > maxSum ? curSum[i]: maxSum;
        }
        return maxSum;
    }
}; // 时间复杂度O(n),空间复杂度O(1)

int main()
{
    vector<int> array;
    int n; int tmp;
    cin >> n;
    while(n--) {
        cin >> tmp;
        array.push_back(tmp);
    }
    Solution1 s;
    if (s.invalidArray) {
        cout << "Invalid input!" << endl;
    } else {
        cout << s.FindGreatestSumOfSubArray(array);
    }

    return 0;
}
