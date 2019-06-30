//
//  containsDuplicates.cpp
//  CodeSignal
//
//  Created by 차경준 on 30/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/CfknJzPmdbstXhsoJ
//  Difficulty : Easy
//  Note : Map

#include "interview-practice.h"

namespace commonTechniquesBasic{
    bool containsDuplicates(std::vector<int> a)
    {
        map<int, bool> m;
        
        for(int i=0; i<a.size(); i++)
        {
            if(m.find(a.at(i)) != m.end())
                return true;
            else
                m[a.at(i)] = true;
        }
        
        return false;
    }
}
