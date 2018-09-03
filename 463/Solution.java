import java.util.*;

class Solution {
    public int islandPerimeter(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int res = 0;

        // DFS and sum the num of unconnected edges of each island.
        HashSet<int[]> visited = new HashSet<int[]>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                res = dfsEdges(grid, i, j, visited);
                break;
            }
        }
        return res;
    }


    private int dfsEdges(int[][] grid, int i, int j, HashSet<int[]> visited) {
        int m = grid.length;
        int n = grid[0].length;
        int numEdges = 4;

        visited.add(new int[] {i, j});

        if (j-1 >= 0 && grid[i][j-1] == 1) {
            numEdges--;
            if(! visited.contains(new int[] {i, j-1})) {
                numEdges += dfsEdges(grid, i, j-1, visited);
            }
        }

        if (j+1 < n && grid[i][j+1] == 1) {
            numEdges--;
            if(! visited.contains(new int[] {i, j+1})) {
                numEdges += dfsEdges(grid, i, j+1, visited);
            }
        }

        if (i-1 >= 0 && grid[i-1][j] == 1) {
            numEdges--;
            if(! visited.contains(new int[] {i-1, j})) {
                numEdges += dfsEdges(grid, i-1, j, visited);
            }
        }

        if (i+1 < m && grid[i+1][j] == 1) {
            numEdges--;
            if(! visited.contains(new int[] {i+1, j})) {
                numEdges += dfsEdges(grid, i+1, j, visited);
            }
        }

        return numEdges;
    }

    public static void main(String[] args) {
      Solution s = new Solution();
      int[][] grid = {{1, 1}, {1, 1}};
      int res = s.islandPerimeter(grid);
      System.out.println(res);
    }
}
