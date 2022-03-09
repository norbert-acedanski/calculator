//Norbert Acedański
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <ctime>
using namespace std;
unsigned int day_1, day_2, month_1, month_2, year_1, year_2;
int i, numberOfElements, keepCalculating=1, y, degreeValue_Int, powerValue_Int, numberToCalculate_Int;
long double result, degreeValue_Double, powerValue_Double, currentNumber, numberToCalculate_Double;
unsigned short int choice, keepAveraging=1;
float product, power, weightProduct, currentProduct, currentWeight, kFactor;

time_t dateToTimeConversion(int day, int month, int year)
{
	tm tmp=tm();
	tmp.tm_mday=day;
	tmp.tm_mon=month-1;
	tmp.tm_year=year-1900;
	return mktime(&tmp);
}

void datePlusDays(struct tm* date, int days)
{
	const time_t ONE_DAY=24*60*60;
	time_t date_seconds=mktime(date)+(days*ONE_DAY);
	*date=*localtime(&date_seconds);
}

void dateDifferenceProgram()
{
	cout<<"11 - DATE DIFFERENCE\n";
	cout<<"To calculate days between dates, enter 1, to add/subtract days from a date, enter 2: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			cout<<"Enter the day of the first date: ";
			cin>>day_1;
			cout<<"Enter the month of the first date: ";
			cin>>month_1;
			cout<<"Enter the year of the first date: ";
			cin>>year_1;
			cout<<"Enter the day of the second date: ";
			cin>>day_2;
			cout<<"Enter the month of the second date: ";
			cin>>month_2;
			cout<<"Enter the year of the second date: ";
			cin>>year_2;
			time_t date_1=dateToTimeConversion(day_1, month_1, year_1);
			time_t date_2=dateToTimeConversion(day_2, month_2, year_2);
			long double sec=difftime(date_2, date_1);
			long days=abs(static_cast<long>(sec/(60*60*24)));
			cout<<"The number of days between "<<day_1<<"."<<month_1<<"."<<year_1<<" and "<<day_2<<"."<<month_2<<"."<<year_2<<" equals: "<<days<<endl;
			break;
		}
		case 2:
		{
			cout<<"Enter the day of the date: ";
			cin>>day_1;
			cout<<"Enter the month of the date: ";
			cin>>month_1;
			cout<<"Enter the year of the date: ";
			cin>>year_1;
			cout<<"Enter the number of days, you want to add (to subtract, enter negative number): ";
			cin>>currentNumber;
			struct tm date={0,0,12};
			date.tm_mday=day_1;
			date.tm_mon=month_1-1;
			date.tm_year=year_1-1900;
			datePlusDays(&date, currentNumber);
			cout<<"When adding "<<currentNumber<<" to date: "<<day_1<<"."<<month_1<<"."<<year_1<<" you get: "<<asctime(&date);
			break;
		}	
		default:
		{
			cout<<"Not acceptable choice";
			break;
		}
	}
}

void percentagesProgram()
{
	cout<<"10 - PERCENTAGES\n";
	cout<<"Enter the number: ";
	cin>>numberToCalculate_Double;
	cout<<"Enter the percentage, you want to calculate: ";
	cin>>currentNumber;
	result=numberToCalculate_Double*currentNumber/100;
	cout<<currentNumber<< " percent of " <<numberToCalculate_Double<< " equals: " <<result<<endl;
}

