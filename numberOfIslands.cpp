/*
Problem 200: Number Of Islands
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size(); //m = rows
        int cols = grid[0].size(); //n = columns
        int islands = 0;

        // up, down, right, left
        vector<pair<int, int>> directions = {{0,1}, {0, -1}, {1,0}, {-1, 0}}; 

        //iterate through rows and columns
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == '1'){
                    islands++;

                    //BFS: visit coordinates and add next to be visited to queue
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    //mark as visited 
                    grid[i][j] = '0';

                    while (!q.empty()){
                        //visiting coords
                        pair<int, int> current = q.front();
                        q.pop();

                        // goes through every direction for a coord
                        for (pair<int,int>& dir : directions){
                            //determines coordinate (current + direction)
                            int newRow = current.first + dir.first;
                            int newCol = current.second + dir.second;

                            //makes sure rows & cols not out of bounds: >= 0 && < m/n
                            if (newRow >= 0 && newRow < rows 
                                && newCol >= 0 && newCol < cols 
                                //if 1: add to queue to check for surrounding 1's
                                && grid[newRow][newCol] == '1'){
                                    q.push({newRow,newCol});
                                    grid[newRow][newCol] = '0'; //mark as visited
                            }
                        }
                    }
                    
                }
            }
        }
        
        // space complexity: O(min(M,N)) --> the max number of coords in the queue is the minimum dimension of the grid
        //  time complexity: O(M x N) --> every cell is visited at least once, added and removed from the queue once
        return islands;
    }
};
