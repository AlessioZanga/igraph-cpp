#pragma once

#include "graph.ipp"

namespace igraph {

namespace structures {

class DirectedGraph : public Graph {
   protected:
    explicit DirectedGraph(const igraph_t *other);

   public:
    DirectedGraph();
    explicit DirectedGraph(const std::string &formula);
    explicit DirectedGraph(const Nodes &nodes);
    explicit DirectedGraph(const Edges &edges);
    DirectedGraph(const Graph &other);
    DirectedGraph(const DirectedGraph &other);
    DirectedGraph &operator=(const DirectedGraph &other);
    virtual ~DirectedGraph();

    bool is_dag() const;

    Graph to_undirected() const;

    [[deprecated]]
    void reverse_edge(const Node &from, const Node &to);

    Nodes parents(const Node &node) const;
    Nodes family(const Node &node) const;
    Nodes children(const Node &node) const;
    Nodes ancestors(const Node &node) const;
    Nodes descendants(const Node &node) const;

    friend Nodes topological_sorting(const DirectedGraph &other);

    static DirectedGraph random(size_t nodes, double edge_probability);
};

}  // namespace structures

}  // namespace igraph
