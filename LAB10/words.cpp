#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t); // Read number of test cases

    while (t--) {
        int n;
        scanf("%d", &n); // Read number of words per player

        map<string, int> word_count;
        vector<vector<string>> words(3, vector<string>(n)); // Stores words for each player

        // Read words for each player and update word frequency map
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                char word[4]; // Words are always of length 3 + null terminator
                scanf("%s", word);
                words[i][j] = word;
                word_count[word]++;
            }
        }

        // Calculate scores for each player
        int scores[3] = {0, 0, 0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                int count = word_count[words[i][j]];
                if (count == 1) scores[i] += 3; // Unique word -> 3 points
                else if (count == 2) scores[i] += 1; // Shared by 2 -> 1 point
                // If shared by all 3 -> 0 points (default case)
            }
        }

        // Print results
        printf("%d %d %d\n", scores[0], scores[1], scores[2]);
    }

    return 0;
}