# Password Generator (C++)

A simple command-line password generator written in C++. This tool allows users to customize their passwords by choosing the length and the types of characters to include (uppercase, lowercase, numbers, and special characters).

---

## 🚀 Features

- **Custom Password Length:** Choose any password length you need.
- **Character Type Selection:**  
  - Include or exclude uppercase letters  
  - Include or exclude lowercase letters  
  - Include or exclude numbers  
  - Include or exclude special characters
- **Random Generation:** Each password is randomly generated based on your selections.
- **Input Validation:** Ensures all user inputs are valid and prompts again if not.

---

## 🛠 Technologies Used

- **C++** (Standard Library)
- **No external dependencies**

---

## 📝 Usage

1. **Compile the program:**  
   ```bash
   g++ -o password_generator main.cpp
   ```

2. **Run the program:**  
   ```bash
   ./password_generator
   ```

3. **Follow the prompts:**  
   - Enter the desired password length.
   - Indicate (with "yes" or "no") whether to include each character type.

4. **Get your password:**  
   The program will display your randomly generated password based on your preferences.

---

## ⚠️ Notes

- At least one character type (uppercase, lowercase, number, or special character) must be selected.
- The random number generator is seeded with the current time for variability, but for cryptographically secure passwords, consider using a more secure RNG.
- This project is intended for educational purposes or simple use cases.
