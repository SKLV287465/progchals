#include <unordered_map>


template <typename T>
class UF {
public:
    void make_set(const T& x) {
        parent[x] = x;
        rank[x] = 0;
    }

    T find(const T& x) {
        if (parent[x] != x) {
            parent[x] = find(x);
        }
        return parent[x];
    }

    void unite(const T& x, const T& y) {
        T rootx = find(x);
        T rooty = find(y);
        if (rootx == rooty) return;
        if (rank[rootx] < rank[rooty]) {
            parent[rootx] = rooty;
        } else if (rank[rooty] < rank[rootx]) {
            parent[rooty] = rootx;
        } else {
            parent[rooty] = rootx;
            rank[rootx]++;
        }
    }

    bool connected(const T& x, const T& y) {
        return find(x) == find(y);
    }

private:
    std::unordered_map<T, T> parent;
    std::unordered_map<T, int> rank;
};