#include <set>
#include "Graph.h"

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(std::size_t vertices_count);

    ArcGraph(const IGraph * graph);

    void AddEdge(int from, int to) override;

    std::size_t VerticesCount() const override { return size; }

    std::vector<int> FindAllAdjacentIn(int vertex) const override;
    std::vector<int> FindAllAdjacentOut(int vertex) const override;

private:
    std::vector<std::pair<int, int>> edges;
    std::set<int> vertices;
    std::size_t size = 0;
};
