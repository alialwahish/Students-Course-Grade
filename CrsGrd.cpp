// Name: Ali Bayati 
// Course Grade  

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


struct stud
{
	string name;
	int tests;
	int studid;
	int *degtst;
};

void printit(stud, int);

int main()
{
	stud *sp;
	int hmtd, nstd;
	cout << "Enter Number of Tests :";
	cin >> hmtd;

	cout << "Enter Number of Students :";
	cin >> nstd;

	sp = new stud[nstd];


	for (int i = 0; i < nstd; i++)
	{
		cout << "Enter Student Id:";
		cin >> sp[i].studid;
		cin.ignore();
		cout << "Enter Student Name:";
		getline(cin, sp[i].name);
		  
		sp[i].degtst = new int[hmtd];
		for (int j = 0; j < hmtd; j++)
		{
			cout << "Enter Test Score #" << j + 1 << ":";
			cin >> sp[i].degtst[j];
			
		}

	}
	cout << endl ;
	for (int p = 0; p < nstd; p++)
		printit(sp[p], hmtd);
	delete[] sp;
	return 0;
}

void printit(stud sp, int tests)
{
	
	int i;
	float  avg, tot = 0;
	char grade;
	cout << "Student ID:    " << sp.studid << endl;
	cout << "Student Name:  " << sp.name << endl;
	cout << "Test #         Score" << endl;

	for (i = 0; i < tests; i++)
	{
		cout << "  " << i + 1 << "            " << sp.degtst[i] << endl;
		tot = tot + sp.degtst[i];
	}
	avg =   tot / tests;
	cout << fixed << setprecision(1);
	cout << "Average:       " <<  avg << endl;
	if (avg > 90 && avg <= 100)
	{
		grade = 'A';
	}
	else if (avg > 80 && avg <= 90)
	{
		grade = 'B';

	}
	else if (avg > 70 && avg <= 80)
	{
		grade = 'C';
	}
	else if (avg > 60 && avg <= 70)
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}
	cout << "Grade:         " << grade << endl << endl;
}
/*Output
Enter Number of Tests :2
Enter Number of Students :2
Enter Student Id:111
Enter Student Name:Ali
Enter Test Score #1:88
Enter Test Score #2:98
Enter Student Id:222
Enter Student Name:Safaa
Enter Test Score #1:88
Enter Test Score #2:77

Student ID:    111
Student Name:  Ali
Test #         Score
1            88
2            98
Average:       93.0
Grade:         A

Student ID:    222
Student Name:  Safaa
Test #         Score
1            88
2            77
Average:       82.5
Grade:         B

Press any key to continue . . .*/