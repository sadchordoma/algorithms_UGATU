#include "ListGraph.h"

ListGraph::ListGraph(std::size_t vertices_count) : childs_(vertices_count), parents_(vertices_count), size(vertices_count) {}

ListGraph::ListGraph(const IGraph * graph) {
    size = graph->VerticesCount();
    childs_.resize(size);
    parents_.resize(size);
    for (int i = 0; i < size; i++) {
        std::vector<int> vertices_;
        vertices_ = graph->FindAllAdjacentOut(i);
        for (auto el: vertices_) {
            ListGraph::AddEdge(i, el);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    childs_[from].push_back(to);
    parents_[to].push_back(from);
}

std::vector<int> ListGraph::FindAllAdjacentIn(int vertex) const {
    return parents_[vertex];
}

std::vector<int> ListGraph::FindAllAdjacentOut(int vertex) const {
    return childs_[vertex];
}
