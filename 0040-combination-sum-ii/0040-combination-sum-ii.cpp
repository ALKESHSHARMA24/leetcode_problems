class Solution {
public:
    set<vector<int>> s;

    void generateCombinations(vector<int>& candidates, int target, int index, vector<int>combination, int currentSum) {
        if (currentSum == target) {
            s.insert(combination);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates to avoid generating duplicate combinations
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // If adding the current element doesn't exceed the target, add it to the combination
            if (currentSum + candidates[i] <= target) {
                combination.push_back(candidates[i]);
                // Recursively generate combinations with the current element included
                generateCombinations(candidates, target, i + 1, combination, currentSum + candidates[i]);
                // Backtrack: remove the last element from the combination
                combination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to handle duplicates efficiently
        sort(candidates.begin(), candidates.end());
        // Generate combinations starting from index 0
        generateCombinations(candidates, target, 0, {}, 0);
        // Convert set to vector of vectors
        return vector<vector<int>>(s.begin(), s.end());
    }
};