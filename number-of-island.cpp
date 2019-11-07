class Solution {
public:
    int n,m;
    void dfs(int x,int y, vector<vector<char>> &grid)
    {
        //cout<<"x :"<<x<<endl;
        //cout<<"y :"<<y<<endl;
        
        grid[x][y]=0;
        
        int xx[]={-1,+1,0,0};
        int yy[]={0,0,+1,-1};
        
        for(int i=0;i<4;i++)
        {
            int newx=x+xx[i];
            int newy=y+yy[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='1')
            {
                dfs(newx,newy,grid);
            }
                
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size()==0)
            return 0;
        
        int count=0;
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    //cout<<"hello"<<endl;
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
        
        //BFS Solution
        
        // m = grid.size();
        // n = grid[0].size();
        // int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // int res = 0;
        // vector<vector<bool>> seen (m, vector<bool> (n));
        // for (int i = 0; i < m; i++) 
        // {
        //     for (int j = 0; j < n; j++) 
        //     {
        //         if (grid[i][j] == '0' || seen[i][j]) {
        //             continue;
        //         }
        //         res++;
        //         queue<pair<int, int>> q;
        //         q.push({i, j});
        //         seen[i][j] = true;
        //         while (!q.empty()) {
        //             int x = q.front().first;
        //             int y = q.front().second;
        //             q.pop();
        //             for (auto& d: dirs) {
        //                 int xx = x + d[0], yy = y + d[1];
        //                 if (inBound(xx, yy) && grid[xx][yy] == '1' && !seen[xx][yy]) {
        //                     seen[xx][yy] = true;
        //                     q.push({xx, yy});
        //                 }
        //             }
        //         }   
        //     }
        // }
    }
};
