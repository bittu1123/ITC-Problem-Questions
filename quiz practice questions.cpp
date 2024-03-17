/*#include <iostream>
using namespace std;
int main()
{
	int a[6] = { 10, 20, 30, 40, 50 };
	int *aptr = a;
	cout << "value is =" << *aptr << endl;  
	cout << "value is =" << ++*aptr << endl; 
	cout << "value is =" << *++aptr << endl; 
    cout << "value is =" << *aptr++ << endl;
	cout << "value is =" << ++*aptr << endl;
	cout << "value is =" << *aptr << endl; 

	system("pause");  
	return 0;
}*/








/*#include <iostream>
using namespace std;


void showarray(int * arr, int size ){
	
	cout<<"Array Elements are: \n";
	
	for(int i=1;i<=size;i++){		
	cout<<arr[i]<<" ";			
	}	
	
}


int* get_array(int * arr, int size ){
	
	return arr;
	
}


int get_array(int * arr, int size, int num ){

    int temp=-1;

    for(int i=1;i<=size;i++){
    	
    if(num==i){
    temp= arr[i];
    }
	}

    return temp;
}




int main(){
	
	int size,num;
	
	cout<<"Enter the size of an array: ";
	cin>>size;
	
	cout<<endl;
	
	int * arr = new int[size];
	
	cout<<"Enter The Array Elements: \n";
	
	for(int i=1;i<=size;i++){
		
	cin>>arr[i];	
		
	}
	
	cout<<endl;
		
	showarray(arr, size );
	
	cout<<endl;
	
	int* receive_array=get_array( arr, size );
	
	cout<<endl;
	
	cout<<"Receive Array Elements are: \n";
	
	for(int i=1;i<=size;i++){
	cout<<receive_array[i]<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Enter the Index Number between (1 to "<<size<<") for Element: ";
	cin>>num;
	
	cout<<endl;
	
	int C=get_array( arr, size, num );
	
	
	if(C==-1){
	cout<<"Given Index Number is Invalid.";	
	}
	
	else{
	cout<<"Value at given index is "<<C; 
    }
	
	
return 0;	
}*/



