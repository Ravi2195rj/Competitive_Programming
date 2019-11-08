class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        int row=matrix.size();
        if(row == 0)
            return false;
        int col=matrix[0].size();
        
        // actually you have given n*m array in sorted order in matrix form 
        // so apply BS on matrix in same way as we apply on array 
        
        int low=0;
        int high= row*col -1;
        
        while(low<=high)
        {
            int mid = (low+high) / 2;
            int midval = matrix[mid/col][mid%col] ; 
            if(midval==target)
            {
                return true;
            }
            else if(midval > target)
            {
                high = mid - 1;
            }
            else // midval < target
            {
                low = mid + 1;
            }
        }
        return false;
    }
}
