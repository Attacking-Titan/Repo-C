#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
  int data;
  struct stack *next;
}stack;
int main(int argc, char *argv[])
{
  char board[13] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};//������0����10 
  int i;
  stack *p,*head,*tail,*temp;
  head = (stack *)malloc(sizeof(stack));
  head->data = board[12];
  head->next = NULL;
  for(i=11;i>=0;i--){
    p = (stack *)malloc(sizeof(stack));
    p->data = board[i];
    tail = head;
    if(tail->next==NULL){
    p->next = head;//ͷ��
    head = p;
    }
    //��β��
    else{
      while(tail->next!=NULL){
      tail = tail->next;
      }
      tail->next = p;//��ջβ
      p->next = head;//����β
      temp = head;
      head = head->next;//ͷ����һ����Ϊ�µ�ͷ���
      temp->next = NULL;
    }
  }
  p = head;
  i = 12;
  while(p!=NULL&&i>=0){
  board[i] = p->data;
  p = p->next;
  i--;
  }
  for(i = 0;i<12;i++){
  if(board[i]=='0')printf("10, ");
  else printf("%c, ",board[i]);
  }
  printf("10");
  return 0;
}
