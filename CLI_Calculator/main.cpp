#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//global variable declaration:
	
	int opr,resetAns;
	float numOne, numTwo, ans;
	float operation();
	void getData();
	void reset();

void reset(){
	cout << "Would you like to use me again?(0/1)";
	cin >> resetAns;
	if(resetAns == 1){getData();}
}


void getData(){
	cout << "Welcome to CLI-Based Calculator:\n\n\n\n\n";
	cout << "1 - Addition\n";
	cout << "2 - Subtraction\n";
	cout << "3 - Multiplication\n";
	cout << "4 - Division\n";
	cout << "Please Choose the Operation: ";
	cin >> opr;
	cout << "\nEnter The First Number: ";
	cin >> numOne;
	cout << "Enter the Second Number: ";
	cin >> numTwo;	
	//operation();
}	

float operation(int opr, float numOne,float numTwo){
	if(opr == 1){
	ans = numOne + numTwo;
	cout << "The Sum is " << ans << endl;
	}
	else if(opr == 2){
	ans = numOne - numTwo;
	cout << "The difference is " << ans;		
	}
	else if(opr == 3){
	ans = numOne * numTwo;
	cout << "The Product is " << ans;
	}
	else if (opr == 4){
	ans = numOne / numTwo;
	cout << "The Quotient is " << ans;		
	}
	else{
		cout << "\nPlease Enter a Valid Operand!\n\n\n\n\n";
		getData(); 
	}
}

int main() {
	getData();
	operation(opr, numOne, numTwo);
	reset();
	//cout << opr << numOne << numTwo;
	return 0;
}


