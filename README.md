<p align="center">
  <img src="logo.png" alt="Syntax Error team logo" width="220">
</p>

# Password Strength Analyzer

A beginner-level password checker built in two versions: a **C console program** and a **web page**.
It checks a password's length and character types, gives a score, shows a strength label and tells you what to improve.

**Live website:** https://codes-ak.github.io/Password-security-analyser_syntax_error/

Project for *Problem Solving Using C* (CSA1500), class 1BCAAIML01, by **Team Syntax Error**.

> This is an educational project, not a professional security tool. Your password is never saved, printed to a file or sent anywhere.

## What is in this repository

| Path | What it is |
|---|---|
| `index.html`, `style.css`, `script.js` | The website (hosted with GitHub Pages) |
| `c_program/password_strength_analyzer.c` | The C console program |
| `docs/Password_Strength_Analyzer_Report.pdf` | Project report |
| `docs/Password_Strength_Analyzer_Presentation.pptx` | Project presentation |
| `assets/logo.png` | Team logo |

## C program

**Checks (1 point each, score out of 5):** length of at least 8, uppercase letter, lowercase letter, digit, special character.

| Score | Result |
|---|---|
| 0 to 2 | WEAK |
| 3 to 4 | MODERATE |
| 5 | STRONG |

It also prints a suggestion for every missing check. It uses only basic C: functions, strings, loops and `if` statements.

### Compile and run

```
gcc c_program/password_strength_analyzer.c -o analyzer
./analyzer
```

On Windows, run `analyzer.exe` instead of `./analyzer`.

### Sample output

```
===== PASSWORD STRENGTH ANALYZER =====
Enter a sample password (no spaces): abc12

===== ANALYSIS RESULT =====
Length: 5 characters
At least 8 characters : No
Uppercase letter      : No
Lowercase letter      : Yes
Digit                 : Yes
Special character     : No
Checks passed: 2 out of 5
Password strength: WEAK

Suggestions to improve your password:
 - Use at least 8 characters.
 - Add an uppercase letter (A-Z).
 - Add a special character like @ # $ !
```

## Website

Open `index.html` in a browser. It shows a live strength bar, a checklist and tips as you type. It scores out of 6 because it also checks for 12 or more characters.

## Team

Akshara Sajeevan M, Ayesha Iram Khan, Aditi Sharma, Aiushi Rathour, Aman Kumar Gupta

Faculty: Dr. Kuppla Saritha
