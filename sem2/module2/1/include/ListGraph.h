#include "Graph.h"

class ListGraph : public IGraph {
public:
    explicit ListGraph(std::size_t vertices_count);

    ListGraph(const IGraph * graph);

    void AddEdge(int from, int to) override;

    std::size_t VerticesCount() const override { return size; }

    std::vector<int> FindAllAdjacentIn(int vertex) const override;
    std::vector<int> FindAllAdjacentOut(int vertex) const override;

private:
    std::vector<std::vector<int>> childs_;
    std::vector<std::vector<int>> parents_;
    std::size_t size = 0;
};
