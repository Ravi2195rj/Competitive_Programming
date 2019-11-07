class Solution {
public:
    
    int dir[4][2] = { {1,0},{0,1},{0,-1},{-1,0} };
    
    /* we don't required visited matrix here, 
        because as we traverse we update "O" to "W", && we do recursion only if "O" present, so only unvisited node will be encounter during DFS.
    */
    void dfs(int i, int j, int row, int col, 
            vector<vector<char> > &A)
    {
        int ii,jj;
        A[i][j]='W';
        for(int k=0;k<4;k++)
        {
            ii = i+dir[k][0];
            jj = j+dir[k][1];
            if(ii>=0 && ii<row && jj>=0 && jj<col)
            {
                if(A[ii][jj]=='O')
                {
                  
                    dfs(ii,jj,row,col,A);

                }
            }
        }
    }
    void solve(vector<vector<char>>& A) {
        
        int row = A.size();
        if(row==0)
            return;
        
        int col = A[0].size();

        for(int i=0;i<row;i++)
        {
            if(A[i][0]=='O')
            {
                dfs(i,0,row,col,A);
            }
        }
        for(int i=0;i<col;i++)
        {
            if(A[0][i]=='O')
            {
                dfs(0,i,row,col,A);
            }
        }
        for(int i=0;i<row;i++)
        {
            if(A[i][col-1]=='O')
            {
                dfs(i,col-1,row,col,A);
            }
        }

        for(int i=0;i<col;i++)
        {
            if(A[row-1][i]=='O')
            {
                dfs(row-1,i,row,col,A);
            }
        }
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j <col; j++) 
            {
                if (A[i][j] == 'W')
                    A[i][j] = 'O';
                else 
                    A[i][j] = 'X';
            }
        }
        
    }
};
