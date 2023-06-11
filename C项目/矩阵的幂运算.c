/*
	Name:����ͼ���ڽӾ������
	Copyright:�ӵ���
	Author:�ӵ���
	Date:2023/06/23 11:22
	Description:
*/
#include<stdio.h>
#include<stdlib.h>
struct Matrix{
	int **matrix;
	int rows;
	int cols;
};

struct Matrix *createMatrix(int *arr,int rows,int cols){
	struct Matrix *M =  (struct Matrix *)malloc(sizeof(struct Matrix));
	M->matrix = (int **)malloc(sizeof(int *) * rows);
	int i,j;
	/* ���پ���Ŀռ䲢����������Ԫ�ظ�ֵ */
	if(arr == NULL){
		for(i = 0;i < rows;i++){
			M->matrix[i] = (int *)malloc(sizeof(int) * cols);
  			for(j = 0;j < cols;j++)
				M->matrix[i][j] = 0;
		}
	}
	else {
		for(i = 0;i < rows;i++){
			M->matrix[i] = (int *)malloc(sizeof(int) * cols);
  			for(j = 0;j < cols;j++)
				M->matrix[i][j] = *(arr + cols * i + j);
		}
	}
	M->rows = rows;
	M->cols = cols;
	return M;
}

struct Matrix *matrixClone(struct Matrix *M){
	struct Matrix *copy = (struct Matrix *)malloc(sizeof(struct Matrix));
	copy->matrix = (int **)malloc(sizeof(int *) * M->rows);
	int i,j;
	for(i = 0;i < M->rows;i++){
		copy->matrix[i] = (int *)malloc(sizeof(int) * M->cols);
		for(j = 0;j < M->cols;j++){
			copy->matrix[i][j] = M->matrix[i][j];
		}
	}
	copy->rows = M->rows;
	copy->cols = M->cols;
	return copy;
}

/*
	�ܹ��������M1*M2��ǰ����M1����������M2������
	res=M1*M2,res����������M1��������res����������M2������
*/
struct Matrix *matrixMult(struct Matrix *M1,struct Matrix *M2){
	int i,j,k;
	struct Matrix *res = createMatrix(NULL,M1->rows,M2->cols);
	for(i = 0;i < res->rows;i++){
        for(j = 0;j < res->cols;j++){
        	for(k = 0;k < M1->cols;k++){
				res->matrix[i][j] += M1->matrix[i][k] * M2->matrix[k][j];
			}
		}
   	}
	return res;
}

void printMatrix(struct Matrix *M){
	int i,j;
	for(i = 0;i < M->rows;i++){
		printf("\t\t");
		for(j = 0;j < M->cols;j++){
			printf("%d ",M->matrix[i][j]);
		}
		putchar('\n');
	}
}

void matrixClean(struct Matrix *M){
	if(M == NULL) return;
	int i;
	for(i = 0;i < M->rows;i++){
		free(M->matrix[i]);
	}
	free(M->matrix);
	free(M);
	M = NULL;//���ͷź��Mָ���ÿ�
}

/* �������M��n���� */
struct Matrix *matrixPow(struct Matrix *M,int n){
	if(n == 1) {
		return matrixClone(M);
	}
	struct Matrix *t = NULL;//��ʱ����
	struct Matrix *res = NULL;
	if(n % 2 == 0){
		t = matrixPow(M,n/2);
		res =  matrixMult(t,t);
  		matrixClean(t);
		return res;
	}
	else{
		t = matrixPow(M,(n+1)/2);
		res = matrixMult(t,M);
 		matrixClean(t);
 		return res;
	}
}

int main(){
	int matrix1[4][4] = {
		0,1,0,1,
		1,0,1,1,
		0,1,1,0,
		1,1,0,0
	};
	/* ��һ�ֲ��� */
	struct Matrix *M1 = createMatrix((int *)matrix1,4,4);
 	struct Matrix *res1 = matrixMult(M1,M1);//����M1*M1
 	struct Matrix *res2 = matrixMult(res1,M1);//����res*M1
  	struct Matrix *res3 = matrixPow(M1,3);//����M^3
  	printMatrix(M1);
 	putchar('\n');
 	printMatrix(res1);
 	putchar('\n');
 	printMatrix(res2);
  	putchar('\n');
	printMatrix(res3);
	putchar('\n');
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
	/* �ڶ��ֲ��� */
	int matrix2[4][4] = {
		1,0,1,1,
		1,0,0,0,
		1,0,0,1,
		1,1,0,0
	};
	struct Matrix *M2 = createMatrix((int *)matrix2,4,4);
	struct Matrix *res4 = matrixMult(M2,M2);//����M2*M2
	struct Matrix *res5 = matrixMult(res4,M2);//����res4*M2
	struct Matrix *res6 = matrixMult(res5,M2);//����res5*M2
	struct Matrix *res7 = matrixPow(M2,4);//����M2^4
 	printMatrix(res4);
	putchar('\n');
	printMatrix(res5);
	putchar('\n');
	printMatrix(res6);
	putchar('\n');
	printMatrix(res7);
	putchar('\n');
	return 0;
}

