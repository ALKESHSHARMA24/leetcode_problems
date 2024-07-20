class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();
        vector<vector<int>> result(m,vector<int>(n,0));


        int i=0;
        int j=0;
        while(i<m && j<n){
            //ALWAYS CHOOSE WHICH WILL BE THE SMALLEST BETWEEN ROW ELEMENT OR COLUMN ELEMENT. AND CHOOSE MINIMUM THEN PLACE IT AT THE ROL AND COLUMN POSITION NOW SET THE OHER ELEMENT OF ROW AND COLUMN ACCORDING TO THE REMAINS VALUE.
            if(rowSum[i]<colSum[j]){
                //CHOOSE ROW ELEMENT
                result[i][j]=rowSum[i];
                rowSum[i]-=result[i][j];//RREOMVE CHOOSEN FROM THE ROW
                colSum[j]-=result[i][j];///ALSO SUBSTRACT THE VALUE FROM THE COLUMN ALSO AS ROW WAS A PART OF THAT COLUMN.
            }else{
                result[i][j]=colSum[j];
                colSum[j]-=result[i][j];
                rowSum[i]-=result[i][j];
            }
            //NOW AS WETHER OUR ANY ROW OR COLUMN VALUE BECOMES 0. INCREASE THE POINTER FOR THE NEXT VALUE AND COMPARE BETWEEN THOSE ROW AND COLUMN VALUE.
            if(rowSum[i]==0){
                i++;
            }
            if(colSum[j]==0){
                j++;
            }

        }
        return result;
                
        
    }
};