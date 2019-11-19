// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string> 
#include <iomanip>


#define MAX 999
class stack
{
private:
	int arr[MAX];
	int top;

public:
	stack()
	{
		top = -1;
	}

	void push(int total)
	{
		top++;
		if (top < MAX)
		{
			arr[top] = total;
		}
		else
		{
			std::cout << "STACK FULL" << std::endl;
			top--;
		}
	}
	int pop(int total)
	{
		if (top == -1)
		{
			std::cout << "STACK IS EMPTY" << std::endl;
			return NULL;
		}
		else
		{
			total = arr[top];
			arr[top] = NULL;
			top--;
			return total;
		}
	}
};

int main()
{
	stack total;
	bool Continue = true;
	char op;
	std::string res1;
	std::string res2;
	std::string res3;
	float stack = 0;
	float num1;
	float num2;
	float result;
	float sum = 0;
    std::cout << "Hello, Welcome to the Calculator App.\n";

	while (Continue == true)
	{
		std::cout << "What would you like to do?\n";
		std::cout << "+ or - or * or / \n";
		std::cin >> op;
		std::cout << "Enter the first digit: \n";
		std::cin >> num1;
		std::cout << "Enter the second digit: \n";
		std::cin >> num2;

		switch (op)
		{
		case '+':
			std::cout << "The total is ";
			result = num1 + num2;
			sum += result;
			//total.push(sum);
			std::cout << sum;
			stack++;
			break;
		case '-':
			std::cout << "The total is ";
			result = num1 - num2;
			sum += result;
			//total.push(sum);
			std::cout << sum;
			stack++;
			break;
		case '*':
			std::cout << "The total is ";
			result = num1 * num2;
			sum += result;
			//total.push(sum);
			std::cout << sum;
			stack++;
			break;
		case '/':
			std::cout << "The total is ";
			result = num1 / num2;
			sum += result;
			//total.push(sum);
			std::cout << sum;
			stack++;
			break;
		default:
			std::cout << "Error! operator is not correct";
			break;
		}
		if (stack > 0)
		{
			std::cout << "\nWould you like to undo your answer?";
			std::cin >> res2;
			if (res2 == "yes")
			{
				sum = total.pop(sum);
				std::cout << "Sum: " << sum << std::endl;
				std::cout << "Would you like to redo your answer?";
				std::cin >> res3;
				if (res3 == "yes")
				{
					if (op = "+" || "*")
					{
						sum += result;
						total.push(sum);
						std::cout << "Sum: " << sum << std::endl;
					}
					else if (op = "-" || "/")
					{
						sum -= result;
						total.push(sum);
						std::cout << "Sum: " << sum << std::endl;
					}
				}
			}
			else if (res2 == "no")
			{
				total.push(sum);
				std::cout << "\nWould you like to continue? \n";
				std::cin >> res1;
				if (res1 == "yes")
				{
					Continue == true;
				}
				else if (res1 == "no")
				{
					break;
				}
			}
		}
	}
	return 0;
}

