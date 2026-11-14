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
double add(double a, double b)
{
	return (a + b);
}

/**
 * subtract - subtracts two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the result of a - b
 */
double subtract(double a, double b)
{
	return (a - b);
}

/**
 * multiply - multiplies two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the product of a and b
 */
double multiply(double a, double b)
{
	return (a * b);
}

/**
 * divide - divides two numbers
 * @a: dividend
 * @b: divisor (must not be zero)
 *
 * Return: the result of a / b
 */
double divide(double a, double b)
{
	return (a / b);
}

/**
 * calculate - asks for A and B, then prints the result
 * @choice: the operation chosen (1 to 4)
 *
 * Return: 0 on success, 1 if the input is not a number
 */
int calculate(int choice)
{
	double a;
	double b;

	printf("A: ");
	if (scanf("%lf", &a) != 1)
		return (1);
	printf("B: ");
	if (scanf("%lf", &b) != 1)
		return (1);

	if (choice == 1)
		printf("Result: %.10g\n", add(a, b));
	else if (choice == 2)
		printf("Result: %.10g\n", subtract(a, b));
	else if (choice == 3)
		printf("Result: %.10g\n", multiply(a, b));
	else if (b == 0)
		printf("Error: division by zero\n");
	else
		printf("Result: %.10g\n", divide(a, b));

	return (0);
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
		else if (calculate(choice) != 0)
			return (1);
	}

	return (0);
}
