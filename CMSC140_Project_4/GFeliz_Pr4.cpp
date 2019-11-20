/*
* Class: CMSC140 CRN 20780
* Instructor: Madhvi Shah
* Project 4
* Description: Program that displays a weekly payroll report.
* Due Date: 10/30/2017
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Gabriel I Feliz
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	// Declare and initialize int and double variables
	int employee_Number = 1;

	double gross_Pay = 0.00,
		federal_Withholding = 0.00,
		state_Withholding = 0.00,
		fica_Withholding = 0.00,
		total_Gross_Pay = 0.00,
		total_Federal_Withholding = 0.00,
		total_State_Withholding = 0.00,
		total_FICA_Withholding = 0.00,
		total_Net_Pay = 0.00;

	// Declare and initialize string literals
	string emplNum = "Employee Number ",
		quit = "(0 to quit): ",
		grossPay = "Gross Pay: ",
		fedWithh = "Federal Withholding: ",
		stWithh = "State Withholding: ",
		ficaWithh = "FICA Withholding: ";

	// Declare Boolean variable
	bool invalid;

	// Two decimal places to the right will be displayed
	cout << fixed << showpoint << setprecision(2);

	while (employee_Number != 0) //This while loop determines the sentinel, which is zero.
	{
		// Prompt and read employee's number for the first employee
		cout << endl << "Enter the following information: " << endl << endl;
		cout << emplNum << quit;
		cin >> employee_Number;

		/* This nested while loop invalidates negative numbers
		and forces the user to re-enter employee number*/
		while (employee_Number < 0)
		{
			cout << "	Employee number may not be less than zero" << endl;
			cout << "	Please re-enter " << emplNum << ": ";
			cin >> employee_Number;
		}
		if (employee_Number > 0)
		{

			do // This loop is executed once, and then the condition will be tested
			{
				// Prompt and read gross pay
				cout << grossPay;
				cin >> gross_Pay;

				/* This nested while loop invalidates negative numbers
				and forces the user to re-enter gross pay*/
				while (gross_Pay < 0)
				{
					cout << "	Gross pay may not be less than zero." << endl;
					cout << "	Re-enter " << grossPay;
					cin >> gross_Pay;
				}

				cout << fedWithh;
				cin >> federal_Withholding;

				/* This nested while loop invalidates negative numbers
				and forces the user to re-enter federal withholding */
				while (federal_Withholding < 0)
				{
					cout << "	Federal withholding may not be less than zero." << endl;
					cout << "	Re-enter " << fedWithh;
					cin >> federal_Withholding;
				}

				/* This nested while loop invalidates numbers greater than gross pay
				and forces the user to re-enter federal withholding */
				while (federal_Withholding > gross_Pay)

				{
					cout << "	Federal withholding may not exceed gross pay." << endl;
					cout << "	Re-enter " << fedWithh;
					cin >> federal_Withholding;

					/* This nested while loop re-invalidates negative numbers, just in case the user
					enters a negative number after entering an amount greater than the gross pay.
					If omitted, the program will read a negative number for the federal withholding */
					while (federal_Withholding < 0)
					{
						cout << "	Federal withholding may not be less than zero." << endl;
						cout << "	Re-enter " << fedWithh;
						cin >> federal_Withholding;
					}
				}

				cout << stWithh;
				cin >> state_Withholding;
				/* This nested while loop invalidates negative numbers
				and forces the user to re-enter state withholding*/
				while (state_Withholding < 0)
				{
					cout << "	State withholding may not be less than zero." << endl;
					cout << "	Re-enter " << stWithh;
					cin >> state_Withholding;
				}

				/* This nested while loop invalidates numbers greater than gross pay
				and forces the user to re-enter state withholding*/
				while (state_Withholding > gross_Pay)
				{
					cout << "	State withholding may not exceed gross pay." << endl;
					cout << "	Re-enter " << stWithh;
					cin >> state_Withholding;

					/* This nested while loop re-invalidates negative numbers, just in case the user
					enters a negative number after entering an amount greater than the gross pay.
					If omitted, the program will read a negative number for the state withholding */
					while (state_Withholding < 0)
					{
						cout << "	State withholding may not be less than zero." << endl;
						cout << "	Re-enter " << stWithh;
						cin >> state_Withholding;
					}
				}

				cout << ficaWithh;
				cin >> fica_Withholding;
				/* This nested while loop invalidates negative numbers
				and forces the user to re-enter FICA withholding*/

				while (fica_Withholding < 0)
				{
					cout << "	FICA withholding may not be less than zero." << endl;
					cout << "	Re-enter " << ficaWithh;
					cin >> fica_Withholding;
				}

				/* This nested while loop invalidates numbers greater than gross pay
				and forces the user to re-enter FICA withholding*/
				while (fica_Withholding > gross_Pay)
				{
					cout << "	FICA withholding may not exceed gross pay." << endl;
					cout << "	Re-enter " << ficaWithh;
					cin >> fica_Withholding;

					/* This nested while loop re-invalidates negative numbers, just in case the user
					enters a negative number after entering an amount greater than the gross pay.
					If omitted, the program will read a negative number for the FICA withholding */
					while (fica_Withholding < 0)
					{
						cout << "	FICA withholding may not be less than zero." << endl;
						cout << "	Re-enter " << ficaWithh;
						cin >> fica_Withholding;
					}
				}

				/* This nested if statement invalidates the sum of withholdings to be greater
				than gross pay. It displays an error message and assigns the Boolean variable
				invalid as true*/
				if (federal_Withholding + state_Withholding + fica_Withholding > gross_Pay)
				{
					cout << endl << "	ERROR: Sum of withholdings cannot exceed gross pay" << endl;
					cout << "	Please re-enter data for this employee" << endl;
					/* The Boolean variable invalid makes the condition inside the do...while loop true
					so it returns back to asking the user to enter gross pay and withholdings*/
					invalid = true;

				}
				else
				{
					// Running totals. 

					// The value of gross pay is added to total gross pay
					total_Gross_Pay += gross_Pay;
					// The value of federal withholding is added to total federal withholding
					total_Federal_Withholding += federal_Withholding;
					// The value of state withholding is added to total state withholding
					total_State_Withholding += state_Withholding;
					// The value of FICA withholding is added to total FICA withholding
					total_FICA_Withholding += fica_Withholding;
					/* The value of gross pay is added to total net pay. Then, the withholdings
					are subtracted from the stored value*/
					total_Net_Pay += gross_Pay;
					total_Net_Pay -= federal_Withholding;
					total_Net_Pay -= state_Withholding;
					total_Net_Pay -= fica_Withholding;

					// Prompt and read employee's number for the second and future employees
					cout << endl << endl << "Processing the next employee: " << endl << endl;
					cout << emplNum << quit;
					cin >> employee_Number;

					/* This nested while loop invalidates negative numbers
					and forces the user to re-enter employee number*/
					while (employee_Number < 0)
					{
						cout << "	Employee number may not be less than zero" << endl;
						cout << "	Please re-enter " << emplNum << ": ";
						cin >> employee_Number;
					}
					/* Even there is no invalid input, the Boolean variable is still true. This is
					so that the user enter the gross pay and withholdings for the second and future employees*/
					invalid = true;
				}
			} while (employee_Number != 0);
			/* The totals of gross pay, withholdings and net pay are displayed only when the data (gross pay and
			withholdings) of at least one employee has been entered. For instance, the program will not display
			anything if the user enters the sentinel (zero) in the employee number for the first employee */

			cout << endl;
			cout << "Total Gross Pay:      " << setw(8) << "$" << setw(1) << "" << total_Gross_Pay << endl;
			cout << "Total Federal Tax:    " << setw(8) << "$" << setw(1) << "" << total_Federal_Withholding << endl;
			cout << "Total State Tax:      " << setw(8) << "$" << setw(1) << "" << total_State_Withholding << endl;
			cout << "Total FICA:           " << setw(8) << "$" << setw(1) << "" << total_FICA_Withholding << endl;
			cout << "Total Net Pay:        " << setw(8) << "$" << setw(1) << "" << total_Net_Pay << endl << endl;
			cout << endl << "Programmer: Gabriel I Feliz " << endl;
		}
	}

	system("pause");
	return 0;
}