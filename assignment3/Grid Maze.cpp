#include <bits/stdc++.h>
using namespace std;
int n,m;

enum class maze_obj{
    wall,
    floor,
    start,
    end,
};
struct position
{
    int i;
    int j;    
};

char find_rank(position &pos, int target_rank, vector<vector<int>>& rank){
    if(pos.i-1 >= 1){
        if(rank[pos.i-1][pos.j] == target_rank){
            pos.i--;
            return 'D';
        }
    }
    if(pos.i+1 <= n){
        if(rank[pos.i+1][pos.j] == target_rank){
            pos.i++;
            return 'U';
        }
    }
    if(pos.j-1 >= 1){
        if(rank[pos.i][pos.j-1] == target_rank){
            pos.j--;
            return 'R';
        }
    }
    if(pos.j+1 <= m){
        if(rank[pos.i][pos.j+1] == target_rank){
            pos.j++;
            return 'L';
        }
    }
    return 'F';// failed
}

void path_tracking(position end, position start, vector<vector<int>>& rank){
    position pos;
    pos.i = end.i; pos.j = end.j;
    int level = rank[end.i][end.j];
    stack<char> path;
    while(pos.i != start.i || pos.j != start.j){
        level--;
        path.push(find_rank(pos, level, rank));
    }
    while(!path.empty()){
        cout << path.top();
        path.pop();
    }
}

vector<position> visit_around(position current_pos, vector<vector<maze_obj>>& maze){
    vector<position> next_step;
    position pos;

    if(current_pos.i+1 <= n){// can down
        if(maze[current_pos.i+1][current_pos.j] == maze_obj::floor || maze[current_pos.i+1][current_pos.j] == maze_obj::end){
            pos.i = current_pos.i+1; pos.j = current_pos.j;
            next_step.emplace_back(pos);
        }
    }
    if(current_pos.i-1 >= 1){// can up
        if(maze[current_pos.i-1][current_pos.j] == maze_obj::floor || maze[current_pos.i-1][current_pos.j] == maze_obj::end){
            pos.i = current_pos.i-1; pos.j = current_pos.j;
            next_step.emplace_back(pos);
        }
    }
    if(current_pos.j+1 <= m){// can right
        if(maze[current_pos.i][current_pos.j+1] == maze_obj::floor || maze[current_pos.i][current_pos.j+1] == maze_obj::end){
            pos.i = current_pos.i; pos.j = current_pos.j+1;
            next_step.emplace_back(pos);
        }
    }
    if(current_pos.j-1 >= 1){// can left
        if(maze[current_pos.i][current_pos.j-1] == maze_obj::floor || maze[current_pos.i][current_pos.j-1] == maze_obj::end){
            pos.i = current_pos.i; pos.j = current_pos.j-1;
            next_step.emplace_back(pos);
        }
    }
    return next_step;
}

void bfs(position start, vector<vector<maze_obj>>& maze, vector<vector<int>>& rank){
    queue<position> que;
    rank[start.i][start.j] = 0;
    que.push(start);
    while(!que.empty()){
        position current_pos = que.front();
        // cout << "current_pos" << current_pos.i << " " << current_pos.j << "\n";
        que.pop();
        vector<position> next_step = visit_around(current_pos, maze);
        // cout << "next_step\n";
        for(auto v : next_step){
            // cout << v.i << " " << v.j << "\n";
            if(rank[v.i][v.j] == -1){
                que.push(v);
                rank[v.i][v.j] = rank[current_pos.i][current_pos.j] + 1;
            }
            if(maze[v.i][v.j] == maze_obj::end){
                cout << "YES\n" << rank[v.i][v.j] << "\n";
                path_tracking(v, start, rank);
                return;
            }
                
        }
    }
    cout << "NO\n";
    return;
}char find_rank(position &pos, int target_rank, vector<vector<int>>& rank);

int main(){
    cin>>n>>m;
    vector<vector<maze_obj>> maze(n+1, vector<maze_obj>(m+1));
    vector<vector<int>> rank(n+1, vector<int>(m+1, -1));
    position start;
    char ch;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>ch;
            if(ch == '#')
                maze[i][j] = maze_obj::wall;
            else if(ch == '.')
                maze[i][j] = maze_obj::floor;
            else if(ch == 'A'){
                maze[i][j] = maze_obj::start;
                start.i = i; start.j = j;
            }
            else if(ch == 'B')
                maze[i][j] = maze_obj::end;
        }
    }   
    bfs(start, maze, rank);

}