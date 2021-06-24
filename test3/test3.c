#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    // обьявление переменных
    float a, b, f, *v1, *v2, *res;
    long int d;
    d = 1;
    char c, e, choice, vecop, inp[100], outp[100];
    int size;

    	do
        {

    	// просьба ввести названия файлов
    	printf("Enter the name of the input file in the format (name.txt): \n");
    	scanf("%s", &inp);
    	printf("Enter the name of the output file in the format (name.txt): \n");
    	scanf("%s", &outp);

    	// создание файла для работы с данными
    	FILE *input, *output;
    	input = fopen(inp,"r");
    	output = fopen(outp,"w");

    	// БЛОК 1
    	//здесь пользователь выбирает какой калькулятор он будет использовать
        fprintf(output, "Choose calculator: \n");
		fprintf(output, "v - vectors, n - numbers\n");
		fscanf(input, "%s", &choice);
		// КОНЕЦ БЛОКА 1

			// БЛОК 2
			//Здесь описаны  векторные операции.
			//Пользователь вводит координаты вектора,
			//которые записываются в выделенные ячейки памяти.
			//После вывода результата, ячейки очищаюся.
			if (choice == 'v')
				{
					fprintf(output, "Enter size of the vectors: \n");
					fscanf(input, "%d", &size);
					v1 = malloc(size*sizeof(int));
					v2 = malloc(size*sizeof(int));
					res = malloc(size*sizeof(int));
					fprintf(output, "Enter first vector: \n");
					for(int i=0; i<size; i++)
						{
							fscanf(input, "%f", &v1[i]);
						}
					fprintf(output, "Enter second vector: \n");
					for(int i=0; i<size; i++)
						{
							fscanf(input, "%f", &v2[i]);
						}
					fprintf(output, "Choose an operation: +, -, *: \n");
					fscanf(input, "%s", &vecop);

					switch(vecop)
					{
					case '+':
						for(int i=0; i<size; i++)
			    			{
			    				fprintf(output, "%0.3f \n", v1[i] + v2[i]);
			    			}
						break;
					case '-':
						for(int i=0; i<size; i++)
			    			{
			    				fprintf(output, "%0.3f \n", v1[i] - v2[i]);
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
						fprintf(output, "%0.f \n", f);
						break;
					default:
					fprintf(output, "An invalid operation\n");
					}

					free(v1);
					free(v2);
					free(res);
				}
			// КОНЕЦ БЛОКА 2


			// БЛОК 3
			//здесь описаны арифметические операции
			//для реализаци некоторых функций была подключена библиотека math.h
			else if (choice == 'n')
				{
					fprintf(output, "Write first number: ");
					fscanf(input, "%f", &a);
					fprintf(output, "Available operations: +, -, *, /, !, ^, @\n");
					fprintf(output, "! finds the factorial of the number\n");
					fprintf(output, "^ brings the number to the power\n");
					fprintf(output, "@ extracts the square root from the number\n");
					fprintf(output,"Please, choose an operation: ");
					fscanf(input, "%s", &c);
					if (c == '+' || c == '-' || c == '*' || c == '/')
					{
						fprintf(output, "Write second number: ");
						fscanf(input, "%f", &b);
					}
					else if (c == '^')
					{
						fprintf(output, "Write degree of the number: ");
						fscanf(input, "%f", &b);
					}


					switch(c)
					{
						case '+':
							fprintf(output, "%0.2f plus %0.2f = %0.2f\n", a, b, a+b);
							break;
						case '-':
							fprintf(output, "%0.2f minus %0.2f = %0.2f\n", a, b, a-b);
							break;
						case '*':
							fprintf(output, "%0.3f multiply by %0.3f = %0.3f\n", a, b, a*b);
							break;
						case '/':
							if (b != 0)
							{
								fprintf(output, "%0.3f divide by %0.3f = %0.3f\n", a, b, a/b);
							}
							else
							{
								fprintf(output, "You can't divide by 0\n");
							}
							break;
						case '!':
							if (a < 0)
							{
								fprintf(output, "Invalid number\n");
							}
							else if (a == 0)
							{
								fprintf(output, "0\n");
							}
							else if(a - (int)a != 0)
							{
								fprintf(output, "You can't use fractional numbers\n");
							}
							else if (a != 0)
							{
								for (int i = 1; i <= a; i++)
								{
									d = d * i;
								}
								fprintf(output, "%li\n", d);
								d = 1;
							}
							break;
						case '^':
							if(b == 0)
							{
								fprintf(output, "1\n");
							}
							else
							{
								fprintf(output, "%f\n", pow(a, b));
							}
							break;
						case '@':
							if (a < 0)
							{
								fprintf(output, "Invalid number\n");
							}
							else
							{
								fprintf(output, "%f\n", sqrt(a));
							}
							break;
						default:
							fprintf(output, "Invalid operation\n");
					}

				}
			// КОНЕЦ БЛОКА 3

		fclose(input);
		fclose(output);

		printf("Do you want to continue? (y/n)\n");
        scanf("%s", &e);
        }
        while(e == 'y');

    return 0;
}
