#include<stdio.h>
#include<stdlib.h>
#define LEN 100
typedef struct Node{
	int* coef;//ϵ��coefficient
	int maxEpt;//����ݴ���maxExponent
}node,*polynomial;

struct result{
	polynomial result[20][3];
	char Operator;
}res;

int size = 0;
polynomial fx[3];

polynomial createPolynomial(int coef[],int maxEpt){
	polynomial f = (polynomial)malloc(sizeof(struct Node));
	f->maxEpt = maxEpt;
	f->coef = (int *)calloc(f->maxEpt + 1,sizeof(int));
	int i;
	for(i = 0;i <= f->maxEpt;i++)
		f->coef[i] = coef[i];
	return f;
}

void show(polynomial f){
	int i;
	printf("(");
	for(i = f->maxEpt;i > 0;i--){
		if(f->coef[i] > 0) {
			if(f->coef[i] != 1){
			printf("%d*[X^%d] + ",f->coef[i],i);
			}
			else printf("[X^%d] + ",i);
		}
		else if(f->coef[i] < 0){
			printf("(%d)*[X^%d] + ",f->coef[i],i);
		}
	}
	if(f->coef[i] >= 0)	printf("%d",f->coef[i]);
	else printf("(%d)",f->coef[i]);
	printf(")");
}

polynomial add(const polynomial f1,const polynomial f2){
	polynomial f = (polynomial)malloc(sizeof(struct Node));
	polynomial high,low;
	if(f1->maxEpt > f2->maxEpt) {
		high = f1;
		low = f2;
		f->maxEpt = f1->maxEpt;
	}
	else {
		high = f2;
		low = f1;
		f->maxEpt = f2->maxEpt;
	}
	f->coef = (int *)calloc(f->maxEpt + 1,sizeof(int));
	int i;
	for(i = 0;i <= f->maxEpt;i++){
		if(i <= low->maxEpt)
			f->coef[i] = high->coef[i] + low->coef[i];
		else f->coef[i] = high->coef[i];
	}
	return f;
}

polynomial subtract(const polynomial f1,const polynomial f2){
	polynomial f = (polynomial)malloc(sizeof(struct Node));
	f->maxEpt = f1->maxEpt > f2->maxEpt ? f1->maxEpt : f2->maxEpt;//��ȡ��������ʽ�е���ߴ���
	f->coef = (int *)calloc(f->maxEpt + 1,sizeof(int));
	int i;
	for(i = 0;i <= f->maxEpt;i++){
		if(i <= f1->maxEpt && i <= f2->maxEpt)
			f->coef[i] = f1->coef[i] - f2->coef[i];
			else if(i <= f1->maxEpt) f->coef[i] = f1->coef[i];
				else f->coef[i] = -f2->coef[i];
	}
	return f;
}

polynomial multiply(const polynomial f1,const polynomial f2){
	polynomial f = (polynomial)malloc(sizeof(struct Node));
	polynomial p1,p2;
	int high,low;
	f->maxEpt = f1->maxEpt + f2->maxEpt;
	f->coef = (int *)calloc(f->maxEpt + 1,sizeof(int));
	if(f1->maxEpt > f2->maxEpt){
		high = f1->maxEpt;
		low = f2->maxEpt;
		p1 = f1;
		p2 = f2;
	}
	else {
		high = f2->maxEpt;
		low = f1->maxEpt;
		p1 = f2;
		p2 = f1;
	}
	int i,j;
	for(i = 0;i <= high;i++){
		for(j = 0;j <= low;j++)
			f->coef[i+j] += (p1->coef[i] * p2->coef[j]);
	}
	return f;
}

void clear(){
	int i;
	polynomial p;
	for(i = 0;i < 3;i++) {
		p = fx[i];
		free(p->coef);
		free(p);
 	}
}

void diposeResult(polynomial f[],char Operator){
	int i,j;
	for(i = 0;i < 3;i++){
		res.result[size][i] = (polynomial)malloc(sizeof(struct Node));
		res.result[size][i]->maxEpt = f[i]->maxEpt;
		(res.result[size][i])->coef = (int *)calloc(f[i]->maxEpt,sizeof(int));
		for(j = 0;j <= f[i]->maxEpt;j++){
			(res.result[size][i])->coef[j] = f[i]->coef[j];
		}
	}
	res.Operator = Operator;
	size++;
	printf("\t\t\t��¼��%d�����ݳɹ�",size);
}

