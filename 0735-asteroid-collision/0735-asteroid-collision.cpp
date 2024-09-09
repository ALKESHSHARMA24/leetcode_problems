class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
       //use stack implemention of stack inform of array because stack will give the result in revrese form
        vector<int>st;
        for(int i=0;i<asteroid.size();i++){
          
            //4 scenerios
            if(asteroid[i]>0){
                //only pos
                st.push_back(asteroid[i]);
            }else{
                //neg>pos
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroid[i])){
                    st.pop_back();
                }

                //neg=pos
                if(!st.empty() && st.back()==abs(asteroid[i])){
                    st.pop_back();
                }
                //only neg
                else if(st.empty() || st.back()<0){
                    st.push_back(asteroid[i]);
                }
            }
        }
        return st;
        
    }
};