// CPPConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>		// Standard Input/Output Streams Library: Includes <string> library
#include <cstdlib>		// C Standard Library: Includes rand()
#include <ctime>		// C Time Library: Includes time()

using namespace std;


int output_arr_info(int a_arr[], int a_len) {

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

float gen_rand_nums(int a_count) {
	// Generate some random numbers, tracking the min, max, and mean values
	int r_count = a_count;
	int r_min = NULL, r_max = NULL, r_val = NULL;
	float r_sum = 0, r_avg = 0;

	// Display random numbers at an interval based upon
	// the number of random numbers being generated and in powers of 10
	int d_interval = (int)pow(10, round(log10(r_count)) - 1);

	cout << "Generating " << r_count << " Random Numbers ";
	cout << "(displayed every " << d_interval << " values): " << endl;

	// Initialize the random number generator with current time serial number as the seed
	srand(time(0));

	for (int k = 0; k < r_count; k++) {
		// Get a random number
		r_val = rand();

		// Store the minimum value
		if ((r_min == NULL) || (r_val < r_min)) r_min = r_val;

		// Store the maximum value
		if ((r_max == NULL) || (r_val > r_max)) r_max = r_val;

		// Keep a running sum to get the mean value later
		r_sum += (float)r_val;

		// Display the random number based upon the defined display interval
		if (k % d_interval == 0) {
			if (k > 0) cout << ", ";
			cout << r_val;
		}
	}
	cout << endl;

	r_avg = r_sum / (float)r_count;

	cout << "Statistics: Mean: " << r_avg << ", Min/Max: [" << r_min << ", " << r_max << "]" << endl;

	return r_avg;
}

int calc_fact(int a_n) {
	// DEBUG
	cout << a_n << ", ";

	// "Base Case": If argument is 1, just return 1 and halt the recursion
	if (a_n == 1) {
		return 1;
	}

	// Calculate a_n * factorial for a_n-1
	int val = a_n * calc_fact(a_n - 1);

	// Return the factorial result
	return val;
}



void gen_fib(int a_n) {
	// Ensure number of Fibonacci numbers being requested is >= 1
	int f_seq_num = a_n;
	if (f_seq_num < 1) f_seq_num = 1;

	// First 3 Fibonacci numbers are F0 = 0, F1 = 1
	int val_m2 = 0, val_m1 = 1;

	cout << "First " << f_seq_num << " Fibonnaci numbers starting with F1:" << endl;

	// Display F1, the first Fibonacci number
	cout << 1;

	// Display the second and higher f_num Fibonacci numbers
	int f_num = NULL;
	for (int i = 2; i <= f_seq_num; i++) {

		// Fibonacci number = sum of last 2 Fibonacci numbers
		f_num = val_m2 + val_m1;

		// Display this Fibonacci number
		cout << ", " << f_num;

		// Update the stored Fibonacci numbers
		val_m2 = val_m1;
		val_m1 = f_num;
	}

	// End the line of numbers
	cout << endl;

	return;
}

int main()
{
	// Output a start up message
	cout << "Let's calculate a sum of several values." << endl << endl;

	// An array of integers - Statically Allocated
	int arr[] = { 11, 22, 33, 44, 55 };

	// Find the number of elements in array arr 
	int arr_len = size(arr);

	// Statically Allocated Array
	cout << "Statically Allocated Array [ " << arr_len << " elements ]: ";

	// Use the function to display the list of all array elements on the same line, then the sum
	int f_sum = output_arr_info(arr, 5);

	// Blank line for spacing
	cout << endl << endl;


	// An array of integers - Dynamically Allocated

	// Size of the dynamically allocated array
	int arr_ptr_len = 5;

	// Pointer for the dynamically allocated array
	int* arr_ptr = NULL;

	// Allocate space to the array
	arr_ptr = new int[arr_ptr_len];

	// Initialize the dynamically allocated array
	for (int j = 0; j < arr_ptr_len; j++)
		arr_ptr[j] = 111 * (j + 1);

	// Dynamically Allocated Array
	cout << "Dynamically Allocated Array [ " << arr_ptr_len << " elements ]: ";

	// Use the function to display the list of all array elements on the same line, then the sum
	int f_sum_ptr = output_arr_info(arr_ptr, 5);

	// Delete the dynamically allocated array
	delete[] arr_ptr;

	// Blank line for spacing
	cout << endl << endl;

	// Generate some random numbers
	//float r_average = gen_rand_nums(10000000);

	// Generate some factorials
	int n_val = 4;
	int f_val = calc_fact(n_val);
	cout << "Factorial " << n_val << "! = " << f_val << endl;

	// Blank line for spacing
	cout << endl << endl;

	// Generate some Fibonacci numbers
	gen_fib(15);


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
