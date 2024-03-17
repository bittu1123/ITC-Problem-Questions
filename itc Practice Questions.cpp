/*#include<iostream>
using namespace std;

int main() {

	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    
    int num;
    
    cout<<"Enter a Number: ";
    cin>>num;
    
    for(int i=0;i<10;i++){
    	
    	if(num==arr1[i]){
    		
        cout<<"Number Found at "<<i<<" index."; 
		break;
	   }
		else{
			
		cout<<"Number Not Found.";
		}
    	
	
	
	}
	
		
	
	
	
	return 0;

}*/



/*int arr2[10];
	int temp;
	
	cout<<"Array 1 is: \n";
	
	for (int i = 0; i < 10; i++) {
	cout << arr1[i] << " ";
	}

    cout<<endl;

    for(int i=0;i<10;i++){
    	
    	for(int j=0;j<10-i-1;j++){
    		
    		if(arr1[j]>arr1[j+1]){
    			
    			temp=arr1[j];
    			arr1[j]=arr1[j+1];
    			arr1[j+1]=temp;
    			
			}
    		
		}
    	
	}

cout<<"Array 2 is: \n";
	
    for(int i=9;i>=0;i--){
    	
    	cout<<arr1[i]<<" ";
    	
	}*/
	
#include<iostream>
using namespace std;

int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int arr2[10];
  //  int temp;

    // Uncomment the following lines if you want to sort the array
    /*
    cout << "Array 1 is: \n";
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    cout << "Array 2 is: \n";
    for (int i = 9; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    */

    // Comment or remove the following code if you want to focus on sorting
    int num;
	bool found=false;
    
	cout << "Enter a Number: ";
    cin >> num;

    for (int i = 0; i < 10; i++) {
        if (num == arr1[i]) {
            cout << "Number Found at " << i << " index.";
            found=true;
			break;
        } 
    }
                if(!found)
            cout << "Number Not Found.";
        

    return 0;
}

