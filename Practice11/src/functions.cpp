#include "functions.hpp"

std::vector<std::vector<std::string>> Solutions::TableOfFoodOrders::displayTable(std::vector<std::vector<std::string>>& orders) {
    std::vector<std::vector<std::string>> table; 
    std::vector<std::string> title; 
    title.push_back("Table");
    std::map<std::pair<std::string, std::string>, int> m;
    std::set<int> tables; 
    std::set<std::string> dishes;
    for(auto& x : orders){
        tables.insert(stoi(x[1])); dishes.insert(x[2]);
        m[std::make_pair(x[1], x[2])]++;
    }
    for(auto& x : dishes) title.push_back(x);
    table.push_back(title);
    std::vector<std::string> cur;
    for(auto& x : tables){
        cur.push_back(std::to_string(x));
        for(auto& y : dishes) cur.push_back(std::to_string(m[std::make_pair(std::to_string(x), y)]));
        table.push_back(cur);
        cur.clear();
    }
    return table;
}

void Solutions::UndergroundSystem::checkIn(int id, std::string stationName, int t) {
    m[id] = std::make_pair(stationName, t);
}

void Solutions::UndergroundSystem::checkOut(int id, std::string stationName, int t) {
    std::pair<std::string, std::string> cur = std::make_pair((m[id].first), stationName);
    if(!times.count(cur)) times[cur] = std::make_pair(t - m[id].second, 1);
    else times[cur] = std::make_pair((times[cur].first + t - m[id].second), times[cur].second + 1);
}

double Solutions::UndergroundSystem::getAverageTime(std::string startStation, std::string endStation) {
    return times[std::make_pair(startStation, endStation)].first / times[std::make_pair(startStation, endStation)].second; 
}

int Solutions::EmployeeImportance::getImportance(std::vector<Employee*> employees, int id) {
    int ans = 0;
    std::map<int, std::vector<int>> m; 
    std::map<int, int> value;
    for(auto& x : employees) { m[x->id] = x->subordinates; value[x->id] = x->importance; }
    for(auto& x : m){
        if(x.first == id){
            ans += value[x.first];
            walk(x.second, ans, m, value);
            break;
        }
    }
    return ans;
}
void Solutions::EmployeeImportance::walk(std::vector<int> vec, int& ans, std::map<int, std::vector<int>> m, std::map<int, int> value){
    if(!vec.size()) return;
    for(auto& x : vec){
        ans += value[x];
        walk(m[x], ans, m, value);
    }
}