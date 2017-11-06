#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

int find_max_index(double * vec, int n){
	int index = 0;
	double max = fabs(vec[0]);
	for (int i=0;i<n;i++){
		if(fabs(vec[i])>max){
			index = i;
			max = fabs(vec[i]);
		}
	}
    return index;
}

double * normalize(double * vec, int n){
	double * returnvec; 
	returnvec = (double *)calloc(n, sizeof(double));
	double max = fabs(vec[0]);
	for (int i=0;i<n;i++){
		if(fabs(vec[i])>max){
			max = fabs(vec[i]);
		}
	}
	for (int i =0;i<n;i++){
		returnvec[i] = vec[i]/max;
	}
	return returnvec;
}

double distance(double * vec1, double * vec2, int n){
	double sum = 0;
	for(int i=0;i<n;i++){
		sum += fabs(vec1[i] - vec2[i]);
	}
	return sum;
}

double * Qxw(double * mat, double * vec, int n){
	double * returnvec; 
	double temp_sum = 0; 
	returnvec = (double *)calloc(n, sizeof(double));
	for(int i=0;i<n;i++){
		temp_sum = 0;
		for(int j=0;j<n;j++){
			temp_sum += mat[n*i+j]*vec[j];
 		}
	    returnvec[i] = temp_sum;
	}
	return returnvec;

}

double powermethod(double * Q, int n){
	//get a random vector
	double * w, * w0;
	w = (double *)calloc(n, sizeof(double));
	w0 = (double *)calloc(n, sizeof(double));
	for(int i=0;i<n;i++){
		w[i] = 100*rand()/(double)RAND_MAX;
		w0[i] = w[i];
	}
	double largest_eigenv;
	while(distance(normalize(Qxw(Q, w, n), n), w, n) > 0.00001){
		w = normalize(Qxw(Q, w, n), n);
	}
	int ind = find_max_index(w, n);
	largest_eigenv = Qxw(Q, w, n)[ind]/w[ind];
	return largest_eigenv;
}

int main()
{
  double m[4] = {6,4,4,5};
  printf("%f\n", powermethod(m, 2));
  return 0;
}

