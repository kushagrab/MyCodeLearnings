#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
*/

int main()
{
    int currSum = 0;
    int k = 3;
    int maxLen = 0;
    unordered_map<int, int> preSum;
    vector<int> nums = {2,0,0,3,0,0,0,0,0};
    for(int i=0;i<nums.size();i++)
    {
        currSum+=nums[i];
        if(currSum == k)
        {
            maxLen = max(maxLen,i+1); 
        }
        
        int sumToFind = currSum - k;
        
        if(preSum.find(sumToFind) != preSum.end())
        {
            int len = i - preSum[sumToFind];
            maxLen = max(maxLen, len);
        }
                
        preSum.insert({currSum,i});
    }

    return maxLen;
}
