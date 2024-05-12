class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        vector<int> freq_pos(2, -1); 

        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] == target) {
                int pos = mid;
                
                
                while (pos > 0 && nums[pos - 1] == target) {
                    pos--;
                }
                freq_pos[0] = pos;
                
                
                pos = mid;
                while (pos < nums.size() - 1 && nums[pos + 1] == target) {
                    pos++;
                }
                freq_pos[1] = pos;
                
                return freq_pos;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return freq_pos;
    }
};
