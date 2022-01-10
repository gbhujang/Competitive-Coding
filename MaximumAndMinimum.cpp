//Find the maximum and minimum element in an array
#include<bits/stdc++.h>
using namespace std;

struct Pair{
	int min;
	int max;
};

Pair getMinMax(int arr[], int n){
	struct Pair minmax;
	if(n==1){
		minmax.min = arr[0];
		minmax.max = arr[0];
		return minmax;
	}
	if(arr[0] > arr[1]){
		minmax.max = arr[0];
		minmax.min = arr[1];
	}
	else{
		minmax.max = arr[1];
		minmax.min = arr[0];
	}
	int i;
	for(i = 2; i < n; i++){
		if(minmax.max < arr[i]){
			minmax.max = arr[i];
		}
		else if(minmax.min > arr[i]){
			minmax.min = arr[i];
		}
	}
	return minmax;
}

int main(){


    int arr[] = { 1000, 11, 445, 
                  1, 330, 3000 };
    int arr_size = 6;
    
    struct Pair minmax = getMinMax(arr, arr_size,2);//330
    
    cout << "Minimum element is " 
         << minmax.min << endl;
    cout << "Maximum element is " 
         << minmax.max;

}