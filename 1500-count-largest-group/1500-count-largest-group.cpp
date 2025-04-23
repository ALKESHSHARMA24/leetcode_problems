class Solution {
public:
    int countLargestGroup(int n) {

        unordered_map<int, int> freqMap;
        int maxSize = 0;

        for (int i = 1; i <= n; i++) {
            int sum = 0, temp = i;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            freqMap[sum]++;
            maxSize = max(maxSize, freqMap[sum]);
        }

        int count = 0;
        for (auto& [digitSum, groupSize] : freqMap) {
            if (groupSize == maxSize) count++;
        }

        return count;
    }
    
};