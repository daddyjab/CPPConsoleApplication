// CPPConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// #include <string>  -- no need to include <string> explicitly, since already in <iostream> library
using namespace std;


int output_arr_info(int* a_arr, int a_len) {

	// Start the line containing the list of array elements
	cout << "{ ";

	// Initial the array sum to 0
	int x_sum = 0;

	// Loop through all elements in the array arr
	for (int i = 0; i < a_len; i++) {

		// If this is not the first element, add a separator
		if (i > 0) cout << ", ";

		// Output the value of the array element
		cout << a_arr[i];

		// Accumulate the sum
		x_sum += a_arr[i];
	}

	// End the line containing the list of array elements
	cout << " }" << endl;

	// Display the sum
	cout << "Sum of array elements: " << x_sum << endl;

	return x_sum;
}


int main()
{
	// An array of integers - static allocation
	int arr[] = { 11, 22, 33, 44, 55 };

	// Output a start up message
    std::cout << "Let's calculate a sum of several values." << endl;
	
	// Find the number of elements in array arr
	int arr_len = size(arr);

	// Display the list of all array elements on the same line, then the sum
	cout << "Statically Allocated Array [ " << arr_len << " elements ]: {";

	// Initial the array sum to 0
	int arr_sum = 0;

	// Loop through all elements in the array arr
	for (int i = 0; i < arr_len; i++) {

		// If this is not the first element, add a separator
		if (i > 0) cout << ", ";

		// Output the value of the array element
		cout << arr[i];

		// Accumulate the sum
		arr_sum += arr[i];
	}

	// End the line containing the list of array elements
	cout << "}" << endl;

	// Display the sum
	cout << "Sum of array elements: " << arr_sum << endl;

	// Try the function
	cout << "Function does this:" << endl;
	int f_sum = output_arr_info(arr, 5);



	/*********************************************************************************************************/

	// An array of integers - dynamically allocated
	int *arr_ptr = NULL;
	arr_ptr = new int[5];

	// Size of the dynamically allocated array
	int arr_ptr_len = 5;
	//int arr_ptr_len = sizeof(*arr_ptr) / sizeof(arr_ptr[0]);
	//cout << "sizeof(*arr_ptr) [" << sizeof(*arr_ptr) << "]" << endl;
	//cout << "sizeof(arr_ptr[0]) [" << sizeof(arr_ptr[0]) << "]" << endl;

	// Initialize the dynamically allocated array
	for (int j = 0; j < arr_ptr_len; j++)
		arr_ptr[j] = 111 * (j + 1);

	// Display the list of all array elements on the same line, then the sum
	cout << "Dynamically Allocated Array [ " << arr_ptr_len << " elements ]: ";

	// Initial the array sum to 0
	int arr_ptr_sum = 0;

	// Loop through all elements in the array arr
	for (int i = 0; i < arr_ptr_len; i++) {

		// If this is not the first element, add a separator
		if (i > 0) cout << ", ";

		// Output the value of the array element
		cout << arr_ptr[i];

		// Accumulate the sum
		arr_ptr_sum += arr_ptr[i];
	}

	// End the line containing the list of array elements
	cout << "}" << endl;

	// Display the sum
	cout << "Sum of array elements: " << arr_ptr_sum << endl;

	// Try the function
	cout << "Function does this:" << endl;
	int f_sum_ptr = output_arr_info(arr_ptr, 5);

	// Delete the dynamically allocated array
	delete [] arr_ptr;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