void viewResult(int index){
	if(index >= size) {
		printf("\t\t\t���±��޽��!\n");
		return;
	}
	int i;
	printf("\t\t\t");
	show(res.result[index][0]);
	printf("\n\t\t\t %c \n\t\t\t",res.Operator);
	show(res.result[index][1]);
	printf("\n\n\t\t\t = ");
	show(res.result[index][2]);
	printf("\n\t\t\t- - - - - - - - - - - - - - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void menu(){
	printf("\n\n");
	printf("\t\t\t_____________________________________________\n");
	printf("\t\t\t|          ______________________           |\n");
	printf("\t\t\t|          |>>>>����ʽ������<<<<|           |\n");
	printf("\t\t\t|          �˵���                           |\n");
	printf("\t\t\t|          �˳�- - - - - - - - -0           |\n");
	printf("\t\t\t|          �ӷ�- - - - - - - - -1           |\n");
	printf("\t\t\t|          ����- - - - -- - - - 2           |\n");
	printf("\t\t\t|          �˷�- - - - - - - - -3           |\n");
	printf("\t\t\t|          �鿴���- - - - - - -4           |\n");
 	printf("\t\t\t|___________________________________________|\n");
 	printf("\n\t\t\t>>>");
}

void input(){
	int coef[LEN] = {0};
	int maxEpt,i,j;
	for(i = 0;i < 2;i++){
		printf("\t\t\t�������%d������ʽ��������ݣ�\n",i + 1);
		printf("\t\t\t����ʽ����ߴ���:");
		scanf("%d",&maxEpt);
		printf("\t\t\t���������ж���ʽ�����д��ݵ�ϵ����\n");
		for(j = maxEpt;j >= 0;j--){
			printf("\t\t\t[X^%d]:",j);
			scanf("%d",&coef[j]);
		}
		fx[i] = createPolynomial(coef,maxEpt);
		printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	}
}

int main(){
	polynomial createPolynomial(int coef[],int maxEpt);
	void show(const polynomial f);
	polynomial add(polynomial f1,polynomial f2);
	polynomial subtract(const polynomial f1,const polynomial f2);
	polynomial multiply(const polynomial f1,const polynomial f2);
	void clear();
	void diposeResult(polynomial f[],char Operator);
	void show(polynomial f);
	void viewResult(int index);
	void menu();
	void input();
	
	int option;
	while(1){
		menu();
		scanf("%d",&option);
		switch(option){
			case 0: return 0;
			case 1:{
				int flag;
				input();
				fx[2] = add(fx[0],fx[1]);
				printf("\t\t\t");
				show(fx[0]);
				printf("\n\t\t\t + \n\t\t\t");
				show(fx[1]);
				printf("\n\n\t\t\t =");
				show(fx[2]);
				printf("\n\n");
				printf("\t\t\t�Ƿ���Ҫ��¼�������¼���(1)/����¼���(0):\n\t\t\t>>");
				scanf("%d",&flag);
				if(flag==0) break;
				diposeResult(fx,'+');
				clear();
				break;
			}
			case 2:{
				int flag;
				input();
				fx[2] = subtract(fx[0],fx[1]);
				printf("\t\t\t");
				show(fx[0]);
				printf("\n\t\t\t - \n\t\t\t");
				show(fx[1]);
				printf("\n\n\t\t\t = ");
				show(fx[2]);
				printf("\n\n");
				printf("\t\t\t�Ƿ���Ҫ��¼�������¼���(1)/����¼���(0):\n\t\t\t>>");
				scanf("%d",&flag);
				if(flag==0) break;
				diposeResult(fx,'-');
				clear();
				break;
			}
			case 3:{
				int flag;
				input();
				fx[2] = multiply(fx[0],fx[1]);
				printf("\t\t\t");
				show(fx[0]);
				printf("\n\t\t\t * \n\t\t\t");
				show(fx[1]);
				printf("\n\n\t\t\t = ");
				show(fx[2]);
				printf("\n\n");
				printf("\t\t\t�Ƿ���Ҫ��¼�������¼���(1)/����¼���(0):\n\t\t\t>>");
				scanf("%d",&flag);
				if(flag==0) break;
				diposeResult(fx,'*');
				clear();
				break;
			}
			case 4:{
				int flag;
				if(size==0) {
					printf("\t\t\t�޴洢���\n");
					break;
				}
				printf("\t\t\t��ǰ���洢��%d������\n",size);
                printf("\t\t\t�鿴���н��(1)/�鿴ĳ����(0)\n\t\t\t>>");
                scanf("%d",&flag);
                if(flag){
                	int i;
					for(i = 0;i < size;i++){
						viewResult(i);
					}
				}
				else {
					int index;
					printf("\t\t\t�����������±꣬�±�3�����3�μ�¼�Ľ����\n");
                    printf("\t\t\t���Ҫ�鿴��һ�εĽ����ֻ������%d\n",size-1);
                    printf("\t\t\t>>");
                    scanf("%d",&index);
                    viewResult(index);
				}
				break;
			}
			default: {
				printf("\n\t\t\t����������������룡\n");
				break;
			}
		}
		system("pause>NULL");
	}
	return 0;
}
