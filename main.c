#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdint.h>

int main() 
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    system("cls");
    srand(time(NULL));

    uint8_t digit, k, n;
    uint64_t q=1, userNumber;

    do
    {
        system("cls");
        printf("Введите скольки значное будет число [1;10]: ");
        scanf("%d", &digit);
    } while (digit<1 || digit>10);
    
    uint8_t compNumber[digit], userNumberArray[digit], bulls=0, cows=0;

    do
    {
        n=0;
        for (int i=0; i<digit; i++) 
        {
            compNumber[i] = rand() % 10;
            while (compNumber[0]==0)
            {
                compNumber[i] = rand() % 10;
            }
            

            do 
            {
                k=0;
                for (int j=0; j<i; j++)
                {
                    while (compNumber[i]==compNumber[j] && k==0) 
                    {
                        compNumber[i] = rand() % 10;
                        k=1;
                    }
                }
            } while (k==1);
        }
        
        printf("\nПопытка %d - ",q);
        for (int i = 0; i < digit; i++)
        {
            printf("%d", compNumber[i]);
            if (n==0 && compNumber[i]!=i+1) 
                n=1;
            if (i==9 && n==0 && compNumber[i]!=0)
                n=1;
        }
        
        q++;
    } while (n!=0);

    printf("\n");
    system("pause");
    return 0;
}
