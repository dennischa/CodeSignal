//
//  flightPlan.cpp
//  CodeSignal
//
//  Created by 차경준 on 17/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/s7E6FdhGKCdaCMNoL/solutions
//  Difficulty : Hard
//  Note : Graph, BFS

#include "interview-practice.h"

using namespace std;

namespace flightPlan {
    struct Time
    {
        Time()
        {
            hour = INT_MAX;
            minute = INT_MAX;
            str = "-1";
        }
        
        Time(string timeString)
        {
            string h = timeString.substr(0, 2);
            string m = timeString.substr(3, 2);
            hour = atoi(h.c_str());
            minute = atoi(m.c_str());
            str = timeString;
        }
        
        int hour;
        int minute;
        string str;
        
        bool operator<(const Time& t) const
        {
            return hour == t.hour ? minute <= t.minute : hour <= t.hour;
        }
    };
    
    struct Schedule
    {
        Schedule(vector<string> schedule):depart(schedule[2]), arrive(schedule[3])
        {
            starting = schedule[0];
            destination = schedule[1];
        }
        
        bool canTransfer(Schedule s)
        {
            Time tmp = arrive;
            tmp.hour++;
            return tmp < s.depart;
        }
        
        string starting;
        string destination;
        Time depart;
        Time arrive;
    };
    
    std::string flightPlan(std::vector<std::vector<std::string>> times, std::string source, std::string dest)
    {
        map<string, vector<Schedule>> timetable;
        map<string, bool> visited;
        queue<Schedule> q;
        
        Time answer;
        
        for(int i=0; i<times.size(); i++)
        {
            vector<string>& line = times.at(i);
            Schedule schedule(line);
            
            if(timetable.find(schedule.starting) == timetable.end())
            {
                timetable[schedule.starting] = vector<Schedule>();
            }
            
            timetable[schedule.starting].push_back(schedule);
        }
        
        for(int i=0; i<timetable[source].size(); i++)
        {
            q.push(timetable[source].at(i));
        }
        
        visited[source] = true;
        
        while(!q.empty())
        {
            Schedule cur = q.front(); q.pop();
            
            if(cur.destination == dest)
            {
                answer = min(answer, cur.arrive);
                continue;
            }
            
            visited[cur.destination] = true;
            vector<Schedule>& dests = timetable[cur.destination];
            
            for(int i=0; i<dests.size(); i++)
            {
                Schedule& dest = dests.at(i);
                
                if(visited.find(dest.destination) == visited.end() &&
                   cur.canTransfer(dest))
                {
                    q.push(dest);
                }
            }
        }
        
        return answer.str;
    }

}
