#include<gsl/gsl_linalg.h>
#include<gsl/gsl_blas.h>
#include<stdio.h>
#include<stdlib.h>
#define RND (double)rand()/RAND_MAX
void matrix_print(const char* s,const gsl_matrix* m){
	printf(s); printf("\n");
	for(int j=0;j<m->size2;j++){
		for(int i=0;i<m->size1;i++)
			printf("%8.3g ",gsl_matrix_get(m,i,j));
		printf("\n");
		}
	}
void vector_print(const char* s,const gsl_vector* v){
	printf(s); printf("\n");
	for(int i=0;i<v->size;i++)
		printf("%8.3g ",gsl_vector_get(v,i));
	printf("\n");
	}
int main(){
	int n=3;
	gsl_matrix* M=gsl_matrix_calloc(n,n);
	for(int i=0;i<M->size1;i++)
	for(int j=0;j<M->size2;j++)
		gsl_matrix_set(M,i,j,(RND-0.5)*10);
	gsl_vector* b=gsl_vector_calloc(n);
	for(int i=0;i<b->size;i++)
		gsl_vector_set(b,i,(RND-0.5)*5);
	gsl_matrix* A=gsl_matrix_calloc(n,n);
	gsl_matrix_memcpy(A,M);
	matrix_print("matrix M=",M);
	vector_print("right hand side b=",b);
	gsl_vector* x=gsl_vector_calloc(n);
	gsl_linalg_HH_solve(M,b,x);
	vector_print("solution x to Mx=b :",x);
	gsl_vector* y=gsl_vector_calloc(n);
	gsl_blas_dgemv(CblasNoTrans,1,A,x,0,y);
	vector_print("check:  Mx= (should be equal b)",y);
/* fixme: free memory */
return 0;
}
