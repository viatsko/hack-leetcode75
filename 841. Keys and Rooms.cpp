class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> tovisit;
        set<int> visited;

        tovisit.push(0);

        while(tovisit.size() > 0) {
            int curr = tovisit.front();
            tovisit.pop();
            visited.insert(curr);
            for (auto & key : rooms[curr]) {
                if (!visited.count(key)) {
                    tovisit.push(key);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};
