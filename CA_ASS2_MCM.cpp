#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int findMinMultiplications(const vector<int>& dimensions) {
    int numMatrices = dimensions.size() - 1;
    vector<vector<int>> dp(numMatrices, vector<int>(numMatrices, 0));

    for (int chainLength = 2; chainLength <= numMatrices; ++chainLength) {
        for (int start = 0; start < numMatrices - chainLength + 1; ++start) {
            int end = start + chainLength - 1;
            dp[start][end] = numeric_limits<int>::max();
            for (int split = start; split < end; ++split) {
                int cost = dp[start][split] + dp[split + 1][end] + dimensions[start] * dimensions[split + 1] * dimensions[end + 1];
                dp[start][end] = min(dp[start][end], cost);
            }
        }
    }

    return dp[0][numMatrices - 1];
}

int main() {
    int matrixCount;
    cout << "How many matrices are there? ";
    cin >> matrixCount;

    vector<int> dims(matrixCount + 1);
    cout << "Provide the dimensions in sequence.\n";
    cout << "For Matrix A1 with dimensions d1 x d2, enter d1 followed by d2.\n";
    cout << "For Matrix A2 with dimensions d2 x d3, enter d3, and so forth.\n\n";

    for (int idx = 0; idx <= matrixCount; ++idx) {
        cout << "Dimension " << idx + 1 << ": ";
        cin >> dims[idx];
    }

    int minOperations = findMinMultiplications(dims);
    cout << "\nMinimum number of multiplications required: " << minOperations << endl;

    return 0;
}