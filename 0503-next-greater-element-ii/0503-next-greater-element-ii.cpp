class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //IF WE HAVE GIVEN THE CIRCULAR ARRAY IN THE PROBLEM DESCRIPTION
        // THEN WE HAVE TO COMUPLSARY RUN THE LOOP AT LEAST FOR O(2N).
        //FOR BOTH MONOTONIC AND THE NESTED LOOP 

        int size=nums.size();
        vector<int>result(size,-1);
        stack<int> st;

        for(int i=(size*2)-1;i>=0;i--){
            int index= i%size;
            int currEle=nums[index];

            while(!st.empty() && st.top()<=currEle){
                st.pop();
            }

            if(i<size && !st.empty()){
                result[i]=st.top();
            }
            st.push(nums[index]);
        }
        return result;
    

    }
};