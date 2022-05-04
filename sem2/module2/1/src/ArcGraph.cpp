#include "ArcGraph.h"

ArcGraph::ArcGraph(std::size_t vertices_count) {
    edges.clear();
    vertices.clear();
    size = vertices_count;
}

ArcGraph::ArcGraph(const IGraph * graph) {
    size = graph->VerticesCount();
    for (int i = 0; i < size; i++) {
        std::vector<int> vertices_;
        vertices_ = graph->FindAllAdjacentOut(i);
        for (auto el: vertices_) {
            ArcGraph::AddEdge(i, el);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back({from, to});
    this->vertices.insert(from);
    this->vertices.insert(to);
}

std::vector<int> ArcGraph::FindAllAdjacentIn(int vertex) const {
    std::vector<int> vertices_;
    for (auto [from, to] : edges) {
        if (to == vertex) {
            vertices_.push_back(from);
        }
    }
}

std::vector<int> ArcGraph::FindAllAdjacentOut(int vertex) const {
    std::vector<int> vertices_;
    for (auto [from, to] : edges) {
        if (from == vertex) {
            vertices_.push_back(to);
        }
    }
}
