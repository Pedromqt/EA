#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumTriangle(vector<vector<int>>& triangle, int rows) {
    for(int i = rows - 2; i >= 0; i--){
        for(int j = triangle[i].size() - 1; j >= 0; j--){
            triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}

int main() {
    int testCases;
    cin >> testCases;
    for(int cases = 0; cases < testCases; cases++) {
        int rows;
        cin >> rows;
        vector<vector<int>> triangle(rows, vector<int>(rows, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> triangle[i][j];
            }
        }
        cout << maxSumTriangle(triangle, rows) << endl;
    }
    return 0;
}