class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, -1);

        for (int i = 0; i < size; i++) {
            int currele = nums[i];

            for (int j = 1; j < size; j++) {
                int index = (j + i) % size;

                if (nums[index] > currele) {
                    result[i] = nums[index];
                    break;
                }
            }
        }
        return result;
    }
};