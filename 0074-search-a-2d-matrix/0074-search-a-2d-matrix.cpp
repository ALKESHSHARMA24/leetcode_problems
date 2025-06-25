class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        for(int i = 0; i < mat.size(); i++){
            int start=0;
            int end=mat[i].size();

            if(mat[i][0]<=target && mat[i][end-1]>=target){
                // cout<<"i"<<i<<endl;
                while(start<=end){
                    int mid=start+(end-start)/2;
                    if(mat[i][mid]==target){
                        return true;
                    }
                    if(mat[i][mid]>target){
                        end=mid-1;
                    }else{
                        start=mid+1;
                    }
                }
            }
            
        }

        return false;
    }
};