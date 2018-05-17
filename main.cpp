#include "header.h"

int main() {
	int 	numAr[AR_SIZE] = { };									//Declare an array of size AR_SIZE and initialize with all 0's
	int 	crtlSwtch = 0;
	time_t 	start, end;
	double	tElapsed = 0;

	//C++ SORT AND TIMES
	cout << "\t\t\tSORTING WARS\n\n";
	readFile(numAr);												//Read data into the array
	cout << "Sorting via C++ .......................\n";
	time(&start);
	BubbleSort(numAr);												//Call C++ bubble sort0.21354
	time(&end);

	tElapsed	=	difftime(end, start);
	cout << "C++ sort finished in " << tElapsed << " seconds.\n";

	writeArrayToFile(crtlSwtch, numAr);

	crtlSwtch++;													//increment crtlSwtch

	//ASSEMBLY SORT AND TIMES
	readFile(numAr);												//Read data into the array
	cout << "\nSorting via Assembly ..................\n";
	time(&start);
	BubbleSort1(numAr, AR_SIZE);									//Call assembly bubble sort
	time(&end);

	tElapsed	=	difftime(end, start);
	cout << "Assembly sort finished in " << tElapsed << " seconds.\n";

	writeArrayToFile(crtlSwtch, numAr);

	return 0;
}


bool readFile(int* array) {
	int temp = 0;
	ifstream ifile;

	ifile.open("masm5.dat");

	if (!ifile.is_open())
		return false;

	for (int i = 0; i <= AR_SIZE; i++) {
		ifile >> temp;
		array[i] = temp;
	}

	ifile.close();
	return true;
}


void BubbleSort(int* array) {
	int temp 	= 	0;
	int cx1 	= 	(AR_SIZE - 1);
	int cx2		=	0;
	int i		=	0;

	while(cx1 > 0) {
		cx2	=	cx1;
		i	=	0;
		while(cx2 > 0) {
			temp	=	array[i];
			if(temp > array[i+1]) {
				array[i]	=	array[i+1];
				array[i+1]	=	temp;
			}
			i++;
			cx2--;
		}
		cx1--;
	}
}


bool writeArrayToFile(int crtlSwtch, int* array) {
	ofstream ofile;

	if(crtlSwtch == 0) {
		ofile.open("sortedCPP.txt");
	} else {
		ofile.open("sortedAssembly.txt");
	}

	if(!ofile.is_open())
		return false;

	for (int i = 0; i <= AR_SIZE; i++) {
		ofile << array[i] << " ";
	}

	ofile.close();
	return true;
}
