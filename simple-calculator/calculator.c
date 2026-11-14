#include <stdio.h>

/**
 * print_menu - displays the calculator menu
 *
 * Return: Nothing.
 */
void print_menu(void)
{
	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
}

/**
 * add - adds two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the sum of a and b
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * main - entry point of the calculator
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice = -1;
	int a, b;

	print_menu();

	while (choice != 0)
	{
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
			return (1);

		if (choice == 0)
			printf("Bye!\n");
		else if (choice == 1)
		{
			printf("A: ");
			if (scanf("%d", &a) != 1)
				return (1);
			printf("B: ");
			if (scanf("%d", &b) != 1)
				return (1);
			printf("Result: %d\n", add(a, b));
		}
		else if (choice < 0 || choice > 4)
			printf("Invalid choice\n");
	}

	return (0);
}
