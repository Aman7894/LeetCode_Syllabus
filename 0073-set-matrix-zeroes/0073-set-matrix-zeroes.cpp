class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> col(n, false);

    // First pass: record rows and columns that need to be zeroed
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    // Second pass: update the matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

};