void arithmeticAverage()
{
	cout<<"1 - ARYTHMETIC AVERAGE\n";
	cout<<"Arythmetic average form:\n";
	cout<<"(a1+a2+a3+...+an)\n";
	cout<<"-----------------\n";
	cout<<"        n\n";
	cout<<"It is a sum of the elements divided by their amount.\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=0;
	for(i=0; i<numberOfElements; i++)
		{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		product+=currentNumber;
	}
	result=product/numberOfElements;
	cout<<"Arythmetic average of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void geometricAverage()
{
	cout<<"2 - GEOMETRIC AVERAGE\n";
	cout<<"Geometric average form:\n";
	cout<<"    ________________\n";
	cout<<"n  /\n";
	cout<<" \\/ a1*a2*a3*...*an\n";
	cout<<"It is an n-th square root of the product of positive numbers\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=1;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		if(currentNumber<=0)
		{
			cout<<"Cannot compute geometric average with non-positive numbers\n";
			i--;
		}
		product*=currentNumber;
	}
	power=1.00/numberOfElements;
	result=pow(product, power);
	cout<<"Geometric mean of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void harmonicAverage()
{
	cout<<"3 - HARMONIC AVERAGE\n";
	cout<<"Harmonic average form:\n";
	cout<<"       n\n";
	cout<<"---------------\n";
	cout<<" 1  1  1      1\n";
	cout<<"--+--+--+...+--\n";
	cout<<"a1 a2 a3     an\n";
	cout<<"It is a number of elements divided by the sum of inverses of the positive numbers\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=0;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		if(currentNumber<=0)
		{
			cout<<"Cannot compute harmonic average with non-positive numbers\n";
			i--;
		}
		product+=1.00/currentNumber;
	}
	result=numberOfElements/product;
	cout<<"Harmonic average of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void squareAverage()
{
	cout<<"4 - SQUARE AVERAGE\n";
	cout<<"Square average form:\n";
	cout<<"      ____________________\n";
	cout<<"     /  2    2          2\n";
	cout<<"    / a1 + a2 + ... + an\n";
	cout<<"\\  /  -------------------\n";
	cout<<" \\/            n\n";
	cout<<"It is a square root of the arithmetic average of squared numbers\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=0;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		product+=currentNumber*currentNumber;
	}
	product=product/numberOfElements;
	result=sqrt(product);
	cout<<"Square average of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void powerAverage()
{
	cout<<"5 - POWER AVERAGE\n";
	cout<<"Power average form:\n";
	cout<<"       ____________________\n";
	cout<<"      /  k    k          k\n";
	cout<<"k    / a1 + a2 + ... + an\n";
	cout<<" \\  /  -------------------\n";
	cout<<"  \\/            n\n";
	cout<<"It is a k-th root of the quotient of the sums of the k-th powers of successive numbers and the number of elements\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	cout<<"Enter \"k\" factor: ";
	cin>>kFactor;
	currentProduct=0;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		currentProduct=pow(currentNumber, kFactor);
		product+=currentProduct;
	}
	product=product/numberOfElements;
	power=1.00/kFactor;
	result=pow(product, power);
	cout<<"Power average of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void weightedAverage()
{
	cout<<"6 - WEIGHTED AVERAGE\n";
	cout<<"Weighted average form:\n";
	cout<<"a1*w1+a2*w2+a3*w3+...+an*wn\n";
	cout<<"---------------------------\n";
	cout<<"      w1+w2+w3+...+wn\n";
	cout<<"It is a quotient of the sum of the products of numbers and their weights and the sum of the weights\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=0;
	weightProduct=0;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		cout<<"Enter element weight: ";
		cin>>currentWeight;
		product+=currentNumber*currentWeight;
		weightProduct+=currentWeight;
	}
	result=product/weightProduct;
	cout<<"Weighted average of " <<numberOfElements<< " given elements equals " <<result<<endl;
}

void printAveragesMenu()
{
	system("cls");
	cout<<"MENU\n";
	cout<<"Choose average to compute:\n";
	cout<<"1 - Arythmetic average\n";
	cout<<"2 - Geometric average\n";
	cout<<"3 - Harmonic average\n";
	cout<<"4 - Square average\n";
	cout<<"5 - Power average\n";
	cout<<"6 - Weighted average\n";
	cout<<"0 - To stop the program\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	system("cls");
}

void averages()
{
	printAveragesMenu();
		switch(choice)
		{
			case 1:
			{
				arithmeticAverage();
				break;
			}
			case 2:
			{
				geometricAverage();
				break;
			}
			case 3:
			{
				harmonicAverage();
				break;
			}
			case 4:
			{
				squareAverage();
				break;
			}
			case 5:
			{
				powerAverage();
				break;
			}
			case 6:
			{
				weightedAverage();
				break;
			}
			case 0:
			{
				system("pause");
				break;
			}
		}
}

void factorialProgram()
{
	cout<<"8 - FACTORIAL\n";
	cout<<"Factorial form:\n";
	cout<<"F = 1*2*3*...*n\n";
	cout<<"Enter the number, you want to calculate factorial: ";
	cin>>numberToCalculate_Int;
	result=1;
	if(numberToCalculate_Int>=0)
	{
		for(i=1; i<=numberToCalculate_Int; i++)
			result=result*i;
		cout<<numberToCalculate_Int<< "! equals: " <<result<< endl;	
	}
	else
		cout<<"Factorial works only with non-negative numbers\n";
}

void floatPowerExponentiationProgram()
{
	cout<<"7 - FLOAT POWER EXPONENTIATION\n";
	cout<<"n-th degree square root of a number to the power of m\n";
	cout<<"Enter the number to exponentiate: ";
	cin>>numberToCalculate_Double;
	cout<<"Enter the square root degree: ";
	cin>>degreeValue_Double;
	cout<<"Enter the power value: ";
	cin>>powerValue_Double;
	if(degreeValue_Double<=0)
		cout<<"There exists no square root with negative degree\n";
	else
	{
		result=pow(numberToCalculate_Double, powerValue_Double/degreeValue_Double);
		cout<<numberToCalculate_Double<< " to the power " <<powerValue_Double<< " and square degree of "  <<degreeValue_Double<< " equals: " <<result<< endl;
	}
}

void integerRootSquareRootProgram()
{
	cout<<"6 - INTEGER ROOT SQUARE ROOT\n";
	cout<<"Enter the number to take root of: ";
	cin>>numberToCalculate_Double;
	cout<<"Enter the square root value: ";
	cin>>degreeValue_Int;
	if(numberToCalculate_Double<0 && degreeValue_Int%2==0)
		cout<<"Program does not compute imaginary numbers\n";
	else
		if(degreeValue_Int<=0)
			cout<<"There exists no square root with negative degree\n";
		else
		{
			result=pow(numberToCalculate_Double, 1.00/degreeValue_Int);
			cout<<"Square root of degree " <<degreeValue_Int<< " of a number " <<numberToCalculate_Double<< " equals: " <<result<<endl;
		}
}

