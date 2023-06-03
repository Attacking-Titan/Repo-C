#ifndef _List_H

struct Node;
typedef struct Node* PtrToNode;//�궨��PtrToNodeΪstruct Node*
typedef PtrToNode List;//List��
typedef PtrToNode Position;//�����λ��

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L);
Position Find(int X,List L);
void Delete(int X,List L);
Position FindPrevious(int X,List L);
void Insert(int X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
PtrToNode Retrieve(Position P);

#endif /* _List_H */


