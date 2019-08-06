//
//  fillingBlocks.cpp
//  CodeSignal
//
//  Created by 차경준 on 06/08/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/yWF4MmhvtmzfKNWgt/
//  Difficulty : Hard
// Time Complex Prediction : O(n)
//  Note : DynamicProgramming
#include "interview-practice.h"

namespace fillingBlocks
{
    int fillingBlocks(int n) {
        int dp[n+1], mid[n+1], half[n+1];
        
        memset(dp, 0, sizeof(dp));
        memset(mid, 0, sizeof(mid));
        memset(half, 0, sizeof(half));
        
        dp[0]=1;
        
        for(int i=1; i<=n; i++)
        {
            /*
             * A
             * A
             * B
             * B
             */
            dp[i] += dp[i-1];
            
            /*
             * AA
             * BB
             * CC
             * DD
             */
            if(i-2 >= 0)
                dp[i] += dp[i-2];
            
            /*
             * AA           A
             * BB    OR     A
             * C            BB
             * C            CC
             */
            if(i-2 >= 0)
                dp[i] += 2 * half[i-1];
            
            /*
             * AA
             * B
             * B
             * CC
             */
            dp[i] += mid[i-1];
            
            /*
             * A
             * A
             * @
             * @
             */
            half[i] = dp[i-1];
            
            /*
             * AA
             * BB
             * @
             * @
             */
            if(i-2 >= 0)
                half[i] += half[i-1];
            
            /*
             * @
             * A
             * A
             * @
             */
            mid[i] = dp[i-1];
            
            /*
             * DD@
             *  AA
             *  BB
             * CC@
             */
            if(i-3 >= 0)
                mid[i] += mid[i-2];
        }
        
        return dp[n];
    }
}

