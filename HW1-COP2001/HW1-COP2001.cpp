// HW1-COP2001.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void PrintSchedule(double intRate, double initialPrincipal, double paymentAmount) {
	double currentPrincipal = initialPrincipal;
	double monthlyInterest = intRate / 12;
	double interestThisMonth;
	double paymentOnPrincipal;
	int paymentCounter = 0;
	//	TODO: Possible Improvement - Add dollar sign to table data for currency amounts
	//	char dollarSign[] = "$";
	//  printf("%10s%.2f", dollarSign, initialPrincipal);   -  unsuccessful attempt at including dollar sign

	printf("The initial loan is $%.2f, \n", initialPrincipal);
	printf("The interest rate is %.2f, \n", intRate);
	printf("The payment amount is $%.2f \n", paymentAmount);

	printf("\n");
	printf("               Interest     Principal    Ending       Payment\n");
	printf(" Principal       Paid         Paid       Payment      Balance     made on: \n");
	printf("__________   __________   __________   __________   __________   ____________\n");
	while (currentPrincipal > 0) {
		paymentCounter++;
		interestThisMonth = currentPrincipal * monthlyInterest;
		paymentOnPrincipal = paymentAmount - interestThisMonth;
		if (paymentOnPrincipal > currentPrincipal) {
			paymentOnPrincipal = currentPrincipal;
			paymentAmount = currentPrincipal + interestThisMonth;
		}
		printf("%*.2f   ", 10, currentPrincipal);
		printf("%*.2f   ", 10, interestThisMonth);
		printf("%*.2f   ", 10, paymentOnPrincipal);
		printf("%*.2f   ", 10, paymentAmount);
		currentPrincipal = currentPrincipal - paymentOnPrincipal;
		printf("%*.2f   ", 10, currentPrincipal);
		printf("____________\n");
	}
}
int main() {
	double initialPrincipal, interestRate, paymentAmount;
	printf("Enter the amount of the loan : ");
	scanf("%lf", &initialPrincipal);
	printf("\nEnter the interest rate(as decimcal eg: .04) : ");
	scanf("%lf", &interestRate);
	printf("\nEnter the payment amount per month : ");
	scanf("%lf", &paymentAmount);
	PrintSchedule(interestRate, initialPrincipal, paymentAmount);
	return 0;
}
