#pragma once
// MathLibrary.h - Contains declaration of Function class


namespace MathLibrary
{
	// This class is exported from the MathLibrary.dll
	class Functions
	{
	public: 
		// Returns a+b
		static double Add(double a, double b);

		// Returns a*b
		static double Multiply(double a, double b);

		// Returns a+(a*b)
		static double AddMultiply(double a, double b);

		//Returns a-b
		static double Subtract(double a, double b);

		//Returns a/b
		static double Divide(double a, double b);

		//Returns a/b
		static double Percentage(double a, double b);
	};
}