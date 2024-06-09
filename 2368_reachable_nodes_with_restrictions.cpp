#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int answer = 0;
        vector< vector<bool> > visited(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue;
                if(grid[i][j] == 0) continue;
                int cnt = 0;
                visited[i][j] = 1;
                queue< pair<int,int> > que;
                que.push({i, j});
                while(que.size()){
                    cnt += 1;
                    pair<int,int> v = que.front();
                    que.pop();
                    int x = v.first, y = v.second;
                    vector < pair<int,int> > adjacent = {
                        {x - 1, y},
                        {x, y - 1},
                        {x + 1, y},
                        {x, y + 1}
                    };
                    for(auto u : adjacent){
                        int new_x = u.first, new_y = u.second;
                        if(new_x >= 0 and new_x < m and new_y >= 0 and new_y < n){
                            if(grid[new_x][new_y] == 1 and visited[new_x][new_y] == 0){
                                visited[new_x][new_y] = 1;
                                que.push({new_x, new_y});
                            }
                        }
                    }
                }
                answer = max(answer, cnt);
            }
        }
        return answer;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> grid={
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}
	};
	sol.maxAreaOfIsland(grid);
}