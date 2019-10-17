// CPPConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>		// Standard Input/Output Streams Library: Includes <string> library
#include <cstdlib>		// C Standard Library: Includes rand()
#include <ctime>		// C Time Library: Includes time()
#include <fstream>		// File Input/Output Streams LIbrary: ofstream (w), ifstream (r), fstream (r/w)
#include <string>		// String Library: Includes getline()
#include <stdlib.h>		// Standard Library with Memory Management functions: malloc(), calloc(), realloc(), free()
#include <Windows.h>	// Windows Library: sleep()

#include "MyClass.h"	// User defined class with some useful content

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
	srand((unsigned int)time(0));

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

void try_class_stuff() {

	// Regular object
	cout << "Regular Object (2 arguments): [obj]" << endl;
	MyClass obj(5, 10);
	obj.myPrint();
	cout << endl;

	//MyClass* ptr = &obj;
	//ptr->myPrint();
	//cout << endl;

	cout << "Regular Object (1 argument): [next_obj]" << endl;
	MyClass next_obj(99);
	next_obj.myPrint();
	cout << endl;

	// Add 2 objects
	cout << "Adding 2 objects (overloaded operator: [+]" << endl;
	cout << "Regular Object: [result_obj = obj + next_obj]" << endl;
	MyClass result_obj = obj + next_obj;
	result_obj.myPrint();
	cout << endl;

	// Constant object
	//cout << "Constant Object (No arguments): [const_obj]" << endl;
	//const MyClass const_obj;

	//const_obj.myPrint();
	cout << endl;
}

void tryfunctemp()
{
	// Use a function template to add 2 values of various data types
	int a = 55, b = 44;
	int sum_int = 0;
	sum_int = sum(a, b);

	cout << "Adding 2 values (function template: [sum])" << endl;
	cout << "[" << a << "] + [" << b << "] = [" << sum_int << "]" << endl;

	cout << endl;

	// Use a function template to add 2 values of various data types
	float c = (float)55.5, d = (float)44.4;
	float sum_float = (float)0.0;
	sum_float = sum(c, d);

	cout << "Adding 2 values (function template: [sum])" << endl;
	cout << "[" << c << "] + [" << d << "] = [" << sum_float << "]" << endl;

	cout << endl;

	// Use a class template of various data types
	int e = 5, f = 4;
	Pair<int> obj_int(e, f);

	cout << "Bigger of 2 numbers (class template: [Pair<int>])" << endl;
	cout << "[" << e << "] " << (e > f ? ">" : "<=") << " [" << f << "] = [" << obj_int.bigger() << "]" << endl;
	cout << endl;

	// Use a class template of various data types
	float g = (float)555.55, h = (float)444.44;
	Pair<float> obj_float(g, h);

	cout << "Bigger of 2 numbers (class template: [Pair<float>])" << endl;
	cout << "[" << g << "] " << (g > h ? ">" : "<=") << " [" << h << "] = [" << obj_float.bigger() << "]" << endl;
	cout << endl;
}

void tryfilestuff() {
	// Open a file for writing
	ofstream MyFile;
	MyFile.open("test.txt");
	if (MyFile.is_open()) {
		cout << "Good News: File is open." << endl;
		MyFile << "Some text." << endl;
		MyFile.close();
	}
	else {
		cout << "A Problem: File didn't open." << endl;
	}

	// Specify the file path using the constructor
	ofstream MyFile2("test.txt", ios::app);
	if (MyFile2.is_open()) {
		cout << "Good News: File is open." << endl;
		MyFile2 << "This is awesome!\n" << endl;
		MyFile2.close();
	}
	else {
		cout << "A Problem: File didn't open." << endl;
	}


	// Read from a file
	ifstream MyFile3("test.txt");
	string line;

	if (MyFile3.is_open()) {
		cout << "Good News: File is open for reading." << endl;

		// Loop through all the lines in the file
		while (getline(MyFile3, line)) {
			cout << line << endl;
		}
		MyFile3.close();
	}
	else {
		cout << "A Problem: File didn't open for reading." << endl;
	}


}

int test_func(char* a_str) {
	return (int)strlen(a_str);
}

