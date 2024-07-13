class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        //APPORACH:- SO IN THIS QUESTION WE SHOULD FOLLOW LIKE FIRST WE NEED TO PROCESS THE ROBOTS BASED ON THEIR SORTED POSITION LIEK POS(2,3,5,9,... IN THIS ORDER).FOR THIS FIRST WE WILL SORT THE ROBOTS BY THEIR POSITION FROM LEFT TO RIGHT. THEN WE WILL COMPARE THE TWO ROBOTS IF THEY ARE IN THE OPPOSITE DIRECTION THEN BASED ON THEIR HEALTH WE WILL PERFORM THE OPREATIONS WHICH WE HAVE GIVEN AND WE WILL COMPARE THE DIRECTION USING THE STACK.

        int n=positions.size();
        //CREATING THE VECTOR WHICH WILL BE USED AS A SORTED DIRECTION TO PERFORM THE OPRATION IN PROPER WAY.
        vector<int> sort_By_Pos(n);
        for(int i=0;i<n;i++){
            sort_By_Pos[i]=i;
        }

        //we will write the lambda function which we now just sort our own define array named sort_By_Pos based on the smallest position from left to biggest position in the right. remember we are not sorting actual position array beacause we are going to use the health and direction of the robots based on the position array.
        //M.imp:- we have to retrun the answer in the same sequance as it was given to us in the position array that's the main thing.

        auto lambda=[&](int &i ,int &j){
            return positions[i] <positions[j];
        };

        sort(sort_By_Pos.begin(),sort_By_Pos.end(),lambda);//SORTING THE VECTOR BASED ON THE LOWEST POSITION TO HIGHEST POSITION.
        
        vector<int> result;
        stack<int> st;

        for(const auto currIndex: sort_By_Pos){
            //HERE AS WE SAID WE WILL ACESS THE VALUE BASED ON THE ORIGINAL POSITONS OF THE ROBOTS . AND HERE CURRENT INDEX WILL DO THAT WORK FOR US BY DIRECTLY ACCESS THE VARIABLE BASED ON MAPPING FROM POSITONS VECTOR  ORDER TO THE OTHER DIRECTIONS VECTOR OF THE ROBOTS.
            if(directions[currIndex]=='R'){
                st.push(currIndex);
            }else{
                while(!st.empty() && healths[currIndex]>0){
                    int topIndex=st.top();
                    st.pop();
                    //IF CURRENT ROBOT HEALTH IS LOWER THAN THE TOP MOST ROBTOS
                    if(healths[topIndex]>healths[currIndex]){
                        healths[topIndex]-=1;
                        healths[currIndex]=0;
                        st.push(topIndex);//AGAIN ADD IT TO THE STACK
                    }//IF CURRENT ROBOT HEALTH IS HIGHER THAN THE TOP MOST ROBTOS
                    else if(healths[topIndex]<healths[currIndex]){
                        healths[currIndex]-=1;
                        healths[topIndex]=0;
                    }else{
                        //IF BOTH ARE EQUAL.
                        healths[currIndex]=0;
                        healths[topIndex]=0;
                    }
                }
            }
        }
        //JUST RETURN THE RESULT BASED ON THE HEALTHS OF ROBOTS WHICH SHOULD BE GREATER THAN 0.
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
        }

        return result; 
    }
};