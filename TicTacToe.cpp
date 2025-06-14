#include<bits/stdc++.h>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    string player1Name;
    string player2Name;
    char player1Symbol;
    char player2Symbol;

    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void initializeBoard() {
        char value = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = value++;
            }
        }
    }

    void displayBoard() const {
        cout << "\n\t\tTic Tac Toe\n\n";
        for (int i = 0; i < 3; i++) {
            cout << "\t\t ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2)  cout << " | ";
            }
            cout << "\n";
            if (i < 2)  cout << "\t\t-----------\n";
        }
        cout << "\n";
    }

    bool isValidMove(int position) const {
        if (position < 1 || position > 9) return false;
        
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        return (board[row][col] != player1Symbol && board[row][col] != player2Symbol);
    }

    void makeMove(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        board[row][col] = currentPlayer;
    }

    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                return true;
            }
        }

        // Check diagonals
        return (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
               (board[0][2] == board[1][1] && board[1][1] == board[2][0]);
    }

    bool isBoardFull() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != player1Symbol && board[i][j] != player2Symbol) {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == player1Symbol) ? player2Symbol : player1Symbol;
    }

    int getValidMove() const {
        int position;
        string currentPlayerName = (currentPlayer == player1Symbol) ? player1Name : player2Name;
        
        while (true) {
            cout << currentPlayerName << "'s turn (" << currentPlayer << "): Enter position (1-9): ";
            if (cin >> position && isValidMove(position)) {
                return position;
            }
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cout << "Invalid move! Please try again.\n";
        }
    }

public:
    TicTacToe() {
        cout << "Enter Player 1 name: ";
        getline(cin, player1Name);
        cout << "Enter a symbol to your move for 1st player: ";
        cin >> player1Symbol;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Player 2 name: ";
        getline(cin, player2Name);
        cout << "Enter a symbol to your move for 2nd player: ";
        cin >> player2Symbol;
        currentPlayer = player1Symbol;
    }

    void play() {
        char playAgain;
        do {
            gameLoop();
            cout << "\nPlay again? (y/n): ";
            cin >> playAgain;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (tolower(playAgain) == 'y');
    }

private:
    void gameLoop() {
        initializeBoard();
        bool gameWon = false;

        while (!gameWon && !isBoardFull()) {
            clearScreen();
            displayBoard();
            
            int position = getValidMove();
            makeMove(position);

            if (checkWin()) {
                clearScreen();
                displayBoard();
                string winner = (currentPlayer == player1Symbol) ? player1Name : player2Name;
                cout << "\nCongratulations! " << winner << " wins the game!\n";
                gameWon = true;
            } else if (isBoardFull()) {
                clearScreen();
                displayBoard();
                cout << "\nGame Draw!\n";
            } else {
                switchPlayer();
            }
        }
    }
};

int main() {
    cout << "\n=== Welcome to Tic Tac Toe ===\n\n";
    TicTacToe game;
    game.play();
    cout << "\nThanks for playing!\n";
    return 0;
}
