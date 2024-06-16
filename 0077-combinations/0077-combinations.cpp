class Solution {
public:
    void helper(int n, int k, int i, vector<vector<int>> &result, vector<int> &temp){
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            temp.push_back(j+1);
            helper(n,k,j+1,result,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> result;
        helper(n,k,0,result,temp); 
    return result;       
    }
};