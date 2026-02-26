 #include <iostream>

#include <vector>

#include <queue>

#include <unordered_map>

using namespace std;

struct Node {

    char state;

    int cost;

    int heuristic;

    bool operator>(const Node& other) const {

        return heuristic > other.heuristic;

    }

};

struct AStarNode {

    char state;

    int g; // path cost so far

    int f; // f = g + h

    bool operator>(const AStarNode& other) const {

        return f > other.f;

    }

};

unordered_map<char, vector<pair<char, int>>> adj = {

    {'S', {{'A', 6}, {'D', 3}}},

    {'A', {{'B', 5}}},

    {'B', {{'C', 4}}},

    {'D', {{'E', 2}}},

    {'E', {{'F', 4}}},

    {'F', {{'G', 3}}}

};

unordered_map<char, int> heuristic = {

    {'S', 12}, {'A', 8}, {'B', 7}, {'C', 5},

    {'D', 9}, {'E', 4}, {'F', 2}, {'G', 0}

};

void greedyBestFirst(char start, char goal) {

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    unordered_map<char, bool> visited;

    pq.push({start, 0, heuristic[start]});

    cout << "Greedy Best-First Path: ";

    while (!pq.empty()) {

        Node current = pq.top();

        pq.pop();

        if (visited[current.state]) continue;

        visited[current.state] = true;

        cout << current.state << " ";

        if (current.state == goal) break;

        for (auto& neighbor : adj[current.state]) {

            if (!visited[neighbor.first]) {

                pq.push({neighbor.first, 0, heuristic[neighbor.first]});

            }

        }

    }

    cout << endl;

}

void aStarSearch(char start, char goal) {

    priority_queue<AStarNode, vector<AStarNode>, greater<AStarNode>> pq;

    unordered_map<char, bool> visited;

    pq.push({start, 0, heuristic[start]});

    cout << "A* Path: ";

    while (!pq.empty()) {

        AStarNode current = pq.top();

        pq.pop();

        if (visited[current.state]) continue;

        visited[current.state] = true;

        cout << current.state << " ";

        if (current.state == goal) break;

        for (auto& neighbor : adj[current.state]) {

            if (!visited[neighbor.first]) {

                int gNew = current.g + neighbor.second;

                int fNew = gNew + heuristic[neighbor.first];

                pq.push({neighbor.first, gNew, fNew});

            }

        }

    }

    cout << endl;

}

int main() {

    greedyBestFirst('S', 'G');

    aStarSearch('S', 'G');
    

    return 0;
