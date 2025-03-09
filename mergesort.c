#include <stdio.h>

/*void merge(int array[], unsigned int first, unsigned int m, unsigned int last){
	
	int n = last-first+1;
	int h, i;
	int temp[n];
	int j = m;
	
	for (i = 0; i < n; i++)
		temp[i] = array[first + i]; //here
	
	i = 0;
	h = first;
	printf("..\n");
	while (j < n && i < m){ //j=2, n=4, i=0, m=2 
	//for (h = first; h < last; h++){
		printf(".\n");
		if (temp[i] < temp[j]){
			array[h] = temp[i]; //here
			i++;
		}else {
			array[h] = temp[j]; //here
			j++;
		}
		
		//h++;
	}
	printf(".\n");
	while (i < m){
		array[h] = temp[i]; //here
		i++;
		h++;
	}
	printf(".\n");
	while (j < n){
		array[h] = temp[j]; //here
		j++;
		h++;
	}
}

void mergeSort(int array[], unsigned int first, unsigned int last){
	
	int m = (last+1-first)/2;
	
	if (last != first+1){
		mergeSort(array, first, last - m);
		mergeSort(array, (first + m), last);
	}
	for(int i = first; i <= last; i++)
		printf("%d", array[i]);
	printf("\n");
	merge(array, first, m,last);	
	for(int i = first; i <= last; i++)
		printf("%d", array[i]);
	printf("\n");
}*/

void merge(int array[], int first, int middle, int last){
	int j, k, z;
	int num1 = middle - first + 1 ;
	int num2 = last - middle;
	int temp1[num1];
	int temp2[num2];

	for(j = 0; j < num1; j++){
	
		temp1[j] = array[first + j];
	}

	for(k = 0; k < num2; k++){

		temp2[k] = array[middle + 1 + k];
	}


	j = 0;
	k = 0;
	z = first;

	while (j < num1 && k < num2){
	
		if(temp1[j] <= temp2[k]){

			array[z] = temp1[j];

			j++;
		}
	
		else{
	
			array[z] = temp2[k];

			k++;
		}

		z++;
	}

	while(j < num1){

		array[z] = temp1[j];
		j++;
		z++;
	}

	while(k < num2){

		array[z] = temp2[k];
		k++;
		z++;
	}
}

void mySort(int array[], unsigned int first, unsigned int last){

		if(first < last){

			int middle = first + (last - first) / 2;
			
			mergeSort(array, first, middle);
			mergeSort(array, middle + 1, last);

			merge(array, first, middle, last);
			
				
		}
	
    
}

int main()
{
	
	int h[] = {5,1,3,4,2};//{5,1,3,4,2}; 5, 1, 7, 3, 6, 2, 8, 4 
	mergeSort(h, 0, 4);
	for(int i = 0; i < 5; i++)
		printf("%d", h[i]);

	return 0;
}
