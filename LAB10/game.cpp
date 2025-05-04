#include <stdio.h>
#include <set> // Used for tracking unique elements

int main() {
    int t; // Number of test cases
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n); // Read the size of the sequence

        int arr[n]; // Array to store sequence
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]); // Read sequence elements
        }

        std::set<int> seen; // Set to store unique numbers
        int unique_count = 0; // Counts how many unique numbers we can keep

        // Traverse from the end to find the longest suffix with unique elements
        for (int i = n - 1; i >= 0; i--) {
            if (seen.find(arr[i]) != seen.end()) { 
                // If number is already seen, we stop
                break;
            }
            seen.insert(arr[i]); // Add new unique number to the set
            unique_count++; // Increase count of unique elements
        }

        // The answer is the number of elements removed from the start
        printf("%d\n", n - unique_count);
    }

    return 0;
}
