class Solution {
public:
    
    int maxEvents(vector<vector<int>>& events) {
        
    sort(events.begin(), events.end());
    int n = events.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    int count =0, day = events[0][0];
    int i = 0;

    int maxi = events[0][1];

    for(auto x : events){
        maxi = max(maxi,x[1]);
    }
    while(day <= maxi){
        
         while(i < n && day == events[i][0]){
            pq.push(events[i][1]);
            i++;
        }

        if(!pq.empty()){
             pq.pop();
        count++;
        }
       
        
          while(!pq.empty() && day >= pq.top()){
            pq.pop();
            // count++;
        }

       


      
        day++;
    }

    return count;
        
    }
};