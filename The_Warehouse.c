/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */


#include "The_Wharehouse_header.h"



/* TASK 1
Find the difference between the total number of seconds, to simulate absolute value use an if statement to  assure the
answer is a positive integer
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int totalSecs;
	totalSecs = (((minuteA*60)+secondA)- ((minuteB*60)+secondB));
	if (totalSecs < 0 ){
		totalSecs = (totalSecs*(-1));
	}
	return totalSecs;
}

/* TASK 2
Starting from the upper bound of the street, check if the number  prime, whilst numbers aren't prime descend in 
increments of 1 down from the upper bound until prime conditions met
*/
int WarehouseAddress(int maximum)
{	
	int j = maximum-1;
	int prime = -1;
	int i = 2;
	int count =0;

	for ((j = maximum-1); j>= 2; j--){
		for (i =2; i <= (j/2); i++){
			if ( (j % i) == 0){
				count++;
			}
		}
		if (count == 0){
			return prime = j;
		} else{
			count = 0;
		}
	}
	return prime;
}

/* TASK 3
Scan the array of chars 'words' (to find the size), then replace every letter with the one infront
of it and put the first letter in the last non '\0' spot 
*/
void Advertise(char *words)
{
	int i = 0;
	char temp = words[0];

	while (words[i] != '\0'){ 
		i++;
	}

	for ( int j =0; j< (i-1); j++){
		words[j] = words[j+1];
	} 

	words[i-1] = temp;
}

/* TASK 4
Implement Bubble sort algorithm in function 'Bubble' which sorts and array of numbers in order of smallest to 
biggest which is called in the 'Sort' function which scans and passes values to the 'Bubble' function this is 
called in 'WinningBid' function which then isolates the smallest individual number (i.e numbers on either side of
the number isn't the same)
*/
void Bubble(int *values, int length)
{
	int i, temp;
	for (i = 0; i < length-1; i++) {
 		if (values[i] > values[i+1]) {
      		temp = values[i];
			values[i] = values[i+1];
			values[i+1] = temp;
		}
	}
}
void Sort(int *values, int length)
{
  int i;
  for (i = 0; i < length; i++) {
    Bubble(values, length);
  }
} 
int WinningBid(int *values, int length)
{
	int temp, j;
	int count = 1;
	int k = 1;
	int WINNER = -1;

	Sort(values,length);
	if (length == 1){
		WINNER = values[0];

	} else if (values[0] == values[length-1]) {
		WINNER = -1;

	} else if (values[0]<values[1]) {
		WINNER = values[0];
		
	} else {
		while (count > 0 && (k <= length-1)){
	
			if ((values[k] != values[k-1]) && (values[k] != values[k+1])){
				WINNER = values[k];
				count = 0;
				
			} else {
			count ++;
			k++;
			WINNER = -1;
			}
		}
	}

	return WINNER;
}

