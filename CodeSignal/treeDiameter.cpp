//
//  treeDiameter.cpp
//  CodeSignal
//
//  Created by 차경준 on 28/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/Sby2j4SHqDncwyQjh
//  Difficulty : Easy
//  Time Complex Prediction(vertex:v, link:l) : O(v2) for adjacent Array, O(l) to update depths
//  Note : Graph, Divide and conquer

#include "interview-practice.h"


namespace treeDiameter {
    //In ordere to get tree diameter, need two largest depths of one node
    //Adding two depths makes diameter
    struct Depths
    {
        int depth1 = 0; // the next largest
        int depth2 = 0; // the largest
        
        void updateDepths(int value)
        {
            if(depth1 < value)
            {
                if(depth2 < value)
                {
                    depth1 = depth2;
                    depth2 = value;
                }
                else
                    depth1 = value;
            }
        }
    };
    
    //Top-down divide and conquer
    //divide graph into subgraph until a edge node
    //update node's depths based on connected node (combine)
    void dc(int v, const int& n, vector<vector<int>>& adjArr, vector<Depths>& depths)
    {
        for(int i=0; i<n; i++)
        {
            if(adjArr[v][i])
            {
                adjArr[v][i] = 0;
                adjArr[i][v] = 0;
                
                dc(i, n, adjArr, depths);
                
                depths[v].updateDepths(depths[i].depth2 + 1);
            }
        }
    }
    
    int treeDiameter(int n, std::vector<std::vector<int>> tree)
    {
        vector<vector<int>> adjArr(n, vector<int>(n, 0));
        
        for(int i=0; i<tree.size(); i++)
        {
            int f = tree.at(i).at(0);
            int t = tree.at(i).at(1);
            
            adjArr[f][t] = 1;
            adjArr[t][f] = 1;
        }
        
        vector<Depths> depths(n);
        
        dc(0, n, adjArr, depths);
        
        int m = 0;
        
        for(int i=0; i<n; i++)
            m = max(m, depths[i].depth1 + depths[i].depth2);
        
        return m;
    }
}


