class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // transpose along diagonal
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            // reverse every row of the transpose matrix-> row is matrix[i]
            reverse(matrix[i].begin(), matrix[i].end() );
        }
        
    }
};