void integerPowerExponentiationProgram()
{
	cout<<"5 - INTEGER POWER EXPONENTIATION\n";
	cout<<"Enter the number to exponentiate: ";
	cin>>numberToCalculate_Double;
	cout<<"Enter the power value: ";
	cin>>powerValue_Int;
	if(numberToCalculate_Double==0 && powerValue_Int<0)
		cout<<"Cannot divide by 0\n";
	else
	{
		result=pow(numberToCalculate_Double, powerValue_Int);
		cout<<numberToCalculate_Double<< " to the power " <<powerValue_Int<< " equals " <<result<< endl;
	}
}

void divisionProgram()
{
	cout<<"4 - DIVISION\n";
	cout<<"Enter the number to divide: ";
	cin>>numberToCalculate_Double;
	cout<<"Enter the number of elements to divide: ";
	cin>>numberOfElements;
	for(i=1; i<=numberOfElements; i++)
	{
		cout<<"To stop dividing, enter 0\n";
		cout<<"Enter " <<i<< ". number: ";
		cin>>currentNumber;
		if(currentNumber==0)
			i=numberOfElements;
		else
			numberToCalculate_Double/=currentNumber;
	}
	cout<<"Quotient of " <<numberOfElements+1<< " given numbers equals: " <<numberToCalculate_Double<< endl;
}

void multiplicationProgram()
{
	cout<<"3 - MULTIPLICATION\n";
	cout<<"Enter the number of elements to multiply: ";
	cin>>numberOfElements;
	result=1;
	for(i=1; i<=numberOfElements; i++)
	{
		cout<<"Enter " <<i<< ". number: ";
		cin>>currentNumber;
		result*=currentNumber;
	}
	cout<<"Product of " <<numberOfElements<< " given numbers equals: " <<result<< endl;
}

void subtractionProgram()
{
	cout<<"2 - SUBTRACTION\n";
	cout<<"Enter the number you want to subtract from: ";
	cin>>numberToCalculate_Double;
	cout<<"Enter number of elements to subtract: ";
	cin>>numberOfElements;
	for(i=1; i<=numberOfElements; i++)
	{
		cout<<"Enter " <<i<< ". number: ";
		cin>>currentNumber;
		numberToCalculate_Double-=currentNumber;
	}
	cout<<"The difference of " <<numberOfElements+1<< " given numbers equals: " <<numberToCalculate_Double<< endl;
}

void additionProgram()
{
	cout<<"1 - ADDITION\n";
	cout<<"Enter number of elements to add: ";
	cin>>numberOfElements;
	result=0;
	for(i=1; i<=numberOfElements; i++)
	{
		cout<<"Enter " <<i<< ". number: ";
		cin>>currentNumber;
		result+=currentNumber;
	}
	cout<<"Sum of " <<numberOfElements<< " given numbers equals: " <<result<< endl;
}

void printEntireMenu()
{
	system("cls");
	cout<<"CALCULATOR\n";
	cout<<"MENU:\n";
	cout<<"Choose action:\n";
	cout<<"1  - Addition\n";
	cout<<"2  - Subtraction\n";
	cout<<"3  - Multiplication\n";
	cout<<"4  - Division\n";
	cout<<"5  - Integer power exponentiation\n";
	cout<<"6  - Integer root square root\n";
	cout<<"7  - Float power exponentiation\n";
	cout<<"8  - Factorial\n";
	cout<<"9  - Averages\n";
	cout<<"10 - Percentages\n";
	cout<<"11 - Date difference\n";
	cout<<"0  - To stop the program\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	system("cls");
}

int main()
{
	cout<<setprecision(1000000);
	y=1;
	while(keepCalculating!=0)
	{
		printEntireMenu();
		switch(choice)
		{
			case 1:
			{
				additionProgram();
				break;
			}
			case 2:
			{
				subtractionProgram();
				break;
			}
			case 3:
			{
				multiplicationProgram();
				break;
			}
			case 4:
			{
				divisionProgram();
				break;
			}
			case 5:
			{
				integerPowerExponentiationProgram();
				break;
			}
			case 6:
			{
				integerRootSquareRootProgram();
				break;
			}
			case 7:
			{
				floatPowerExponentiationProgram();
				break;
			}
			case 8:
			{
				factorialProgram();
				break;
			}
			case 9:
			{
				averages();
				break;
			}
			case 10:
			{
				percentagesProgram();
				break;
			}
			case 11:
			{
				dateDifferenceProgram();
				break;
			}
			case 0:
			{
				system("pause");
				return 0;
				break;
			}
			default:
			{
				cout<<"Value not recognised";
				break;	
			}
		}
		cout<<"To select menu enter 1, to stop the program, enter 0: ";
		cin>>keepCalculating;
	}
	system("pause");
	return 0;
}
