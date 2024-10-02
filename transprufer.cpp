// A function to get the prufer code of a tree
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree_to_prufer_code(vector<vector<int>> tree) {
  // Get the number of vertices in the tree
  int n = tree.size();
  // Initialize an empty vector for the prufer code
  vector<int> prufer_code;
  // Initialize a vector to store the degrees of each vertex
  vector<int> degrees(n, 0);
  // Loop through the tree and update the degrees
  for (int u = 0; u < n; u++) {
    for (int v : tree[u]) {
      degrees[u]++;
      degrees[v]++;
    }
  }
  // Initialize a queue to store the leaves of lowest label
  queue<int> queue;
  // Loop through the degrees and add the leaves to the queue
  for (int u = 0; u < n; u++) {
    if (degrees[u] == 1) {
      queue.push(u);
    }
  }
  // Loop until there are only two nodes left
  while (!queue.empty() && prufer_code.size() < n - 2) {
    // Pop the leaf of lowest label from the queue
    int x = queue.front();
    queue.pop();
    // Find the vertex connecting it to the rest of tree
    int y = -1;
    for (int v : tree[x]) {
      if (degrees[v] > 0) {
        y = v;
        break;
      }
    }
    // Remove x from the tree and add y to the prufer code
    prufer_code.push_back(y);
    degrees[x]--;
    degrees[y]--;
    // If y becomes a leaf, add it to the queue
    if (degrees[y] == 1) {
      queue.push(y);
    }
  }
  // Return the prufer code
  return prufer_code;
}


