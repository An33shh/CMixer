# Tic-Tac-Toe
This is a C++ implementation of a two-player Tic-Tac-Toe game with a text-based interface and an improved AI opponent.

**Features:**

- Play against a strategic AI opponent.
- Get a valid move prompt for user input.
- Check for wins, ties, and invalid moves.

**How to Play:**

1. Compile the code using a C++ compiler (e.g., g++).
2. Run the executable.
3. The game will display the board and prompt you for your move (row col).
4. Enter a valid empty position on the board (e.g., 1 2).
5. The AI will make its move after yours.
6. The game will continue until there is a winner or the board is full.

**Code Structure:**

- `board.cpp`: Contains functions for displaying the board, checking win conditions, and checking for a full board.
- `game.cpp`: Implements the main game loop, including player moves, AI moves, and win/tie checks.

**AI Improvements:**

- Prioritizes winning moves for the computer.
- Blocks the opponent's winning moves.
- Includes a center square preference (if no immediate win/block is possible).

**Future Enhancements:**

- Difficulty levels for the AI.
- Graphical user interface.
- Player symbol selection (X or O).
- Win/loss tracking.

**Compiling and Running:**

```bash
g++ -o tic_tac_toe board.cpp game.cpp  # Replace with your compiler
./tic_tac_toe


** Enjoy playing Tic-Tac-Toe!
