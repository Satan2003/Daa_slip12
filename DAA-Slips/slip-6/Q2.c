// LCS using Dynamic Programming

#include <stdio.h>
#include <string.h>

int lcsLength(char *X, char *Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Build LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;  // Base Case
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;  // If characters match
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  // Max of excluding one char
        }
    }
    return dp[m][n]; // Length
}

int main() {
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int length = lcsLength(X, Y, m, n);
    printf("Length of Longest Common Subsequence: %d\n", length);

    return 0;
}
