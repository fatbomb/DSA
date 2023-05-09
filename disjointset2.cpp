// implementation of dsu using array

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    int n;       // total node number
    int *parent; // for storing root
    int *rank;   // for storing height
    int *size;   // for storing node number

public:
    DisjointSet(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];
        size = new int[n + 1];

        makeset();
    }
    DisjointSet()
    {
        this->n = 1e6;
        parent = new int[n + 1];
        rank = new int[n + 1];
        size = new int[n + 1];
    }

    void makeset()
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int find(int x) // find function with path compression
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unionByRank(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }

    void unionBySize(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (size[rootX] < size[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};