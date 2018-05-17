
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int AR_SIZE = 200000;								// The size of the array -- Global constant


/*
 * 		This function will read in a *.dat file and store its contents into an array.
 * 		Returns: 	True if the file opened correctly.
 */
bool	readFile(int*);

/*
 * 		This function performs a bubble sort on the given array.
 * 		Returns: 	Nothing
 */
void BubbleSort(int*);

/*
 * 		This function writes the entire array to a text file.  The parameter 'crtlSwtch' will determine which file
 * 		will be written to.
 * 		Returns:	True if the file opened correctly.
 */
bool writeArrayToFile(int, int*);

/*
 * 		This function declares a external procedure that is defined in an assembly file.  The procedure performs
 * 		a bubble sort on the given array.
 * 		Returns:	Nothing
 */
extern "C" {int BubbleSort1(int*, const int);}

#endif /* HEADER_H_ */
