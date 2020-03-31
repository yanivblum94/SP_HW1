#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "SPBufferset.h"


static int numcol,numrow;

int main(int argc, char* argv[])
{
	//FILE* inputf = fopen(argv[1], 'r');
	char *inputfname = argv[1];
	char *outputfname = argv[2];
	FILE* outf;
	int numcol, numrow;
	double matrix[][], cov[][];
	int arr[2];
	int n;
	double d;
	matrix = readmat(*inputfname,*outputfname);
	subtractmean(matrix);
}

double * readmat(*inputfname, *outputfname){
	    FILE* inputf = fopen(*inputfname, 'r');
		/*int numcol, numrow;*/
		double matrix[][];
		int arr[2];
		int n;
		double d;
		n = fread(arr, sizeof(int), 2, inputf);
		assert(n == 2);
		numcol = arr[0];
		numrow = arr[1];
		for(int i = 0; i < numrow; i++){
			for(int j = 0; j < numcol; j++){
				n = fread(d, sizeof(double), 1, inputf);
				assert(n == 1);
				matrix[i][j] = d;
			}
		}
	return matrix;
}

void subtractmean(double matrix[][]){
	double meanarr[numrow];
	int sum;
	for(int i=0; i<numrow; i++){
		sum=0;
		for(int j=0; j<numcol; j++){
			sum+= matrix[i][j];
		}
		meanarr[i] = sum/numrow;
	}
	for(int a=0; a<numrow; a++){
		for(int b=0; b<numcol; b++){
			matrix[a][b] = matrix[a][b] - meanarr[a];
		}
	}
}

double * calculatecov(double matrix[][])
{

	return 0.0;
}
