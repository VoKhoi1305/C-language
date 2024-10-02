// Define a struct to represent a vertex
struct Vertex {
    int x, y;
};

// Include the necessary libraries
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    // Read the number of vertices
    int n;
    cin >> n;

    // Initialize an empty vector to store the edges
    vector<Vertex> edges;

    // Initialize an unordered map to store the degrees of each vertex
    unordered_map<int, int> degrees;

    // Loop through the vertices and read the edges
    for (int i = 0; i < n; i++) {
        // Read the x and y coordinates of the edge
        int x, y;
        cin >> x >> y;

        // Create a Vertex object and push it to the edges vector
        Vertex edge = {x, y};
        edges.push_back(edge);

        // Increment the degrees of both vertices by 1
        degrees[x]++;
        degrees[y]++;
    }

    // Initialize a variable to store the current vertex
    int i = 1;

    // Initialize a vector to store the output
    vector<int> output;

    // Initialize an unordered set to store the visited edges
    unordered_set<int> visited;

    // Loop until all vertices are visited
    while (i <= n) {
        // Loop through the edges
        for (int k = 0; k < n; k++) {
            // Check if the edge has not been visited and one of its vertices has degree 1
            if (visited.find(k) == visited.end() && ((edges[k].x == i && degrees[edges[k].x] == 1) || (edges[k].y == i && degrees[edges[k].y] == 1))) {
                // Push the other vertex to the output vector
                if (edges[k].x == i) {
                    output.push_back(edges[k].y);
                }
                else {
                    output.push_back(edges[k].x);
                }

                // Decrement the degrees of both vertices by 1
                degrees[edges[k].x]--;
                degrees[edges[k].y]--;

                // Mark the edge as visited
                visited.insert(k);

                // Reset the current vertex to 0
                i = 0;

                // Break out of the inner loop
                break;
            }
        }

        // Increment the current vertex by 1
        i++;
    }

    // Print the output vector separated by spaces
    for (int v : output) {
        cout << v << " ";
    }
    cout << endl;
}
