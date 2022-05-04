#include <vector>
struct IGraph {
    virtual ~IGraph() {}

    virtual void AddEdge(int from, int to) = 0;

    virtual std::size_t VerticesCount() const  = 0;

    virtual std::vector<int> FindAllAdjacentIn(int vertex) const = 0;
    virtual std::vector<int> FindAllAdjacentOut(int vertex) const = 0;
};
