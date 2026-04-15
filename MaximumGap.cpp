/*
Problem 164: Maximum Gap
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        
        //if less than two elements
        if (n < 2){ 
            return 0;
        }
          
        //finds min and max element in nums
        int minVal = nums[0];
        int maxVal = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < minVal) minVal = nums[i];
            if (nums[i] > maxVal) maxVal = nums[i];
        }

        //if gap is 0
        if (minVal == maxVal) return 0;

        //bucket size vs num of buckets
        int range = maxVal - minVal;
        int bucketSize = max(1, range / (n - 1));
        int bucketCount = range / bucketSize + 1;

        //vectors for buckets
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        //fill buckets
        for (int num : nums) {
            int i = (num - minVal) / bucketSize;
            bucketMin[i] = min(bucketMin[i], num);
            bucketMax[i] = max(bucketMax[i], num);
        }

        //get max gap between buckets
        int maxGap = 0;
        int prev = minVal; 
        for (int i = 0; i < bucketCount; i++) {
            if (bucketMin[i] == INT_MAX){
                continue; //skip empty buckets...
            } 
                
            maxGap = max(maxGap, bucketMin[i] - prev);
            prev = bucketMax[i];
        }

        return maxGap;

    }

};
