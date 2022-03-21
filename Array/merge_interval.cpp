class Solution {
        // private:
        // bool static compareInterval(Interval i1, Interval i2)
        // {
        //     return (i1.start < i2.start);
        // }     
public:
     
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int rowsize=intervals.size();
        vector<vector<int>>v1;
        stack<pair<int,int>>s;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<rowsize;i++)
        {
            if(s.empty()){
                s.push({intervals[i][0],intervals[i][1]});
            }
            else{
                pair<int,int>p1;
                if(s.top().second >= intervals[i][0]){
                    p1=s.top();
                    s.pop();
                    s.push({p1.first,max(intervals[i][1],p1.second)});
                }
                else{
                    s.push({intervals[i][0],intervals[i][1]});
                }
            }
         
        }
        while(!s.empty()){
            vector<int>v;
            v.push_back(s.top().first);
            v.push_back(s.top().second);
            v1.push_back(v);
            s.pop();
            //free(v);
        }
        return v1;
    }
};