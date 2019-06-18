//
//  currencyArbitrage.cpp
//  CodeSignal
//
//  Created by 차경준 on 18/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/SAmkgZQwDMtwwtdgn
//  Difficulty : Hard
//  Note : Graph, Bellman-Ford algorithm

#include <float.h>
#include "interview-practice.h"

bool currencyArbitrage(std::vector<std::vector<double>> exchange)
{
    auto size = exchange.size();
    
    for(int c=0; c<size; c++)
    {
        vector<double> currency(size, -(DBL_MAX));
        currency[c] = 1;
        
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                if(currency[i] != -(DBL_MAX))
                    currency[j] = max(currency[j], currency[i] * exchange[i][j]);
            }
        }
        
        for(int i=0; i<size; i++)
        {
            if(currency[i] * exchange[i][c] > 1)
                return true;
        }
    }
    
    return false;
}
