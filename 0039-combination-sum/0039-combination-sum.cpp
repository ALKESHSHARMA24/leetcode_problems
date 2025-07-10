class Solution {
public:
    void findCombinations(vector<int>& candidates,
                          vector<vector<int>>& combinations,
                          vector<int> currentCadidates, int target, int sum,
                          int pos) {

        if (sum > target || pos >= candidates.size()) {
            return;
        }

        if (sum == target) {
            combinations.push_back(currentCadidates);
            return;
        }

        sum += candidates[pos];

        currentCadidates.push_back(candidates[pos]);
        findCombinations(candidates, combinations, currentCadidates, target,
                         sum, pos);
        currentCadidates.pop_back();
        findCombinations(candidates, combinations, currentCadidates, target,
                         sum - candidates[pos], pos + 1);

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> combinations;
        vector<int> currentCadidates;
        findCombinations(candidates, combinations, currentCadidates, target, 0,
                         0);
        return combinations;
    }
};