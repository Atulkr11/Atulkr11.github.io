#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px != py)
        {
            if (rank[px] < rank[py])
            {
                parent[px] = py;
            }
            else
            {
                parent[py] = px;
                if (rank[px] == rank[py])
                {
                    rank[px]++;
                }
            }
        }
    }

private:
    vector<int> parent, rank;
};

vector<pii> kruskal_mst(const Graph &graph)
{
    int n = graph.size();
    UnionFind uf(n);
    vector<pii> edges;
    vector<pii> mst_edges;

    // Populate edges vector with all edges in the graph
    for (int i = 0; i < n; i++)
    {
        for (auto neighbor : graph[i])
        {
            int j = neighbor.first, w = neighbor.second;
            if (i < j)
            {
                edges.push_back(make_pair(w, i * n + j));
            }
        }
    }
    sort(edges.begin(), edges.end());

    // Find minimum spanning tree
    for (auto edge : edges)
    {
        int i = edge.second / n, j = edge.second % n;
        if (uf.find(i) != uf.find(j))
        {
            uf.unite(i, j);
            mst_edges.push_back(make_pair(i, j));
        }
    }

    return mst_edges;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }
    auto mst = kruskal_mst(graph);
    int mst_weight = 0;
    for (auto edge : mst)
    {
        mst_weight += edge.second;
    }
    cout << "Minimum Spanning Tree:" << endl;
    for (auto edge : mst)
    {
        cout << edge.first << " -- " << edge.second << endl;
    }
    cout << "Total weight: " << mst_weight << endl;
    return 0;
}