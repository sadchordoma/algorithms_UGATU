#include "SetGraph.h"

SetGraph::SetGraph(std::size_t vertices_count) : out(vertices_count), in(vertices_count), size(vertices_count) {}

SetGraph::SetGraph(const IGraph * graph) {
    size = graph->VerticesCount();
    out.resize(size);
    in.resize(size);
    for (int i = 0; i < size; i++) {
        std::vector<int> vertices_;
        vertices_ = graph->FindAllAdjacentOut(i);
        for (auto el: vertices_) {
            SetGraph::AddEdge(i, el);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    out[from].insert(to);
    in[to].insert(from);
}

std::vector<int> SetGraph::FindAllAdjacentIn(int vertex) const {
    std::vector<int> vertices_;
    for (auto el: out[vertex]) {
        vertices_.push_back(el);
    }
    return vertices_;
}

std::vector<int> SetGraph::FindAllAdjacentOut(int vertex) const {
    std::vector<int> vertices_;
    for (auto el: in[vertex]) {
        vertices_.push_back(el);
    }
    return vertices_;
}
