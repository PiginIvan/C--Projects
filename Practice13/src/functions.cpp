#include "functions.hpp"
#include <iostream>
#include <algorithm>

size_t Solutions::RunningMedian::signum(int left, int right) {
    if (left == right){
        return 0;
    }
    return (left < right)?-1:1;
}

void Solutions::RunningMedian::get_median( unsigned int x_i, double &m, type_H_low *l, type_H_high *r) {

    switch (signum( l->size(), r->size() )) {
    case 1: 
        if (x_i < m) {
            r->push(l->top());
            l->pop();
            l->push(x_i);
        } else {
            r->push(x_i);
        }
        break;

    case 0: 
        if (x_i < m){
            l->push(x_i);
        } else {
            r->push(x_i);
        }
        break;

    case -1: 
        if (x_i < m){
            l->push(x_i);
        } else {
            l->push(r->top());
            r->pop();
            r->push(x_i);
        }
        break;
    }

    if (l->size() == r->size()){
        m = (double)(l->top() + r->top()) / 2;
    } else if (l->size() > r->size()){
        m = l->top();
    } else {
        m = r->top();
    }

    return;
}

std::vector<double> Solutions::RunningMedian::runningMedian(std::vector<int> a) {
    std::vector<double> ans(a.size());
    double median = 0;
    long int sum = 0;
    type_H_low  H_low;
    type_H_high H_high;
    int i = 0;
    for (std::vector<int>::iterator x_i = a.begin(); x_i != a.end(); x_i++) {
        get_median(*x_i, median, &H_low, &H_high);
        ans[i] = median;
        i++;
    }
    return ans;
}

std::vector<int> Solutions::BFSShortSeacrh::bfs(int n, int m, std::vector<std::vector<int>> edges, int s) {
    std::queue<int> q;
    std::vector<int> dst(n,-1);
    dst[s - 1] = 0;
    q.push(s);    
    int curr;
    while(!q.empty()){
        curr = q.front(); q.pop();
        for(const std::vector<int> &v : edges){
            if(v[0] == curr && dst[v[1] - 1] == -1){
                dst[v[1] - 1] = dst[curr - 1] + 6;
                q.push(v[1]);
            } else if (v[1] == curr && dst[v[0] - 1] == -1){
                dst[v[0] - 1] = dst[curr - 1] + 6;
                q.push(v[0]);
            }
        }
    }
    dst.erase(dst.begin() + s-1);
    return dst;
}

void Solutions::VectorErase::eraseFromVector(std::vector<int> arr, int x, int st, int end) {
    x--;
    arr.erase(arr.begin()+x);
    st--; end--;
    arr.erase(arr.begin()+st, arr.begin()+end);
    std::cout << arr.size() << std::endl;
    for(int i = 0; i < arr.size(); i++) std::cout << arr[i] << " ";
}

void Solutions::CppLowerBound::findLowerBound(std::vector<int> arr, int t) {
    for(int i = 0; i < t; i++) {
        int num;
        std::cin >> num;
        auto it = lower_bound(arr.begin(), arr.end(), num);
        if(arr[it - arr.begin()] == num) {
            std::cout << "Yes " << it - arr.begin() + 1;
        }
        else {
            std::cout << "No " << it - arr.begin() + 1;
        }
        std::cout << std::endl;
    }
}

void Solutions::DequeSTL::printKMax(int arr[], int n, int k) {
    int st = 0, end = k;
    std::deque<int> mx;
    for(int i = st; i < end; i++) mx.push_back(arr[i]);
    int maxx = *std::max_element(mx.begin(),mx.end()); 
    for (int i = k; i < n + 1; i++){
        std::cout << maxx << " ";
        if(mx[0] != maxx) {
            mx.pop_front();
            mx.push_back(arr[i]);
            if(arr[i] > maxx) maxx = arr[i];
        }
        else {
            mx.pop_front();
            mx.push_back(arr[i]);
            maxx = *std::max_element(mx.begin(),mx.end()); 
        }
    }
    std::cout << std::endl;
}

int Solutions::NumberOfWordsFoundInSentences::mostWordsFound(std::vector<std::string>& sentences) {
    int ans = 0, cur_ans = 0;
    for(int i = 0; i < sentences.size(); i++) {
        cur_ans = std::count(sentences[i].begin(), sentences[i].end(), ' ');
        ans = std::max(ans, cur_ans);
    }
    return ans + 1;
}

std::vector<int> Solutions::CreateTargetArray::createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
    std::vector<int> ans;
    for(int i = 0; i < nums.size(); i++) {
        ans.insert(ans.begin() + index[i], nums[i]);
    }
    return ans;
}

int Solutions::MaxIncreaseToKeepCitySkyline::maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
    int n = grid.size(), ans = 0;
    std::vector<std::pair<int,int>> v(n,{-1,-1});
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            v[i].first = std::max(v[i].first,grid[i][j]);
            v[j].second = std::max(v[j].second,grid[i][j]);
        }
    }
    for(int i=0,k=0; i<n; ++i,++k){
        for(int j=0; j<n; ++j)
            ans += std::min(v[i].first,v[j].second) - grid[i][j];
    }
    return ans;
}