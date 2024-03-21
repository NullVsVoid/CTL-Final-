//
// Copyright Caiden Sanders - All Rights Reserved
//
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.
//
// Written by Caiden Sanders <work.caidensanders@gmail.com>, March 19, 2024.
//

#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

// Function prototype for breadth first search
bool breadth_first_search(int start,
                          const std::vector<std::vector<int>>& graph);

// Helper function prototype to check for a value in a node
bool is_value(int node, const std::vector<std::vector<int>>& graph);

#endif  // BREADTH_FIRST_SEARCH_HPP