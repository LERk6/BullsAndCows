#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

int main() 
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    system("cls");
    srand(time(NULL));

    int digit, k, n;
    unsigned long long int userNumber, compNumber=0;

    do
    {
        system("cls");
        printf("               Быки и Коровы\n");
        printf("\nВведите скольки значное будет число [1;10]: ");
        scanf("%d", &digit);
    } while (digit<1 || digit>10);
    
    int compNumberArray[digit], userNumberArray[digit], bulls, cows;

    printf("\ncompNumber=%llu\n", compNumber);

    for (int i=0; i<digit; i++) 
    {
        compNumberArray[i] = rand() % 10;
        while (compNumberArray[0]==0)
        {
            compNumberArray[i] = rand() % 10;
        }
        

        do 
        {
            k=0;
            for (int j=0; j<i; j++)
            {
                while (compNumberArray[i]==compNumberArray[j] && k==0) 
                {
                    compNumberArray[i] = rand() % 10;
                    k=1;
                }
            }
        } while (k==1);
        int q=pow(10,digit-i-1);
        int w=compNumberArray[i];
        compNumber=w*q;
        printf("i=%d,compNumber=%llu\n", i, compNumber);
    }
    
    do
    {
        printf("Введите предполагаемое %d-значное число: ", digit);
        scanf("%llu", &userNumber);

        bulls=4;
        cows=0;

        for (int i = 0; i < digit; i++)
        {
            printf("%d", compNumberArray[i]);
        }
    } while (bulls!=4);

    printf("\nВы угадали загаданное число!\nОтвет: %llu\nКолличество попыток, которо", compNumber);
    system("pause");
    return 0;
}