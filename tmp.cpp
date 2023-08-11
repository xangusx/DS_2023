# include <iostream>
# include <vector>
# include <queue>

std::vector<int> TopologicalSort(std::vector<std::vector<int>> &G, std::vector<int> ind, int &n){
    std::vector<int> ans;
    std::queue<int> q;
    //std::cout << "start by: " << start << std::endl;
    for(int i = 1; i <= n; i++){
        if(!ind[i])
            q.emplace(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.emplace_back(u);
        for(auto v: G[u]){
            ind[v]--;
            //std::cout << v << "/" << ind[v] << "\n";
            if(!ind[v]){
                q.emplace(v);
                //std::cout << "can go: " << v << "\n";
            }
        }
    }
    return ans;
}

int back_tp(const std::vector<std::vector<int>> &G, std::vector<int> &after_tpsort, const int &n){
    std::vector<int> dp(n+1, 0);
    for(std::vector<int>::reverse_iterator it = after_tpsort.rbegin(); it != after_tpsort.rend(); ++it){
        int max = 0;
        for(auto &v : G[*it]){
            if(dp[v] > max)
                max = dp[v];
        }
        dp[*it] = 1 + max;
    }
    return dp[1];
}


int main(){
    int vertex_num, edge_num;
    std::cin >> vertex_num >> edge_num;
    std::vector<std::vector<int>> Graph(vertex_num + 1);
    std::vector<int> indegree(vertex_num + 1, 0);
    
    for(int i = 0; i < edge_num; i++){
        int u, v;
        std::cin >> u >> v;
        Graph[u].emplace_back(v);
        indegree[v]++;
    }
    std::vector<int> after_tpsort = TopologicalSort(Graph, indegree, vertex_num);
    if(back_tp(Graph, after_tpsort, vertex_num) == vertex_num)
        std::cout << "Yes";
    else
        std::cout << "No"; 
}