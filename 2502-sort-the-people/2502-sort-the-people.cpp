class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int len=heights.size();
        vector<int> result(len,0);
        vector<string> fin_res;
        for(int i=0;i<heights.size();i++){
            result[i]=i;    
        }

        auto lambda = [&heights](int i1, int i2) {
            return heights[i1] > heights[i2];
        }; 

        sort(result.begin(),result.end(),lambda);
        
        int index=0;
        for(auto i: result){
            fin_res.push_back(names[i]);
            
        }
        return fin_res;
    }
};