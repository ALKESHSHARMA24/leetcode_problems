class Solution {
public:
    string frequencySort(string s) {
        string result="";
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> v(mp.begin(),mp.end());

        auto lambda = [](pair<char, int>& p1, pair<char, int>& p2) {
            return p1.second > p2.second;
        };
        sort(v.begin(),v.end(),lambda);

        
        for(int i=0;i<v.size();i++){
            char c=v[i].first;
            int freqncy=v[i].second;
            string temp=string(freqncy,c);
            result+=temp;
        }
        return result;

    }
};