#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    // обьявление переменных
    float a, b, f, *v1, *v2, *res;
    long int d;
    d = 1;
    char c, e, choice, vecop;
    int size;


    	do
        {


    	// БЛОК 1
    	//здесь пользователь выбирает какой калькулятор он будет использовать
        printf("Choose calculator: \n");
		printf("1 - vectors, 2 - numbers\n");
		scanf("%s", &choice);
		// КОНЕЦ БЛОКА 1


			// БЛОК 2
			//Здесь описаны  векторные операции.
			//Пользователь вводит координаты вектора,
			//которые записываются в выделенные ячейки памяти.
			//После вывода результата, ячейки очищаюся.
			if (choice == '1')
				{
					printf("Enter size of the vectors: \n");
					scanf("%d", &size);
					v1 = malloc(size*sizeof(int));
					v2 = malloc(size*sizeof(int));
					res = malloc(size*sizeof(int));
					printf("Enter first vector: \n");
					for(int i=0; i<size; i++)
						{
							scanf("%f", &v1[i]);
						}
					printf("Enter second vector: \n");
					for(int i=0; i<size; i++)
						{
							scanf("%f", &v2[i]);
						}
					printf("Choose an operation: +, -, *: \n");
					scanf("%s", &vecop);

					switch(vecop)
					{
					case '+':
						for(int i=0; i<size; i++)
			    			{
			    				printf("%0.3f \n", v1[i] + v2[i]);
			    			}
						break;
					case '-':
						for(int i=0; i<size; i++)
			    			{
			    				printf("%0.3f \n", v1[i] - v2[i]);
			    			}
						break;
					case '*':
						for(int i=0; i<size; i++)
			    			{
			    				res[i] = v1[i] * v2[i];
			    			}
						for(int i=0; i<size; i++)
			    			{
			    				f = res[i] + f;
			    			}
						printf("%0.f \n", f);
						break;
					default:
					printf("An invalid operation\n");
					}

					free(v1);
					free(v2);
					free(res);
				}
			// КОНЕЦ БЛОКА 2



			// БЛОК 3
			//здесь описаны арифметические операции
			//для реализаци некоторых функций была подключена библиотека math.h
			else if (choice == '2')
				{
					printf("Write first number: ");
					scanf("%f", &a);
					printf("Available operations: +, -, *, /, !, ^, @\n");
					printf("! finds the factorial of the number\n");
					printf("^ brings the number to the power\n");
					printf("@ extracts the square root from the number\n");
					printf("Please, choose an operation: ");
					scanf("%s", &c);





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

				}
			// КОНЕЦ БЛОКА 3


		printf("Do you want to continue? (y/n)\n");
        scanf("%s", &e);
        system("cls"); // очищает экран консоли
        }
        while(e == 'y');

    return 0;
}
