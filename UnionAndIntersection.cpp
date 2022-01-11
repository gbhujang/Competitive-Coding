//Find the Union and Intersection of the two sorted arrays.
#include<bits/stdc++.h>
using namespace std;
void UnionArray(int arr1[], int arr2[], int n1, int n2){
	map<int,int> map;

	for(int i=0; i<n1; i++){
		map[arr1[i]]++;
	}

		for(int i=0; i<n2; i++){
		map[arr2[i]]++;
	}

	for(auto x: map){
		cout<<x.first<<" ";
	}
	cout<<"\n";
}
void IntersectionArray(int arr1[], int arr2[], int n1, int n2){
	unordered_set<int> map;

	for(int i=0; i<n1; i++){
		map.insert(arr1[i]);
	}
	int ab[n1+n2];
	int j = 0;
	for(int i=0; i<n2; i++){
		int key = arr2[i];
		if(map.find(key) != map.end()){
			ab[j] = key;
			map.erase(key);
			j++; 
				}
	}


	for(int i=0; i< j; i++) cout<<ab[i]<<" ";

}
int main(){
		
		int arr1[] = {1, 3, 4, 5, 7};
        int arr2[] = {2, 3, 5, 6}; 

        int n1 = sizeof(arr1) / sizeof(arr1[0]);
        int n2 = sizeof(arr2) / sizeof(arr2[0]);

        UnionArray(arr1,arr2,n1,n2);
        IntersectionArray(arr1,arr2,n1,n2);
}
