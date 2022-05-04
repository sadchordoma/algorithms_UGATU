#include <unordered_set>
#include "Graph.h"

using std::unordered_set;

class SetGraph : public IGraph{
public:

    explicit SetGraph(std::size_t vertices_count);

    SetGraph(const IGraph * graph);

    void AddEdge(int from, int to) override;

    std::size_t VerticesCount() const override {return size;}

    std::vector<int> FindAllAdjacentIn(int vertex) const override;
    std::vector<int> FindAllAdjacentOut(int vertex) const override;

private:
    std::size_t size = 0;
    std::vector<unordered_set<int>> out;
    std::vector<unordered_set<int>> in;
};
