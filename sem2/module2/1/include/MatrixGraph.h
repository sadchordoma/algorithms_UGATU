#include <set>
#include "Graph.h"

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(std::size_t vertices_count);

    MatrixGraph(const IGraph * graph);

    void AddEdge(int from, int to) override;

    std::size_t VerticesCount() const override {return size;}

    std::vector<int> FindAllAdjacentIn(int vertex) const override;
    std::vector<int> FindAllAdjacentOut(int vertex) const override;

private:
    std::vector<std::vector<bool>> g;
    std::size_t size = 0;
};
