/*
	#include<iostream>
using namespace std;

int main() {
    int num1, num2, temp;

    cout << "Enter two numbers: \n";
    cin >> num1 >> num2;

    if(num1>num2){
    	
    	
    for (int i = num1; i <= num2; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            cout << "Number divisible by 3 or 5 are " << i << endl;
        }
    }
}
else if(num1<num2){

    	
	
	 
        temp = num1;
        num1 = num2;
        num2 = temp;
    

    for (int i = num1; i <= num2; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            cout << "Number divisible by 3 or 5 are " << i << endl;
        }
    }
}
    return 0;
}
*/



/*#include<iostream>
using namespace std;

int main() {
	
    int num;

    cout << "Enter a number: ";
    cin >> num;

    for(i=1;i<=1;i++){
    	
    cout<< ;    	
    	
	}



return 0;

}*/



#include<iostream>
using namespace std;

int main() {
    int number, reversedNumber = 0;

    // Input a positive number
    cout << "Enter a positive number: ";
    cin >> number;

    if (number <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1;  // Exit with an error code
    }

    // Reverse the digits of the number
    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    // Display the reversed number
    cout << "Reversed Number: " << reversedNumber << endl;

    return 0;
}

