//
//  mostFrequentSum.cpp
//  CodeSignal
//
//  Created by 차경준 on 06/08/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/9i2KvkNRzncy7Bzia/
//  Difficulty : Hard
// Time Complex Prediction : O(n) // n : number of node
//  Note : Graph
#include "interview-practice.h"

int travel(Tree<int> *t, map<int, int> &sums, int &count)
{
    if(t == nullptr)
        return 0;
    
    Tree<int> *left = t->left;
    Tree<int> *right = t->right;
    int value = t->value;
    
    if(left != nullptr || right != nullptr)
    {
        value += travel(left, sums, count) + travel(right, sums, count);
    }
    
    if(sums.find(value) != sums.end())
        sums[value]++;
    else
        sums[value] = 1;
    
    count = max(sums[value], count);
    return value;
}

std::vector<int> mostFrequentSum(Tree<int> * t)
{
    int count = 0;
    map<int, int> sums;
    
    travel(t, sums, count);
    
    vector<int> answer;
    
    map<int, int>::iterator it = sums.begin();
    for(;it != sums.end(); it++)
    {
        if(it->second == count)
            answer.push_back(it->first);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

