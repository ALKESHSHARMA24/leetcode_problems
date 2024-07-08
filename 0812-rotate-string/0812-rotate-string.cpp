class Solution {
public:
    bool rotateString(string s, string goal) {
        //INTUTION:- WE WILL BE USING 2 QUEUES AND AFTER PERFORMING THE PUSH POP OPEARTION WE WILL DO COMPARE BOTH QUEUES AND CHECK THAT NOW IS IT SAME OR NOT. IF AT PARTICULAR TIME WHEN BOTH QUEUE BECOMES EQUAL MEANS WE CAN FIND THE GOAL STRING AFTER PERFORMING SOME NUMBER OF ROTATION. AND WE CAN DO MAX NUMBERS OF THIS OPERATION  TIMES DEPENDS ON THE STRING S SIZE .
        
        if(s==goal){
            return true;
            
        }

        queue<char> queueS,queueGoal;

        for(int i=0;i<s.length();i++){
            queueS.push(s[i]);
        }
        for(int i=0;i<goal.length();i++){
            queueGoal.push(goal[i]);
        }

        int maxRotation=queueGoal.size()-1;
        while(maxRotation--){
            char ch=queueS.front();
            queueS.pop();
            queueS.push(ch);

            if(queueS == queueGoal){
                return true;
            }
        }

        return false;
    }
};