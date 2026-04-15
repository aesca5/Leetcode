/*
Problem 75: Sort Colors
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
            int k = nums.size();
            vector<int> temp_nums(3,0);
            vector<int> sorted_nums(k);

            for (int i : nums) {
                temp_nums[i]++;
            }

            for (int j = 1; j < 3; j++) {
                temp_nums[j] += temp_nums[j - 1];
            }

            for (int i = k - 1; i >= 0; i--) {
                int curr_num = nums[i];
                int position = temp_nums[curr_num] - 1;
                sorted_nums[position] = curr_num;
                temp_nums[curr_num]--;
            }
            
            nums = sorted_nums;
    }
};
