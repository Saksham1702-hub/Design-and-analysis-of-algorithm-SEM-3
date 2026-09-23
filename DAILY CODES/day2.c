//Write a program using a while loop that repeatedly asks the user to enter the password and stops only when the correct password is entered. Finally, display "Login successful!".

#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];
    char correctPassword[] = "saksham1";

    printf("Enter password: ");
    scanf("%s", password);

    while (strcmp(password, correctPassword) != 0)
    {
        printf("Wrong password. Try again: ");
        scanf("%s", password);
    }

    printf("Login successful!");

    return 0;
}