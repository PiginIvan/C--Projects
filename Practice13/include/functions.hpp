#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

class Solutions {
public:
    class RunningMedian {
    public:
        typedef std::priority_queue<unsigned int> type_H_low;
        typedef std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int> > type_H_high;
        size_t signum(int left, int right);
        void get_median( unsigned int x_i, double &m, type_H_low *l, type_H_high *r);
        std::vector<double> runningMedian(std::vector<int> a);
    };
    
    class BFSShortSeacrh {
    public:
        std::vector<int> bfs(int n, int m, std::vector<std::vector<int>> edges, int s);
    };

    class VectorErase {
    public:
        void eraseFromVector(std::vector<int> arr, int x, int st, int end);
    };

    class CppLowerBound {
    public:
        void findLowerBound(std::vector<int> arr, int t);
    };

    class DequeSTL {
    public:
        void printKMax(int arr[], int n, int k);
    };

    class NumberOfWordsFoundInSentences {
    public:
        int mostWordsFound(std::vector<std::string>& sentences); 
    };

    class CreateTargetArray {
    public:
        std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index);
    };

    class MaxIncreaseToKeepCitySkyline {
    public:
        int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid);
    };
    
};

#endif