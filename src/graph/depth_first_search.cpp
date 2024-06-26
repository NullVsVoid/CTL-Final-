//
// Copyright Caiden Sanders - All Rights Reserved
//
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.
//
// Written by Caiden Sanders <work.caidensanders@gmail.com>, March 19, 2024.
//

#include "../../include/graph/depth_first_search.hpp"

bool depth_first_search(int start, const std::vector<std::vector<int>>& graph) {
    // A stack is used to keep track of the nodes to be visited next.
    // DFS uses a LIFO (Last In, First Out) strategy for exploring nodes,
    // meaning the most recently discovered node will be explored next.
    std::stack<int> search_stack;

    // An unordered set to keep track of all the nodes that have been visited.
    // This is to prevent re-visiting and getting stuck in a loop.
    std::unordered_set<int> searched;

    // The search begins from the 'start' node, so we push it onto the stack.
    search_stack.push(start);

    // Continue the saerch as long as there are nodes left to explore,
    // i.e., the stack is not empty.
    while (!search_stack.empty()) {
        // Retrieve and remove the top element from the stack.
        // This is the next node to be explored.
        int node = search_stack.top();
        search_stack.pop();

        // Check if this node has been visitd before.
        // If it hasn't been visited ('searched' set does not contain 'node'),
        // then proceed with exploring it.
        if (searched.find(node) == searched.end()) {
            // For debugging purposes, print the node.
            std::cout << node << std::endl;

            // If the 'is_value' condition is satisfied for the node,
            // then we have found what we are searching for, and return true.
            if (is_value(node, graph)) {
                return true;
            } else {
                // If the node does not satisfy the 'is_value' condition,
                // then we add all of its neighbors to the stack for future
                // exploration. This is where the DFS explores depth by moving
                // to adjacent nodes.
                for (int neighbor : graph[node]) {
                    search_stack.push(neighbor);
                }

                // Mark the current node as visitd by adding it to the
                // 'searched' set. This ensures we do not revisit and re-explore
                // this node.
                searched.insert(node);
            }
        }
    }

    // If the function reaches this point, it means we have explored all
    // possible apthways without finding a node that satisfies the 'is_value'
    // condition. Therefore, return false.
    return false;
}

// Checks for condition of node being 42 (example).
bool is_value(int node, const std::vector<std::vector<int>>& graph) {
    return node == 42;
}