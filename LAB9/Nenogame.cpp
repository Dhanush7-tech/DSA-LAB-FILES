#include <stdio.h>
#include <vector>
#include <algorithm>

class Game {
private:
    std::vector<int> elimination_positions;

public:
    // Function to read the elimination sequence
    void readEliminationSequence(int k) {
        elimination_positions.resize(k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &elimination_positions[i]);
        }
        std::sort(elimination_positions.begin(), elimination_positions.end()); // Sort positions
    }

    // Function to simulate the game using a while loop
    int simulate(int n) {
        int remaining_players = n;
        

        // Process eliminations while valid
        for(int pos:elimination_positions){
        while (pos<=remaining_players) {
            remaining_players--; // Remove a player
             // Move to the next elimination
        }
    }
        
        return remaining_players;
    }
};

int main() {
    int t;
    scanf("%d", &t); // Read the number of test cases

    while (t--) {
        int k, q;
        scanf("%d %d", &k, &q);

        Game game;
        game.readEliminationSequence(k);

        // Read q queries and compute results
        while (q--) {
            int n;
            scanf("%d", &n);
            printf("%d ", game.simulate(n));
        }
        printf("\n"); // New line after each test case
    }

    return 0;
}