/* TASK 5
 A nested for loop is used for both the top and bottom widths of the box and the  box is ended with with 
 \n\0. To make the mid section of the box a series of nested if conditions are used to determine which indexes
 of character array 'design' the perimiter of the box should go in. To put the crosses in the middle I used a 
 series of if conditions (for the odd-even length variations) to determine the exact location of the crosses.
*/
void BoxDesign(char *design, int width, int height)
{	 

	int n = 1;
	int k = 0;
	int i = (width +1);
	int j =2;
	int x = 2;
	int a = 0;

	for (int i = 0; i<=(width); i++){
		if (i<= (width-1)){
			design[i] = '*';
		} else {
			design[i] = '\n';
		}
	}

	while (i<=((width+1)*(height-1))){
		if (i == ((width+1)*n)){
			design[i] = '*';
			n++;
		
		} else if (i % ((j*width)+k) == 0){
			design[i] = '*';
			k++;
			j++;

		} else if ( i % ((width*x)+(x-1)) == 0){
			design[i] = '\n';
			x++;

		}else {
			design[i] = ' ';
		}
		i++;
	}
 
	for (int i = ((width+1)*(height-1)+1); i<((width+1)*(height)); i++){
		if (i != (((width+1)*(height))-1)){
			design[i] = '*';
		} else if (i == (((width+1)*(height))-1)){
			design[i] = '\n';
		} else {
			design[i] = '\0';
		}
	}

	if ((width >2) && (height>2)){
		
		if ( width % 2 == 0 && height % 2 == 0){
			design[((strlen(design)-2)/2)- (width/2)-1] = 'X';
			design[((strlen(design)-2)/2)- (width/2)] = 'X';
			design[((strlen(design)-2)/2)+ (width/2)+1] = 'X';
			design[((strlen(design)-2)/2)+ (width/2)] = 'X';
			
		} else if ( width % 2 != 0 && height % 2 == 0){
			design[((strlen(design)-2)/2)+ ((width/2)+1)] = 'X';
			design[((strlen(design)-2)/2)- ((width/2)+1)] = 'X'; 

		} else if ( width % 2 == 0 && height % 2 != 0){
			int a = (((width+1)*height)/2);
			design[a]= 'X';
			design[a-1]= 'X';
		
		} else if (height && width != 1){
			design[(((width*width)/2) +(width/2))]= 'X';
		}
	}
}
/* TASK 6
WorkerRoute implements FindTile from Lab 9 as a helper function to scan the array and the find the location (row & col)
of the desired tile and points to its location which is then used in WorkerRoute. The body of WorkerRoute is a series
of if statements which determine where the worker is '1' relative to the box '2' and then each if statement will have a
while loop to draw the path (notated with values of 3 in the array) between the box and worker. The worker must move
horizontally before vertically so the inital if statements dictate horizontal movement, followed by vertical.
*/
void FindTile(int board[10][10], int tile, int *rowPos, int *colPos)
{
	int i, j;
	for(i = 0;i <10;i++){

		for(j = 0;j < 10 ;j++){

			if (board[i][j]== tile){
				*rowPos = i;
				*colPos = j;
			}
		}
	}
}
void WorkerRoute(int warehouse[10][10])
{
	int row_1, col_1, row_2, col_2;

	FindTile(warehouse, 1, &row_1, &col_1);
	FindTile(warehouse, 2, &row_2, &col_2);

	int a = row_1;
	int b = row_2;
	if (col_1 == col_2 ){
		while ( (a+1) <b ){
			warehouse[a+1][col_2] = 3;
			a++;
		}
	}

	int i = col_1;
	int j = col_2;
	if (col_2> col_1 && row_1 != row_2){
		while ( i <j ){
			warehouse[row_1][i+1] = 3;
			i++;
		}
	} else if (col_1> col_2 && row_1 != row_2){
		while ( i>j ){
			warehouse[row_1][i-1] = 3;
			i--;
		}
	} else if (col_2> col_1 && row_1 == row_2){
		while ( i < j-1 ){
			warehouse[row_1][i+1] = 3;
			i++;
		}
	} else if (col_1> col_2 && row_1 == row_2){
		while ( j+1< i ){
			warehouse[row_1][j+1] = 3;
			j++;
		}
	}

	int k = row_1;
	int f = row_2;
	if (row_1 > row_2){
		while ( (f+1) < k ){
			warehouse[k-1][col_2] = 3;
			k--;
		}
	} else if (row_2> row_1){
		while ( k<(f-1) ){
			warehouse[k+1][col_2] = 3;
			k++;
		}
	}
}

/* TASK 7 
Using the earlier defined 'FindTile' function and a newly defined funtion 'rotateBoard' locate 
the row & col of the worker (5) in the rotated board then using a series of if statements determine 
which direction player wants to move and check if the element is either a wall not.

TASK 8 
Developing on task 7, task 8 adds a box which can be moved by the worker, task 8 is a series of if 
conditions which check what is infront of the worker and what is infront of the box and also when the
box is moved, whats goes where the worker was...

TASK 9
Further developing from task 7 & 8, task 9 adds multiple boxes to the warehouse. I developed the 
task 8 if statements to determine whether the box can be moved or not.

TASK 10
Finally, task 10 combines all of 7-9 and adds targets... There are two main groups of statements, the
statements for when the location of the worker is on a target and when he is not. When the boxes are
on targets (which is the objective of the game) and the worker is on a target, I use a nested for loop to
see if there are any uncovered targets.
*/
void rotateBoard( int Array[10][10], int Rots)
{
	int i, j; 
	int f = 1;
	int temp[10][10];

	// rotate the board required number of times
	while (f <= Rots ){
		
		// scan initial array into temporary array
    	for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
		    	temp[i][j] = Array[i][j];
			}
    	}
		// rotate array 90º CW
		for (i=0; i<10; i++){
			for (j=0; j<10; j++){
				Array[j][9-i] = temp[i][j];
			}
		}
		f++;
	}	
}

