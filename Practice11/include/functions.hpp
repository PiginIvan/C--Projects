#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
#include <string>
#include <map>
#include <set>

class Solutions {
public:
    class TableOfFoodOrders {
    public:
        std::vector<std::vector<std::string>> displayTable(std::vector<std::vector<std::string>>& orders);
    };
    
    class UndergroundSystem {
    public:
        std::map<int, std::pair<std::string, int>> m;
        std::map<std::pair<std::string, std::string>, std::pair<double, int>> times;
        
        UndergroundSystem() {}    
        void checkIn(int id, std::string stationName, int t);
        void checkOut(int id, std::string stationName, int t);
        double getAverageTime(std::string startStation, std::string endStation);
    };
    class EmployeeImportance {
    public:
        class Employee {
        public:
            int id;
            int importance;
            std::vector<int> subordinates;
        };
        int getImportance(std::vector<Employee*> employees, int id);
        void walk(std::vector<int> vec, int& ans, std::map<int, std::vector<int>> m, std::map<int, int> value);
    };
    
};

#endif