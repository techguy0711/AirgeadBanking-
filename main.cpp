#include <iostream>
#include <iomanip>

using namespace std;

void displayForm()
{
    //Display form to user
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";
}
void displayResults(float initialInvestment, float monthlyDeposit, float anualInterest, float years, float months)
{
    //Declare variables to store year end total amount, interest, and year end interest
    float totalAm, intAmt, yearTotInt;

    //Set total amount to initial investment to be updated
    totalAm = initialInvestment;

    //Display year data without monthly deposits
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";


    for (int i = 0; i < years; i++) {

        //Calculate yearly interest
        intAmt = (totalAm) * ((anualInterest / 100));

        //Calculate year end total
        totalAm = totalAm + intAmt;

        //Print results to table showcasing only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << "\n";

    }

    //Set total amount to initial investment to be updated
    totalAm = initialInvestment;

    //Display year data with monthly deposits
    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {

        //Set yearly interest to zero at the start of the year
        yearTotInt = 0;

        for (int j = 0; j < 12; j++) {

            //Calculate monthly interest
            intAmt = (totalAm + monthlyDeposit) * ((anualInterest / 100) / 12);

            //Calculate month end interest
            yearTotInt = yearTotInt + intAmt;

            //Calculate month end total
            totalAm = totalAm + monthlyDeposit + intAmt;

        }

        //Print results to table showcasing only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << yearTotInt << "\n";


    }
}
void getUserInput(float initialInvestment, float monthlyDeposit, float anualInterest, float years, float months)
{
    //Get data from user
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;
    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    cout << "Annual Interest: %";
    cin >> anualInterest;
    cout << "Number of years: ";
    cin >> years;
    months = years * 12;
    displayResults(initialInvestment,monthlyDeposit,anualInterest,years,months);
}

int main()
{
    //Declare variables to store input
    float initialInvestment, monthlyDeposit, anualInterest, months, years;

    displayForm();
    getUserInput(initialInvestment,monthlyDeposit,anualInterest,years,months);


    return 0;
}
