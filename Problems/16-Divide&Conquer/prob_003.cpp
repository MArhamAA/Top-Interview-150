// BISMILLAH

// Problem link: https://leetcode.com/problems/construct-quad-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

// Definition for a QuadTree node.

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

struct cell {
    int x;
    int y;
    cell() {}
    cell(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

class Solution {
public:
    int N;
    vector<vector<int>> g;

    bool check(cell l, cell r) {
        bool zero, one; zero = one = 0;
        for (int i = l.x; i <= r.x; i++) {
            for (int j = l.y; j <= r.y; j++) {
                if (g[i][j]) one = 1;
                else zero = 1;
            }
        }
        return zero & one ? 0 : 1;
    }

    Node* dNc(cell top_left, cell bottom_right) {
        // printf("%d %d : %d %d\n", top_left.x, top_left.y, bottom_right.x, bottom_right.y);
        // check for the base case
        if (check(top_left, bottom_right)) {
            return new Node(g[top_left.x][top_left.y], 1);  // leaf_node
        }

        // divide into 4 sub grids
        cell m = cell((top_left.x+bottom_right.x)/2, (top_left.y+bottom_right.y)/2);

        Node* tl = dNc(top_left, m);
        Node* tr = dNc(cell(top_left.x, m.y+1), cell(m.x, bottom_right.y));
        Node* bl = dNc(cell(m.x+1, top_left.y), cell(bottom_right.x, m.y));
        Node* br = dNc(cell(m.x+1, m.y+1), bottom_right);
        return new Node(rand()%2, 0, tl, tr, bl, br);
    }

    Node* construct(vector<vector<int>>& grid) {
        N = (int) grid.size();
        g = grid;

        return dNc(cell(0,0), cell(N-1,N-1));
    }
};

signed main() {
    //
}

/*

brute force, divide & conquer

*/