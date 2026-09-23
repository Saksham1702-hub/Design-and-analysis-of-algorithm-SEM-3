#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char s[1000];
        scanf("%s", s);

        int len = strlen(s);
        int lower = 0, upper = 0;
        int digit = 0, special = 0;

        for (int i = 0; i < len; i++) {

            if (s[i] >= 'a' && s[i] <= 'z')
                lower = 1;

            if (i > 0 && i < len - 1) {

                if (s[i] >= 'A' && s[i] <= 'Z')
                    upper = 1;

                if (s[i] >= '0' && s[i] <= '9')
                    digit = 1;

                if (s[i] == '@' || s[i] == '#' ||
                    s[i] == '%' || s[i] == '&' ||
                    s[i] == '?')
                    special = 1;
            }
        }

        if (len >= 10 && lower && upper &&
            digit && special)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}