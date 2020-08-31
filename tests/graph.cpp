#include <gtest/gtest.h>

#include "graph.ipp"

#define N {"1", "2", "3", "4", "5"}
#define N_SIZE 5

using namespace igraph;

TEST(TestGraph, DefaultContructor) {
    Graph g0, g1(N);
    ASSERT_EQ(g1.size(), N_SIZE);
}

TEST(TestGraph, CopyConstructor) {
    Graph g0(N);
    Graph g1(g0);
    ASSERT_EQ(g0.size(), g1.size());
}

TEST(TestGraph, AssignmentConstructor) {
    Graph g0(N);
    Graph g1 = g0;
    ASSERT_EQ(g0.size(), g1.size());
}

TEST(TestGraph, Destructor) {
    Graph *g = new Graph(N);
    ASSERT_EQ(g->size(), N_SIZE);
    delete g;
}

TEST(TestGraph, EdgesConstructor) {
    Nodes nodes = {"A", "B", "C", "D"};
    Edges edges = {
        {"A", "B"},
        {"A", "C"},
        {"B", "C"},
        {"A", "D"},
        {"B", "D"},
        {"C", "D"}
    };
    Graph g(edges);
    ASSERT_EQ(g.get_nodes(), nodes);
    ASSERT_EQ(g.get_edges(), edges);
}

TEST(TestGraph, GetNodes) {
    Graph g(N);
    ASSERT_EQ(g.get_nodes(), Nodes(N));
}

TEST(TestGraph, SetNodes) {
    Graph g(N);
    ASSERT_EQ(g.get_nodes(), Nodes(N));
    g.set_nodes(N);
    ASSERT_EQ(g.get_nodes(), Nodes(N));
}

TEST(TestGraph, GetEdges) {
    Edges edges;
    Graph g(N);
    ASSERT_EQ(g.get_edges(), edges);
    Nodes nodes = g.get_nodes();
    g.add_edge(nodes[0], nodes[1]);
    g.add_edge(nodes[0], nodes[2]);
    g.add_edge(nodes[2], nodes[2]);
    edges.push_back({nodes[0], nodes[1]});
    edges.push_back({nodes[0], nodes[2]});
    edges.push_back({nodes[2], nodes[2]});
    ASSERT_EQ(g.get_edges(), edges);
}

TEST(TestGraph, HasNode) {
    Graph g(N);
    ASSERT_TRUE(g.has_node(g.get_nodes()[0]));
    ASSERT_FALSE(g.has_node(""));
}

TEST(TestGraph, AddNode) {
    Graph g(N);
    ASSERT_EQ(g.get_nodes(), Nodes(N));
    Nodes nodes = g.get_nodes();
    nodes.push_back(std::to_string(g.size() + 1));
    g.add_node(nodes.back());
    ASSERT_EQ(g.get_nodes(), nodes);
}

TEST(TestGraph, RemoveNode) {
    Graph g(N);
    ASSERT_EQ(g.get_nodes(), Nodes(N));
    Nodes nodes = g.get_nodes();
    g.remove_node(nodes[2]);
    nodes.erase(nodes.cbegin() + 2);
    ASSERT_EQ(g.get_nodes(), nodes);
}

TEST(TestGraph, HasEdge) {
    FAIL();
}

TEST(TestGraph, AddEdge) {
    Graph g(N);
    Nodes nodes = g.get_nodes();
    g.add_edge(nodes[0], nodes[1]);
    Edges edges = g.get_edges();
    auto it = std::find(edges.begin(), edges.end(), Edge({nodes[0], nodes[1]}));
    ASSERT_NE(it, edges.end());
}

TEST(TestGraph, RemoveEdge) {
    Graph g(N);
    Nodes nodes = g.get_nodes();
    g.add_edge(nodes[0], nodes[1]);
    g.remove_edge(nodes[0], nodes[1]);
    Edges edges = g.get_edges();
    auto it = std::find(edges.begin(), edges.end(), Edge({nodes[0], nodes[1]}));
    ASSERT_EQ(it, edges.end());
}

TEST(TestGraph, Subgraph) {
    Graph g(N);
    Nodes n = g.get_nodes();
    n.pop_back();
    Graph s = g.subgraph(n);
    ASSERT_EQ(s.get_nodes(), n);
}

TEST(TestGraph, Size) {
    Graph g(N);
    ASSERT_EQ(g.size(), N_SIZE);
}

TEST(TestGraph, IsDirected) {
    Graph g(N);
    ASSERT_FALSE(g.is_directed());
}

TEST(TestGraph, IsChordal) {
    FAIL();
}

TEST(TestGraph, IsComplete) {
    FAIL();
}

TEST(TestGraph, Neighbors) {
    FAIL();
}

TEST(TestGraph, Boundary) {
    FAIL();
}