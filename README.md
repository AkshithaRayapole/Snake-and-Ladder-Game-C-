# Snakes and Ladders Game

This is a simple command-line implementation of the classic **Snakes and Ladders** game in C.

## Features
- Two-player gameplay
- Random dice rolls
- Snakes that bring players down
- Ladders that help players move up
- Turn-based gameplay until a player wins

## How to Play
1. Clone this repository:
   ```sh
   git clone https://github.com/your-username/snakes-and-ladders.git
   cd snakes-and-ladders
   ```
2. Compile the code using a C compiler (GCC recommended):
   ```sh
   gcc -o snakes_ladders snakes_ladders.c
   ```
3. Run the executable:
   ```sh
   ./snakes_ladders
   ```
4. Follow the on-screen instructions to roll the dice and move your player.
5. The first player to reach position 100 wins the game!

## Game Rules
- Players take turns rolling a six-sided die.
- If a player lands at the bottom of a ladder, they climb up.
- If a player lands on a snake's head, they slide down.
- The first player to reach position 100 wins.

## File Structure
```
/snakes-and-ladders
│── snakes_ladders.c   # Source code for the game
│── README.md          # Documentation
```

## Example Gameplay
```
Welcome to Snakes and Ladders!
Player 1's turn. Press enter to roll the dice...
Player 1 rolled a 5
Player 1 is now at position 5
Player 2's turn. Press enter to roll the dice...
Player 2 rolled a 3
Player 2 is now at position 3
...
Player 1 wins!
Game Over! Thank you for playing.
```

## Contributing
Feel free to fork this repository and contribute by adding new features or improving the existing code.

## License
This project is open-source and available under the **MIT License**.

