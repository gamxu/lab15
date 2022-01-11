#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double A[][N]){
	for(int i=0;i<N;i++){
		cout << "Row "<< i+1 << ": ";
		cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3] >> A[i][4];
	}
}

void findLocalMax(const double A[][N], bool B[][N]){
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			int val = A[x][y];
			if(x==0||y==0||x==4||y==4) B[x][y] = 0;
			else if(val>=A[x-1][y]&&val>=A[x+1][y]&&val>=A[x][y-1]&&val>=A[x][y+1]) B[x][y] = 1;
			else B[x][y] = 0;
		}	
	}
}

void showMatrix(const bool B[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << B[i][j] << " ";
		}
		cout << "\n";
	}
}