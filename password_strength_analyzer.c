/* ------------------------------------------------------------
   PASSWORD STRENGTH ANALYZER USING C
   C Programming Mini-Project (basic version)

   What it does:
   - Takes one password from the user (no spaces)
   - Checks 5 things: length >= 8, uppercase, lowercase,
     digit and special character
   - Gives 1 point for each check passed (score out of 5)
   - Shows WEAK / MODERATE / STRONG and tips for what is missing

   The password is only used while the program runs.
   It is never saved, printed to a file or logged.
   ------------------------------------------------------------ */

#include <stdio.h>
#include <string.h>

/* Function 1: returns 1 if the password has an uppercase letter */
int hasUpper(char pass[])
{
    int i;
    int len = strlen(pass);
    for (i = 0; i < len; i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
            return 1;
    }
    return 0;
}

/* Function 2: returns 1 if the password has a lowercase letter */
int hasLower(char pass[])
{
    int i;
    int len = strlen(pass);
    for (i = 0; i < len; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
            return 1;
    }
    return 0;
}

/* Function 3: returns 1 if the password has a digit */
int hasDigit(char pass[])
{
    int i;
    int len = strlen(pass);
    for (i = 0; i < len; i++)
    {
        if (pass[i] >= '0' && pass[i] <= '9')
            return 1;
    }
    return 0;
}

/* Function 4: returns 1 if the password has a special character
   (anything that is not a letter or a digit) */
int hasSpecial(char pass[])
{
    int i;
    int len = strlen(pass);
    for (i = 0; i < len; i++)
    {
        if (!(pass[i] >= 'A' && pass[i] <= 'Z') &&
            !(pass[i] >= 'a' && pass[i] <= 'z') &&
            !(pass[i] >= '0' && pass[i] <= '9'))
            return 1;
    }
    return 0;
}

/* Function 5: adds 1 point for every check that passed */
int calculateScore(int length, int upper, int lower, int digit, int special)
{
    int score = 0;

    if (length >= 8)
        score++;
    if (upper == 1)
        score++;
    if (lower == 1)
        score++;
    if (digit == 1)
        score++;
    if (special == 1)
        score++;

    return score;
}

/* Function 6: shows the result of each check */
void showChecks(int length, int upper, int lower, int digit, int special)
{
    printf("Length: %d characters\n", length);
    printf("At least 8 characters : %s\n", length >= 8 ? "Yes" : "No");
    printf("Uppercase letter      : %s\n", upper ? "Yes" : "No");
    printf("Lowercase letter      : %s\n", lower ? "Yes" : "No");
    printf("Digit                 : %s\n", digit ? "Yes" : "No");
    printf("Special character     : %s\n", special ? "Yes" : "No");
}

/* Function 7: shows the strength category */
void showStrength(int score)
{
    if (score < 3)
        printf("Password strength: WEAK\n");
    else if (score < 5)
        printf("Password strength: MODERATE\n");
    else
        printf("Password strength: STRONG\n");
}

/* Function 8: shows a tip for every missing check */
void showSuggestions(int length, int upper, int lower, int digit, int special)
{
    if (length >= 8 && upper && lower && digit && special)
    {
        printf("Great! Your password meets all the checks.\n");
        return;
    }

    printf("Suggestions to improve your password:\n");
    if (length < 8)
        printf(" - Use at least 8 characters.\n");
    if (upper == 0)
        printf(" - Add an uppercase letter (A-Z).\n");
    if (lower == 0)
        printf(" - Add a lowercase letter (a-z).\n");
    if (digit == 0)
        printf(" - Add a digit (0-9).\n");
    if (special == 0)
        printf(" - Add a special character like @ # $ !\n");
}

int main()
{
    char password[100];
    int length, upper, lower, digit, special, score;

    printf("===== PASSWORD STRENGTH ANALYZER =====\n");
    printf("Enter a sample password (no spaces): ");
    scanf("%99s", password);

    /* Run all the checks */
    length  = strlen(password);
    upper   = hasUpper(password);
    lower   = hasLower(password);
    digit   = hasDigit(password);
    special = hasSpecial(password);
    score   = calculateScore(length, upper, lower, digit, special);

    /* Show the results */
    printf("\n===== ANALYSIS RESULT =====\n");
    showChecks(length, upper, lower, digit, special);
    printf("Checks passed: %d out of 5\n", score);
    showStrength(score);
    printf("\n");
    showSuggestions(length, upper, lower, digit, special);

    printf("\nNote: This is a basic educational estimate, not a\n");
    printf("guarantee of security. Your password was not saved.\n");

    return 0;
}