int MakeMove(int warehouse[10][10], char move)
{
	int rowWorker, colWorker, k, h;
	int rowTW = 0;
	int colTW = 0;

	// determine number of rotations necessary to orientate the board 
	if ( move == 'd'){
		k = 3;
		h = 1;
	} else if ( move == 's'){
		k = 2;
		h = 2;
	} else if ( move == 'a'){
		k = 1;
		h = 3;
	} else if ( move == 'w'){
		k = 0;
		h = 0;
	}

	rotateBoard(warehouse, k);

	for( int i = 0;i <10;i++){
		for( int j = 0;j < 10 ;j++){
			if (warehouse[i][j]== WORKER){
				FindTile(warehouse, WORKER, &rowWorker, &colWorker);
			} else {
				FindTile(warehouse, WORKER_ON_TARGET, &rowWorker, &colWorker);
			}
		}
	}

	if (warehouse[rowWorker-1][colWorker] == WALL){
		warehouse[rowWorker][colWorker] = WORKER;

	} else if (warehouse[rowWorker][colWorker] == WORKER_ON_TARGET){ 

		if ((warehouse[rowWorker-1][colWorker] == BOX) && (warehouse[rowWorker - 2][colWorker] != WALL)){
			
			if (warehouse[rowWorker-2][colWorker] == BOX){
				warehouse[rowWorker -1][colWorker] = BOX;
				warehouse[rowWorker][colWorker] = WORKER_ON_TARGET;
			} else if (warehouse[rowWorker-2][colWorker] == TARGET){
				warehouse[rowWorker-2][colWorker] = BOX_ON_TARGET;
				warehouse[rowWorker - 1][colWorker] = WORKER;
				warehouse[rowWorker][colWorker] = TARGET;
			}else {
				warehouse[rowWorker-2][colWorker] = BOX;
				warehouse[rowWorker - 1][colWorker] = WORKER;
				warehouse[rowWorker][colWorker] = TARGET;
			}

		} else if (warehouse[rowWorker-1][colWorker] != BOX){

			if (warehouse[rowWorker-1][colWorker] == TARGET ){
				warehouse[rowWorker-1][colWorker] = WORKER_ON_TARGET;
				warehouse[rowWorker][colWorker] = TARGET;
			
			} else if (warehouse[rowWorker-1][colWorker] == BOX_ON_TARGET){
				if (warehouse[rowWorker-2][colWorker] == BOX_ON_TARGET || warehouse[rowWorker-2][colWorker] == BOX){
					warehouse[rowWorker][colWorker] = WORKER;
				} else {
					warehouse[rowWorker-2][colWorker] = BOX;
					warehouse[rowWorker-1][colWorker] = WORKER_ON_TARGET;
					warehouse[rowWorker][colWorker] = TARGET;
				}

			} else {
				warehouse[rowWorker-1][colWorker] = WORKER;
				warehouse[rowWorker][colWorker] = TARGET;
			}
		}

	} else if (warehouse[rowWorker][colWorker] == WORKER) {

		if ((warehouse[rowWorker-1][colWorker] == BOX) && (warehouse[rowWorker - 2][colWorker] != WALL)){
			
			if (warehouse[rowWorker-2][colWorker] == BOX || warehouse[rowWorker-2][colWorker] == BOX_ON_TARGET){
				warehouse[rowWorker -1][colWorker] = BOX;
				warehouse[rowWorker][colWorker] = WORKER;
			} else if (warehouse[rowWorker-2][colWorker] == TARGET){
				warehouse[rowWorker-2][colWorker] = BOX_ON_TARGET;
				warehouse[rowWorker - 1][colWorker] = WORKER;
				warehouse[rowWorker][colWorker] = SPACE;
			}else {
				warehouse[rowWorker-2][colWorker] = BOX;
				warehouse[rowWorker - 1][colWorker] = WORKER;
				warehouse[rowWorker][colWorker] = SPACE;
			}

		} else if (warehouse[rowWorker-1][colWorker] != BOX){

			if (warehouse[rowWorker-1][colWorker] == TARGET ){
				warehouse[rowWorker-1][colWorker] = WORKER_ON_TARGET;
				warehouse[rowWorker][colWorker] = SPACE;
			
			} else if (warehouse[rowWorker-1][colWorker] == BOX_ON_TARGET){
				if (warehouse[rowWorker-2][colWorker] == BOX_ON_TARGET || warehouse[rowWorker-2][colWorker] == BOX){
					warehouse[rowWorker][colWorker] = WORKER;
				} else {
					warehouse[rowWorker-2][colWorker] = BOX;
					warehouse[rowWorker-1][colWorker] = WORKER_ON_TARGET;
					warehouse[rowWorker][colWorker] = SPACE;
				}

			} else {
				warehouse[rowWorker-1][colWorker] = WORKER;
				warehouse[rowWorker][colWorker] = SPACE;
			}
		}
	}
	rotateBoard(warehouse, h);

	int count;
	for( int i = 0;i <10;i++){
		for( int j = 0;j < 10 ;j++){
			if (warehouse[i][j]== WORKER || warehouse[i][j]== BOX ){
				count ++;
			} 
			
		}
	}

	if (count ==0){
		return 1;
	} else{
		return 0;
	}
}
