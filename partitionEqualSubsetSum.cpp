class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //TIME: 0(n * S)
        int total = 0;

        //find total of nums
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
        }
        
        //false if not even
        if (total % 2 != 0){
            return false;
        } 
        
        int S = total/2;
        //create table initialized to false
        vector<bool> dp(S + 1, false);
        //base case of 0 is always possible
        dp[0] = true;

        //iterate through each number
        for(int num : nums){
            //go backwards
            for(int s = S; s >= num; s--){
                //dp is true if already true, or if (s-num) is possible
                dp[s] = dp[s] || dp[s-num];
            }
        }
        
        //return
        return dp[S];
    }
};