void trysomeCstuff() {
	// Structure and Strings ******************************************************
	struct MyStruct test_struct;
	test_struct.a = 1;
	test_struct.b = 3.14159;
	strncpy_s(test_struct.c, "Hello, there", 29);

	struct MyStruct another_struct = { 2, 6.28, "Quick Check" };

	printf("Trying Some C Stuff\n\n");
	const char* PROMPT_STR[] = { ", the values are ", " and " };

	printf("Use a Structure: [MyStruct] with manually assignment\n");
	printf("%s%s%d%s%.4f\n\n", test_struct.c, PROMPT_STR[0], test_struct.a, PROMPT_STR[1], test_struct.b);

	printf("Use a Structure: [MyStruct] with initialized values\n");
	printf("%s%s%d%s%.4f\n\n", another_struct.c, PROMPT_STR[0], another_struct.a, PROMPT_STR[1], another_struct.b);

	// Typedef
	MyTestType another_type = { 3, 9.42, "Type Check" };

	printf("Use a Typedef: [MyTestType] with initialized values\n");
	printf("%s%s%d%s%.4f\n\n", another_type.c, PROMPT_STR[0], another_type.a, PROMPT_STR[1], another_type.b);

	// Function Pointers **********************************************************
	int (*ptr_to_func)(char*);		// Pointer to a function
	const char* test_string = "This is a test string";	// Test string
	int ts_len;

	// Assign the address of test_func() to the pointer
	ptr_to_func = test_func;

	// Call the function with the test string
	ts_len = ptr_to_func((char*)test_string);

	// Display the results
	printf("Use a Pointer to FUnction: [ptr_to_func] pointing to [test_func]\n");
	printf("String: [%s], String Length: [%d]\n\n", test_string, ts_len);

	// Void Pointer **********************************************************
	int abc_int = 88;
	double def_double = 99.0;
	const char* ghi_string = "String for testing a void pointer";

	void* v_ptr;		// void pointer - can point to any type of value in memory

	// Pointer to int
	v_ptr = &abc_int;
	printf("Using a void Pointer: [v_ptr] pointing to [abc_int] = ");
	printf("Value: [%d]\n", *((int*)v_ptr));

	// Pointer to double
	v_ptr = &def_double;
	printf("Using a void Pointer: [v_ptr] pointing to [def_double] = ");
	printf("Value: [%.2f]\n", *((double*)v_ptr));

	// Pointer to int
	v_ptr = (char*)ghi_string;
	printf("Using a void Pointer: [v_ptr] pointing to [ghi_string] = ");
	printf("Value: [%s]\n\n", (char*)v_ptr);

	// Memory Management
	printf("Memory Management\n");

	// Allocate memory for a block of values
	int* ptr;	// A pointer to a block of int values
	int n_blocks = (int)pow(10.0, 8);	// Number of blocks to allocate

	printf("Allocating memory: Using [malloc()] to allocated [%d blocks] for [%d total bytes] = ",
		(int)n_blocks, (int)(n_blocks * sizeof(*ptr)));

	// Allocate memory
	ptr = (int*)malloc(n_blocks * sizeof(*ptr));

	// Check for return status
	if (ptr != NULL) {
		printf("Result: Memory Allocated\n\n");
	}
	else {
		printf("Result: Memory NOT Allocated\n\n");
	}

	// Free up the allocated memory (after waiting a few seconds)
	int n_waitsecs = 0;

	printf("Waiting %d seconds... ", n_waitsecs);
	Sleep((DWORD)(n_waitsecs * 1000));
	free(ptr);
	printf("memory now freed.\n\n");

	// File I/O
	printf("Reading and Writing Files with C\n");

	// Write to a file
	FILE* f_ptr;

	const char* f_name = "test.txt";

	// Open file for writing
	printf("Opening a file [%s] for writing = ", f_name);

	int retval = fopen_s(&f_ptr, f_name, "w");
	if (retval != 0) {
		printf("Result: Error opening file.\n");
	}
	else {
		printf("Result: File opened for writing.\n");
	}

	// Write content to the file
	int w_count = 10;
	for (int j=1; j <= w_count; j++) {
		fprintf(f_ptr, "This is line %d written using the `fprintf` function.\n", j);
	}

	// Close the file
	fclose(f_ptr);

	// Read content from the file
	char i_buf[300];	// An input buffer

	printf("Opening a file [%s] for reading = ", f_name);

	retval = fopen_s(&f_ptr, f_name, "r");
	if (retval != 0) {
		printf("Result: Error opening file.\n");
	}
	else {
		printf("Result: File opened for reading.\n");
	}

	// Read and print each line with a line number until the end of file is reached
	int i_line = 1;
	while ( fgets(i_buf, sizeof(i_buf)-1, f_ptr) != NULL ) {
		printf("[Line %d]:%s", i_line++, i_buf);
	}

	printf("\n\n");

	// Close the file
	fclose(f_ptr);

	// Various C Preprecessor directives

	// List of directives
	//	#include Including header files.
	//	#define, #undef Defining and undefining macros.
	//	#ifdef, #ifndef, #if, #else, #elif, #endif Conditional compilation.
	//	#pragma Implementation and compiler specific.
	//	#error, #warning Output an error or warning message An error halts compilation.

	printf("Using C Preprocessor Directives\n");

	printf("%s %s\n", __TIME__, __DATE__);

	printf("__cplusplus is %d\n", __cplusplus);
	printf("__STDCPP_THREADS__ is %d\n\n", __STDCPP_THREADS__);

	printf("Function name: %s\n", __FUNCTION__);
	printf("Decorated function name: %s\n", __FUNCDNAME__);
	printf("Function signature: %s\n", __FUNCSIG__);
	printf("This is line %d\n\n", __LINE__);
}

int main()
{
	// Output a start up message
	cout << "Let's calculate a sum of several values." << endl << endl;

	// An array of integers - Statically Allocated
	int arr[] = { 11, 22, 33, 44, 55 };

	// Find the number of elements in array arr 
	int arr_len = (int)size(arr);

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


	// Try some class stuff
	try_class_stuff();

	// Try some function template stuff
	tryfunctemp();

	// Try some file stuff
	tryfilestuff();

	// Try some plain old C stuff
	trysomeCstuff();

	// Exit
	exit(EXIT_SUCCESS);
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
