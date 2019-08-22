//
//  interview-practice.h
//  CodeSignal
//
//  Created by 차경준 on 03/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//

#ifndef interview_practice_h
#define interview_practice_h

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <numeric>

using namespace std;

template<typename T>
struct Tree {
   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
   T value;
   Tree *left;
   Tree *right;
};
namespace feedingTime {
    struct ColoringGraph;
    vector<vector<int>> makeAdjacencyArray(const vector<vector<string>>& classes);
    bool isViable(const ColoringGraph& g, const vector<vector<int>> &adjArr, int count);
    int feedingTime(vector<vector<string>> classes);
}

#endif /* interview_practice_h */
