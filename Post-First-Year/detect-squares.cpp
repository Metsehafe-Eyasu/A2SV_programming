class DetectSquares {
public:
    map<int, map<int, int>>grid;
    DetectSquares() {}
    
    void add(vector<int> point) {
        grid[point[0]][point[1]] += 1;
    }
    
    int count(vector<int> point) {
        int square_count = 0;
        int x = point[0], y = point[1];
        for(auto& [val, cnt]: grid[x]) {
            if (val == y) continue;
            int diff = y-val;
            square_count += grid[x][val] * grid[x+diff][y] * grid[x+diff][val];
            square_count += grid[x][val] * grid[x-diff][y] * grid[x-diff][val];
        }
        return square_count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */