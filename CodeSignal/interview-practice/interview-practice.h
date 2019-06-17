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

using namespace std;

namespace feedingTime {
    struct ColoringGraph;
    vector<vector<int>> makeAdjacencyArray(const vector<vector<string>>& classes);
    bool isViable(const ColoringGraph& g, const vector<vector<int>> &adjArr, int count);
    int feedingTime(vector<vector<string>> classes);
}

#endif /* interview_practice_h */
