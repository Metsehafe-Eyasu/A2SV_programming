class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>s;
        for(int rock: asteroids) {
            if (s.empty()) {
                s.push_back(rock);
                continue;
            }
            bool check = true;
            while (!s.empty()) {
                int last = s.back();
                s.pop_back();
                if (last > 0 && rock < 0) {
                    if (abs(last) > abs(rock)) {
                        s.push_back(last);
                        check = false;
                        break;
                    } else if (abs(last) == abs(rock)) {
                        check = false;
                        break;
                    }
                } else {
                    s.push_back(last);
                    break;
                }
            }
            if (check) s.push_back(rock);
        }
        return s;
    }
};