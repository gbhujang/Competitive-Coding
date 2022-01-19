//Merge 2 sorted arrays without using Extra space.
#include<bits/stdc++.h>
using namespace std;
int main(){
	int vec1[] = { -1, 3, 4, 5}, vec2[] = {-2, 4, 6, 8};

	int n1 = sizeof(vec1)/sizeof(vec1[0]);
	int n2 = sizeof(vec2)/sizeof(vec2[0]);

	int N = n1+n2;
	int vec3[N];

	int i = 0, j = 0, k = 0;

	while(i < n1 && j < n2){
		if(vec1[i] < vec2[j]){
			vec3[k++] = vec1[i++];
		}
		else vec3[k++] = vec2[j++];
	}
	while(i < n1){
		vec3[k++] = vec1[i++];
	}
	while(j < n2){
		vec3[k++] = vec2[j++];
	}

	for(int num = 0; num < N; num++) cout<<vec3[num]<<" ";

}