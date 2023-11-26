//project2 tax document

#include <iostream>
using namespace std;

int main() {
    
    //initilizing taxpayer info
    string name, occupation;
    double taxableIncome;
    int numberOfChildren;
    
    //collecting info
    cout << "Name: ";
    getline(cin, name);
    cout << "Taxable income: ";
    cin >> taxableIncome;
    
    cin.ignore(10000, '\n');
    cout << "Occupation: ";
    getline(cin, occupation);
    
    cout << "Number of children: ";
    cin >> numberOfChildren;
    cout << "---" << endl;
    
    //output any errors here and do not run rest of program
    if (name == ""){
        cout << "You must enter a name" << endl;
        return 1;
    }
    if (taxableIncome < 0){
        cout << "The taxable income must not be negative" << endl;
        return 1;
    }
    if (occupation == ""){
        cout << "You must enter an occupation" << endl;
        return 1;
    }
    if (numberOfChildren < 0){
        cout << "The number of children must not be negative" << endl;
        return 1;
    }
    
    
    //taxRates
    double rate1 = .04;
    double rate2 = .07;
    double rate3 = .093;
    if (occupation == "nurse" || occupation == "teacher")
        rate2 = .05;
    
    
    //taxable income in each bracket range
    double bracket1 = 0;
    double bracket2 = 0;
    double bracket3 = 0;
    if (taxableIncome > 125000){
        bracket1 = 55000;
        bracket2 = 70000;
        bracket3 = taxableIncome - 125000;
    }else if (taxableIncome > 55000){
        bracket1 = 55000;
        bracket2 = taxableIncome - 55000;
    }else{
        bracket1 = taxableIncome;
    }
    
    //variable to calculate final amount due
    double taxDue = 0.0;
    
    //child deductions
    if (taxableIncome < 125000)
        taxDue -= numberOfChildren * 200;
    
    //final calculations
    taxDue += bracket1 * rate1 + bracket2 * rate2 + bracket3 * rate3;
    
    //tax must not be negative
    if (taxDue < 0)
        taxDue = 0;
    
    //2 digit precison
    cout.setf(ios::fixed);
    cout.precision(2);
    
    // final output
    cout << name << " would pay $" << taxDue << endl;
    
}
