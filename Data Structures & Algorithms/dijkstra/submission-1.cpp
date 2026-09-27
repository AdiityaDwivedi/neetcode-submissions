class Solution {
public:
    int dijkstra(vector<vector<int>>& edges, int src, int dest, int n) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == dest) return distance;
            if(distance > dist[node]) continue;

            for(auto it : adj[node]) {
                int nextNode = it.first;
                int weight = it.second;
                

                int newDistance = distance + weight;
                
                if(newDistance < dist[nextNode]) {
                    dist[nextNode] = newDistance;
                    pq.push({newDistance, nextNode});
                }
            }
        }
        return -1;
    }

    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int k = dijkstra(edges, src, i, n);
            mp[i] = k;
        }
        return mp;
    }
};











