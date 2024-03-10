#include "functions.hpp"
#include <iostream>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

void LeftRotation() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<int> ans = rotateLeft(d, arr);
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
}

std::vector<int> rotateLeft(int d, std::vector<int> arr) {
    int n = arr.size();
    std::vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[((i - d) + n) % n] = arr[i];
    }
    return ans;
}

void VectorErase() {
    int n, x, st, end;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> x;
    x--;
    arr.erase(arr.begin() + x);
    std::cin >> st >> end;
    st--; end--;
    arr.erase(arr.begin() + st, arr.begin() + end);
    std::cout << arr.size() << std::endl;
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
}

void DequeSTL() {
    int t;
    std::cin >> t;
    while(t > 0) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> arr(n);
        for(int i = 0; i < n; i++) {
              std::cin >> arr[i];
        }
        printKMax(arr, n, k);
        t--;
    }
}

void printKMax(std::vector<int> arr, int n, int k) {
    int st = 0, end = k;
    std::deque<int> mx;
    for(int i = st; i < end; i++) {
        mx.push_back(arr[i]);
    }
    int maxx = *std::max_element(mx.begin(), mx.end()); 
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
            maxx = *std::max_element(mx.begin(), mx.end()); 
        }
    }
    std::cout << std::endl;
}

void EqualStacks() {
    int ans, size1, size2, size3;
    std::cin >> size1 >> size2 >> size3;
    std::vector<int> h1(size1), h2(size2), h3(size3);
    for(int i = 0; i < size1; i++) {
        std::cin >> h1[i];
    }
    for(int i = 0; i < size2; i++) {
        std::cin >> h2[i];
    }
    for(int i = 0; i < size3; i++) {
        std::cin >> h3[i];
    }
    ans = equalStacks(h1, h2, h3);
    std::cout << ans;
}

int find_height(std::vector<int> arr) {
    int ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        ans += arr[i];
    }
    return ans;
}

int find_max(int f, int s, int t) {
    if(f >= s && f >= t) return f;
    if(s >= f && s >= t) return s;
    else return t;
}

int equalStacks(std::vector<int> h1, std::vector<int> h2, std::vector<int> h3) {
    int ans = 0, cur_maxx = 0;
    reverse(h1.begin(), h1.end()); 
    reverse(h2.begin(), h2.end()); 
    reverse(h3.begin(), h3.end());
    int H1 = find_height(h1), H2 = find_height(h2), H3 = find_height(h3);
    while(H1 != H2 || H1 != H3){
        cur_maxx = find_max(H1, H2, H3);
        if(H1 == cur_maxx) { H1 -= h1[h1.size()-1]; h1.pop_back(); } 
        else if (H2 == cur_maxx) { H2 -= h2[h2.size()-1]; h2.pop_back(); } 
        else if (H3 == cur_maxx) { H3 -= h3[h3.size()-1]; h3.pop_back(); } 
    }
    ans = H1;
    return ans;
}

void BalancedBrackets() {
    std::string ans, s;
    int t;
    std::cin >> t;
    while(t > 0) {
        std::cin >> s;
        ans = isBalanced(s);
        std::cout << ans << std::endl;
        t--;
    }
}

std::string isBalanced(std::string s) {
    std::stack<char> st;
    std::string Y = "YES", N = "NO";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else {
            if(st.empty()) return N;
            if(s[i] == ')' && st.top() != '(' || s[i] == '}' && st.top() != '{' || s[i] == ']' && st.top() != '[') {
                return N;
            }
            st.pop();
        }
    }
    if(st.empty()) return Y;
    return N;
}

void ComponentsInAGraph() {
    int n, first, second;
    std::vector<int> ans;
    std::cin >> n;
    std::vector<std::vector<int>> gb(n, std::vector<int>(2));
    for(int i = 0; i < n; i++) {
        std::cin >> first >> second;
        gb[i][0] = first;
        gb[i][1] = second;
    }
    ans = componentsInGraph(gb);
    std::cout << ans[0] << " " << ans[1] << std::endl;
}

int find_len(int pos, std::vector<std::vector<int>>& edges, std::vector<int>& visited) {
    int length = 0;
    std::queue<int> q;
    visited[pos] = 1;
    q.push(pos);
    while(!q.empty()) {
        int next = q.front();
        length++;
        for(auto v : edges[next]) {
            if(visited[v] == 0){
                visited[v] = 1;
                q.push(v);
            }
        }
        q.pop();
    }
    return length;
}

std::vector<int> componentsInGraph(std::vector<std::vector<int>> gb) {
    std::vector<int> ans;
    std::vector<std::vector<int>> edges(2 * gb.size() + 1);
    std::vector<int> visited(2 * gb.size() + 1, 0);
    for (int i = 0; i < gb.size(); i++) {
        edges[gb[i][0]].push_back(gb[i][1]);
        edges[gb[i][1]].push_back(gb[i][0]);
    }
    int mn = 1000000, mx = 0;
    for (int i = 1; i < 2 * gb.size() + 1; i++) {
        if (visited[i] == 0){
            int length = find_len(i, edges, visited);
            if(length >= 2) { 
                mn = std::min(mn, length); 
                mx = std::max(mx, length);
            }
        }
    }
    ans.push_back(mn); 
    ans.push_back(mx);
    return ans;
}