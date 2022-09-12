#include <iostream>
#include <vector>
using namespace std;

// O(n) time | O(n) space
void helper(vector<vector<int>> &matrix, vector<int> &result, int rowStart, int rowEnd, int colStart, int colEnd) {
    if(rowStart > rowEnd || colStart > colEnd) {
        return;
    }
    for(int col = colStart; col <= colEnd; col++) {// O(n) time
        result.push_back(matrix[rowStart][col]);// O(1) time | O(n) space
    }
    for(int row = rowStart + 1; row <= rowEnd; row++) {// O(n) time
        result.push_back(matrix[row][colEnd]);// O(1) time | O(n) space
    }
    for(int col = colEnd - 1; col >= colStart; col--) {// O(n) time
        if(rowStart == rowEnd) {// O(1) time
            return;
        }
        result.push_back(matrix[rowEnd][col]);// O(1) time | O(n) space
    }
    for(int row = rowEnd - 1; row > rowStart; row--) {// O(n) time
        if(colStart == colEnd) {// O(1) time
            return;
        }
        result.push_back(matrix[row][colStart]);// O(1) time | O(n) space
    }
    helper(matrix, result, rowStart + 1, rowEnd - 1, colStart + 1, colEnd - 1);// O(n) time | O(n) space
}

// O(n) time | O(n) space
vector<int> spiralTraverseRecursive(vector<vector<int>> &array) {
    if(array.empty()) {
        return {};
    }
    vector<int> result = {};// O(n) space
    helper(array, result, 0, array.size() - 1, 0, array[0].size() - 1);// O(n) time | O(n) space
    return result;
}

// O(n) time | O(1) space
vector<int> spiralTraverseIterative(vector<vector<int>> &array) {
    if(array.empty()) {// O(1) TIME
        return {};// O(1) space
    }
    vector<int> result = {};// O(n) space
    int rowStart = 0;// O(1) space
    int rowEnd = array.size() - 1;// O(1) space
    int colStart = 0;// O(1) space
    int colEnd = array[0].size() - 1;// O(1) space
    while((rowStart <= rowEnd) && (colStart <= colEnd)) {// O(n) time
        for(int col = colStart; col <= colEnd; col++) {// O(n) time
            result.push_back(array[rowStart][col]);// O(1) time | O(1) space
        }
        for(int row = rowStart + 1; row <= rowEnd; row++) {// O(n) time
            result.push_back(array[row][colEnd]);// O(1) time | O(1) space
        }
        for(int col = colEnd - 1; col >= colStart; col--) {// O(n) time
            if(rowStart == rowEnd) {// O(1) TIME
                break;
            }
            result.push_back(array[rowEnd][col]);// O(1) time | O(1) space
        }
        for(int row = rowEnd - 1; row >= rowStart + 1; row--) {// O(n) time
            if(colStart == colEnd) {// O(1) TIME
                break;
            }
            result.push_back(array[row][colStart]);// O(1) time | O(1) space
        }
        rowStart++;// O(1) time | O(1) space
        rowEnd--;// O(1) time | O(1) space
        colStart++;// O(1) time | O(1) space
        colEnd--;// O(1) time | O(1) space
    }
    return result;
}

int main() {
    vector<vector<int>> input = {
            {1, 2, 3, 4},
            {12, 13, 14, 5},
            {11, 16, 15, 6},
            {10, 9, 8, 7},
    };
    cout << "Input matrix: " << endl;
    for(const vector<int>& array : input) {
        for(int element : array) {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<int> recursiveResult = spiralTraverseRecursive(input);
    vector<int> iterativeResult = spiralTraverseIterative(input);
    cout << "Recursive Method Result: " << endl;
    for(int element : recursiveResult) {
        cout << element << " ";
    }
    cout << " " << endl;
    cout << " " << endl;
    cout << "Iterative Method Result: " << endl;
    for(int element : iterativeResult) {
        cout << element << " ";
    }
    cout << " " << endl;
    cout << " " << endl;
    return 0;
}
