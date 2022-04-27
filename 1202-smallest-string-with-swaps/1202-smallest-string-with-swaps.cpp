class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int u ) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    
    void union1(int x, int y) {
        int root1 = find(x);
        int root2 = find(y);
        if (root1 == root2) return ;
        if (rank[root2] >= rank[root1]) {
            parent[root1] = root2;
            rank[root2]++;
        }
        else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        parent.assign(n, 0);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (auto &pair : pairs) {
            union1(pair[0], pair[1]);
        }
        unordered_map<int, vector<int>> child;
        for (int i = 0; i < n; i++){
            child[find(i)].push_back(i);
           
        }
        for (auto &p : child) {
           string temp = "";
            for (int i : p.second) temp += s[i];
            sort(temp.begin(), temp.end());
            int k = 0;
            for (int i : p.second)
                s[i] = temp[k++];
        }
        return s;
    }
};