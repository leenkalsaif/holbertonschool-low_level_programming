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
	printf("Choice: ");
}

/**
 * main - entry point of the calculator
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice;

	print_menu();
	if (scanf("%d", &choice) != 1)
		return (1);

	if (choice == 0)
		printf("Bye!\n");

	return (0);
}
