class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q; //for storing only rotten oranges
        int row=grid.size();
        int col=grid[0].size();
        int total=0;
        
        //now loop for counting total oranges and pushing rotten in queue for doing bfs;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int countRotten=0; //this will calculate the number of oranges our queue will rott
        int time=0;//this will count number of second elapsed after each queue iteration
        
        //now making the dx and dy, they help in accessignt he 4 adjacent direction of each rotten orange index
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        
        while(!q.empty())
        {
            int k=q.size(); //every time we have to run for k oranges ka first second, becoz they are going to rott their next adjancet ones;
            countRotten+=k;
            
            while(k--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                //for each rotten orange that we fetch from queue we go its all 4 direction, if any fresh orange found then usko rott krke queue me daal do
                for(int i=0;i<4;i++)
                {
                    int newx=x-dx[i];
                    int newy=y-dy[i];
                    if(newx<row && newx>=0 && newy<col && newy>=0 && grid[newx][newy]!=2 && grid[newx][newy]!=0){
                        grid[newx][newy]=2;
                        q.push({newx,newy});
                    }
                }
            }
            //think of last iteration, usme queue empty rhega and hme wo time nhi lena,becoz all got rotten
            if(!q.empty()) time++;
        }
        if (countRotten==total) {return time;}
        else {cout<<countRotten<<" "<<total; return -1;}
        
    }
};