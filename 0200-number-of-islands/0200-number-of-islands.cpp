
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {       
        int m = grid.size();
        int n = grid[0].size();       
        int count = 0;
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1}; 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {                    
                    count++;                   
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';                 
                    while(!q.empty()) {                      
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++) {                           
                            int newRow = row + delRow[k];
                            int newCol = col + delCol[k];
                            if(newRow >= 0 && newRow < m &&
                               newCol >= 0 && newCol < n &&
                               grid[newRow][newCol] == '1') {                              
                                grid[newRow][newCol] = '0';
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }        
        return count;
    }
};
