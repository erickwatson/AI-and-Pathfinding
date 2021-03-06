// MathLibrary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MathLibrary.h"
#include "Vector2.h"
#include "Vector3.h"

namespace MathLibrary
{
	double Functions::Add(double a, double b)
	{
		return a + b;
	}

	double Functions::Multiply(double a, double b)
	{
		return a * b;
	}

	double Functions::AddMultiply(double a, double b)
	{
		return a + (a * b);
	}

	double Functions::Subtract(double a, double b)
	{
		return a - b;
	}

	double Functions::Divide(double a, double b)
	{
		return a / b;
	}

	double Functions::Percentage(double a, double b)
	{
		return a / b * 100;
	}




}


//int main()
//{
//    
//}

