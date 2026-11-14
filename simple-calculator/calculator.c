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
 * main - entry point of the calculator
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice = -1;

	print_menu();

	while (choice != 0)
	{
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
			return (1);

		if (choice == 0)
			printf("Bye!\n");
		else if (choice < 0 || choice > 4)
			printf("Invalid choice\n");
	}

	return (0);
}
