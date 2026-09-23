#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int M[n][n];

    printf("Enter the matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }

    int celebrity = -1;

    for (int i = 0; i < n; i++)
    {
        int knowsNobody = 1;
        int knownByEveryone = 1;

        //checking row : celebrity should know nobody
        for (int j = 0; j < n; j++)
        {
            if (i != j && M[i][j] == 1)
            {
                knowsNobody = 0;
                break;
            }
        }

        //checking columnn : everyone should know celebrity
        for (int j = 0; j < n; j++)
        {
            if (i != j && M[j][i] == 0)
            {
                knownByEveryone = 0;
                break;
            }
        }

        if (knowsNobody && knownByEveryone)
        {
            celebrity = i;
            break;
        }
    }

    if (celebrity == -1)
    {
        printf("No celebrity found.\n");
    }
    else
    {
        printf("Celebrity is person %d\n", celebrity);
    }

    return 0;
}