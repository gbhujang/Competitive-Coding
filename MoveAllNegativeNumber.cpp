//Move all the negative elements to one side of the array 
#include<bits/stdc++.h>
using namespace std;

void MoveNegative(int arr[], int n){

	int j=0;

	for(int i=0; i<n; i++){
		if(arr[i] < 0){
			int num = arr[j];
			arr[j] = arr[i];
			arr[i] = num;
			j++;		}
	}

	for(int i=0; i<n; i++) cout<<arr[i]<<" ";


}

int main(){
	
	int arr[]={2,4,-10,13,-7,-60,52,8,-19 };
	int n = sizeof(arr)/sizeof(arr[0]);

	MoveNegative(arr,n);
}