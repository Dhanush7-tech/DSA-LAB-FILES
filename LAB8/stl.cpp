#include <cstdio>
#include <vector>
#include <numeric> // For accumulate
using namespace std;

class TowerGame {
private:
    int n; // Number of towers
    vector<int> towers; // Stores the number of blocks in each tower

public:
    // Constructor to initialize n and resize vector
    TowerGame(int size) {
        n = size;
        towers.resize(n);
    }

    // Function to read input
    void readInput() {
        for (int i = 0; i < n; i++) {
            scanf("%d", &towers[i]);
        }
    }

    // Function to compute the maximum blocks in tower 1
    void solve() {
        long long totalSum = accumulate(towers.begin(), towers.end(), 0LL);
        long long maxBlocks = (totalSum > towers[0]) ? totalSum : towers[0];
        printf("%lld\n", maxBlocks);
    }
};

// Main function
int main() {
    int t, n;
    scanf("%d", &t); // Read number of test cases
    
    while (t--) {
        scanf("%d", &n); // Read number of towers
        TowerGame game(n);
        game.readInput();
        game.solve();
    }

    return 0;
}
