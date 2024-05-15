/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

namespace ariel {
    using IndexType = typename std::vector<int>::size_type; // Define a type alias for vector index type
    class Graph { // our namespace
    private:
        int numVertices;
        std::vector<std::vector<int>> adjMatrix;

    public:
        // Constructor taking the number of vertices
        Graph() : numVertices(), adjMatrix(0, std::vector<int>(0, 0)) {} // empty graph

        // Constructor taking the adjacency matrix
        // Constructor taking the adjacency matrix
        Graph(const std::vector<std::vector<int>>& Mat) : adjMatrix(Mat) {
            this->numVertices = Mat.size();
        }

        int getNumVertices() const;
        std::vector<std::vector<int>> getAdjMatrix() const;
        void loadGraph(const std::vector<std::vector<int>>& adjMat);
        void printGraph();

//---------------------------operators---------------------------

        friend Graph& operator+(Graph g1, Graph g2); // plus operator
        friend Graph& operator+=(Graph g1, Graph g2); // addition operator
        friend Graph& operator+(Graph g, int c); // Unary plus operator
        friend Graph& operator-(Graph g1, Graph g2); // matrix subtraction operator
        friend Graph& operator-=(Graph g1, Graph g2); // subtraction operator
        friend Graph& operator-(Graph g, int c); // Unary minus operator

        friend Graph& operator>(Graph g1, Graph g2); // Unary minus operator
        friend Graph& operator>=(Graph g1, Graph g2); // Unary minus operator
        friend Graph& operator<(Graph g1, Graph g2); // Unary minus operator
        friend Graph& operator<=(Graph g1, Graph g2); // Unary minus operator
        friend Graph& operator==(Graph g1, Graph g2); // Unary minus operator
        friend Graph& operator!=(Graph g1, Graph g2); // Unary minus operator
    };
}

#endif // GRAPH_HPP
