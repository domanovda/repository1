#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    // обьявление переменных
	// изменение

    float a, b;
    long int d;
    d = 1;
    char c, e;

        // БЛОК 1
        // ввод пользователем первого числа
        do
        {
        printf("Write first number: ");
        scanf("%f", &a);

        //КОНЕЦ БЛОКА 1

        // БЛОК 2
        // описание+выбор пользователем арифметической операции
        printf("Available operations: +, -, *, /, !, ^, @\n");
        printf("! finds the factorial of the number\n");
        printf("^ brings the number to the power\n");
        printf("@ extracts the square root from the number\n");
        printf("Please, choose an operation: ");
        scanf("%s", &c);
        // КОНЕЦ БЛОКА 2

        // БЛОК 3
        // ввод пользователем второго числа или степени, в которую будет возводиться первое число
        if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                printf("Write second number: ");
                scanf("%f", &b);
            }
            else if (c == '^')
            {
                printf("Write degree of the number: ");
                scanf("%f", &b);
            }
        // КОНЕЦ БЛОКА 3

        // БЛОК 4
        // арифметические операции в зависимости от того, что выбрал пользователь
        // при помощи оператора switch программа решает какой алгоритм действий ей
        // использовать, для реализаци некоторых функций была подключена библиотека math.h
        switch(c)
        {
        case '+':
            printf("%0.2f plus %0.2f = %0.2f\n", a, b, a+b);
            break;
        case '-':
            printf("%0.2f minus %0.2f = %0.2f\n", a, b, a-b);
            break;
        case '*':
            printf("%0.3f multiply by %0.3f = %0.3f\n", a, b, a*b);
            break;
        case '/':
            if (b != 0)
            {
        printf("%0.3f divide by %0.3f = %0.3f\n", a, b, a/b);
            }
            else
            {
            printf("You can't divide by 0\n");
            }
            break;
        case '!':
            if (a < 0)
            {
                printf("Invalid number\n");
            }
            else if (a == 0)
            {
                printf("0\n");
            }
            else if(a - (int)a != 0)
            {
                printf("You can't use fractional numbers\n");
            }
            else if (a != 0)
            {
               for (int i = 1; i <= a; i++)
                {
                d = d * i;
                }
            printf("%li\n", d);
            d = 1;
            }
            break;
        case '^':
        if(b == 0)
            {
                printf("1\n");
            }
        else
            {
            printf("%f\n", pow(a, b));
            }
            break;
        case '@':
        if (a < 0)
            {
            printf("Invalid number\n");
            }
            else
            {
            printf("%f\n", sqrt(a));
            }
            break;
        default:
            printf("Invalid operation\n");
        }
        // КОНЕЦ БЛОКА 4

        // БЛОК 5
        // в этом блоке программа спрашивает, будет ли пользователь использовать ее повторно
        // а так же очищает экран консоли
        printf("Do you want to continue? (y/n)\n");
        scanf("%s", &e);
        system("cls"); // очищает экран консоли
        }
        while(e == 'y');
        // КОНЕЦ БЛОКА 5

    return 0;
}
