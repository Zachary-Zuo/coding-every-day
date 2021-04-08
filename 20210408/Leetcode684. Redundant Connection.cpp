class UF
{
    vector<int> id, size;

public:
    UF(int n) : id(n), size(n, 1)
    {
        iota(id.begin(), id.end(), 0);
    }
    int find(int p)
    {
        while (p != id[p])
        {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    void connect(int p, int q)
    {
        int i = find(p), j = find(q);
        if (i != j)
        {
            if (size[i] < size[j])
            {
                id[i] = j;
                size[j] += size[i];
            }
            else
            {
                id[j] = i;
                size[i] += size[j];
            }
        }
    }
    bool isConnected(int p, int q) { return find(p) == find(q); }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        UF uf(n + 1);
        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            if (uf.isConnected(u, v))
            {
                return e;
            }
            uf.connect(u, v);
        }
        return vector<int>{-1, -1};
    }
};
