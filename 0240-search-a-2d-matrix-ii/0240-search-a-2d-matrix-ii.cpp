class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
        int start=0;
        int end=matrix[i].size();
        if(matrix[i][0]<=target && matrix[i][end-1]>=target ){
            // cout<<"i"<<i<<endl;
            while(start<=end){

            
            int mid=start+(end-start)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            if(matrix[i][mid]>target){
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