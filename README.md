# Rock Paper Scissors Game (C Language)

A simple, clean, and fully interactive **Rock–Paper–Scissors** game written in **C**.  
This program allows the user to play infinite rounds against the computer, with clear explanations for every win and loss.

# 🎮 Features

- Text-based interactive gameplay  
- Input validation (ensures only 1–3 are accepted)  
- Computer choice generated using `rand()`  
- Detailed explanation of every win or loss  
- Infinite gameplay loop  
- Modular code with separate functions for:
  - Menu display  
  - Choice printing  
  - Winner calculation  
  - Win/Loss explanation  
  - Round handling  

# 📂 Project Structure

```
Rock-Paper-Scissors/
│
├── rps.c        # Main C program source code
└── README.md    # Project documentation
```

# 🛠️ How It Works

The game uses simple numeric inputs:

| Choice     | Number |
|------------|--------|
| Rock       | 1      |
| Paper      | 2      |
| Scissors   | 3      |

Winner Logic:
- Rock beats Scissors  
- Paper beats Rock  
- Scissors beat Paper  

The program prints both choices and shows who won, along with a friendly explanation.

# ▶️ How to Run

### **1. Compile the program**
```bash
gcc rps.c -o rps
```

### **2. Run the executable**
```bash
./rps
```

The game will start instantly and continue running in an infinite loop.

# 📦 Requirements

- C Compiler (GCC, Clang, MinGW, etc.)
- Standard C Libraries (`stdio.h`, `stdlib.h`, `time.h`)

# 🧠 Code Highlights

- Uses `rand() % 3 + 1` to generate computer choices  
- Uses `srand(time(0));` to ensure randomness  
- Clean modular functions make the code easy to read and maintain  
- Friendly UI printed using ASCII formatting  

# 📝 Example Output

```
==============================
   Rock Paper Scissors Game
==============================
Choose one option:
  1 -> Rock
  2 -> Paper
  3 -> Scissors
Enter your choice (1-3): 1

You chose: Rock
Computer chose: Scissors

Result: YOU WIN! Great job!
Rock smashes Scissors.
```

# 📜 License

This project is licensed under the **MIT License** — you’re free to use and modify it.
