#include <iostream>
#include <map>
#include <queue>

using namespace std;

int n;

vector<int> a, b, c;

vector<vector<bool>> visited;

vector<vector<int>> maximum_total_points;

int recurse(int i, int t){
    if(visited[i][t]){
        return maximum_total_points[i][t];
    }
    visited[i][t] = 1;
    if(i == 0){
        if(t == 0){
            maximum_total_points[i][t] = a[i];
        }else if(t == 1){
            maximum_total_points[i][t] = b[i];
        }else{
            maximum_total_points[i][t] = c[i];
        }
    }else{
        int current_point = 0;
        if(t == 0){
            current_point = a[i];
        }else if(t == 1){
            current_point = b[i];
        }else{
            current_point = c[i];
        }
        for(int j = 0; j < 3; j++){
            if(j != t){
                maximum_total_points[i][t] = max(maximum_total_points[i][t], recurse(i - 1, j) + current_point);
            }
        }
    }
    return maximum_total_points[i][t];
}

int main(){
    cin >> n;

    a.resize(n);
    b.resize(n);
    c.resize(n);
    visited = vector<vector<bool>>(n, vector<bool>(3));
    maximum_total_points = vector<vector<int>>(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int answer = 0;
    answer = max(answer, recurse(n - 1, 0));
    answer = max(answer, recurse(n - 1, 1));
    answer = max(answer, recurse(n - 1, 2));
    cout << answer << "\n";
}