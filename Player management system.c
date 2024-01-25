#include <stdio.h>
#include<string.h>
//Define a structure for a player record
struct Player{
    int jerseyNo;
    char name[50];
    int runs;
    int wickets;
    int matches;
};
void displayMenu();
void addplayer();
void displayAllPlayers();
void searchByJerseyNo(int);
void searchByName(char*);
void updatePlayer(int);
void deletePlayer(int);
void top3PlayersByRuns();
void top3PlayersByWickets();


// Global array to store player records
struct Player players[100];
int numPlayers = 0;
// Function to display the main menu
void displayMenu() {
    printf("\nPlayer Management System Menu\n");
    printf("1. Add Player\n");
    printf("2. Display All Players\n");
    printf("3. Search Player by Jersey No\n");
    printf("4. Search Player by Name\n");
    printf("5. Update Player Information\n");
    printf("6. Delete Player by Jersey No\n");
    printf("7. Top 3 Players by Runs\n");
    printf("8. Top 3 Players by Wickets\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new player to the records
void addPlayer() {
	
    struct Player player;
    printf("Enter Jersey No: ");
    scanf("%d", &player.jerseyNo);
    printf("Enter Name: ");
    scanf("%s", &player.name);
    printf("Enter Runs: ");
    scanf("%d", &player.runs);
    printf("Enter Wickets: ");
    scanf("%d", &player.wickets);
    printf("Enter Matches: ");
    scanf("%d", &player.matches);

    players[numPlayers] = player;
    numPlayers++;
    printf("Player added successfully.\n");
}

// Function to display all player records
void displayAllPlayers() {
    printf("\nPlayer Records:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Jersey No: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",
               players[i].jerseyNo, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
    }
}

// Function to search for a player by jersey number
void searchByJerseyNo(int jerseyNo) {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].jerseyNo == jerseyNo) {
            printf("Player found: Jersey No: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",
                   players[i].jerseyNo, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
            return;
        }
    }
    printf("Player not found with Jersey No: %d\n", jerseyNo);
}

// Function to search for a player by name
void searchByName(char *name) {
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Player found: Jersey No: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",
                   players[i].jerseyNo, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
            return;
        }
    }
    printf("Player not found with name: %s\n", name);
}

// Function to update player information
void updatePlayer(int jerseyNo) {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].jerseyNo == jerseyNo) {
            printf("Enter new Runs: ");
            scanf("%d", &players[i].runs);
            printf("Enter new Wickets: ");
            scanf("%d", &players[i].wickets);
            printf("Enter new Matches: ");
            scanf("%d", &players[i].matches);
            printf("Player information updated successfully.\n");
            return;
        }
    }
    printf("Player not found with Jersey No: %d\n", jerseyNo);
}

// Function to delete a player by jersey number
void deletePlayer(int jerseyNo) {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].jerseyNo == jerseyNo) {
            for(int j = i; j < numPlayers - 1; j++){
                players[j] = players[j + 1];
            }
            numPlayers--;
            printf("Player with Jersey No %d deleted successfully.\n", jerseyNo);
            return;
        }
    }
    printf("Player not found with Jersey No: %d\n", jerseyNo);
}

// Function to find the top 3 players based on runs
void top3PlayersByRuns() {
    // Sort players by runs in descending order
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = i + 1; j < numPlayers; j++) {
            if (players[i].runs < players[j].runs) {
                struct Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    printf("\nTop 3 Players by Runs:\n");
    for (int i = 0; i < numPlayers && i < 3; i++) {
        printf("Jersey No: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",
               players[i].jerseyNo, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
    }
}

// Function to find the top 3 players based on wickets
void top3PlayersByWickets() {
    // Sort players by wickets in descending order
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = i + 1; j < numPlayers; j++) {
            if (players[i].wickets < players[j].wickets) {
                struct Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    printf("\nTop 3 Players by Wickets:\n");
    for (int i = 0; i < numPlayers && i < 3; i++) {
        printf("Jersey No: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",
               players[i].jerseyNo, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
    }
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addplayer();
                break;
            case 2:
                displayAllPlayers();
                break;
            case 3:;
                int jerseyNo;
                printf("Enter Jersey No to search: ");
                scanf("%d", &jerseyNo);
                searchByJerseyNo(jerseyNo);
                break;
            case 4:;
                char name[50];
                printf("Enter Name to search: ");
                scanf("%s", name);
                searchByName(name);
                break;
            case 5:;
                int updateJerseyNo;
                printf("Enter Jersey No to update: ");
                scanf("%d", &updateJerseyNo);
                updatePlayer(updateJerseyNo);
                break;
            case 6:;
                int deleteJerseyNo;
                printf("Enter Jersey No to delete: ");
                scanf("%d", &deleteJerseyNo);
                deletePlayer(deleteJerseyNo);
                break;
            case 7:
                top3PlayersByRuns();
                break;
            case 8:
                top3PlayersByWickets();
                break;
            case 9:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}