//include any standard libraries needed


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line

   // open file and verify it opened

   // Declare an array of doubles of size ARR_CAP.

    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.

    
   // Call the mean function passing it this array and output the 
   // value returned.
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.

	
   // Call the display function to output the array.

   
   // Call the remove function to remove the value at the index
   // provided by the user.
  
    
   // Call the display function again to output the array
   // with the value removed.

   
   // Call the mean function again to get the new mean

   
	return 0;
}