class Solution {
public:

    bool IsPossible = false ; 

    void helper(vector<vector<int>> &trackUsed , string &word , int pos ,  vector<vector<char>>& board , int row , int col , bool &IsPossible   ){

        if(pos == word.size()){
            IsPossible = true;
            return;
        }

        if(row >= board.size() || row < 0 || col >= board[0].size() || col < 0){
            return ;
        }

        if( board [row ] [ col ] != word[pos] ){
            return;
        }

        if(trackUsed [row] [col] == 0){
            return ;
        }


        if( board[row][col] == word[pos]){
            trackUsed [row] [col] = 0;
            pos++;
        }


        //try all the possible directions to find the next word combinations

         helper(trackUsed , word , pos , board , row , col-1 , IsPossible ); 
         helper(trackUsed , word , pos , board , row , col+1 , IsPossible ); 
         helper(trackUsed , word , pos , board , row-1 , col , IsPossible ); 
         helper(trackUsed , word , pos , board , row+1 , col , IsPossible ); 

        //If with the current starting point we are not able to find the string matching combination then agian makea all the points to  unvisited for the new starting point . so that we can again try all the combinations with fresh and scratch.
        trackUsed[row][col] = 1;
        

    }
    bool exist(vector<vector<char>>& board, string word) {
        
       vector<vector<int>> trackUsed (board.size() , vector <int> (board[0].size() , 1));
       
       
        for(int i = 0; i < board.size() ; i++){

            for( int j = 0 ; j < board[0].size(); j++ ){

                if(board[i][j] == word[0]){

                    helper( trackUsed , word , 0 , board , i , j , IsPossible );
                    if(IsPossible) return true;

                }

            }
        }

        return false ;


    }
};