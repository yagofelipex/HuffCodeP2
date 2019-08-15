#include<stdio.h>

int Heap[100];
count = 0;
int GetParentIndex(int index)
{
    return index/2;
}
int GetChildrenLeftIndex(int index)
{
    return index*2;
}
int GetChildrenRightIndex(int index)
{
    return index*2 + 1;
}
void View(){
int i;
for(i = 1;i <= count;i++)
{
    printf("%d ",Heap[i]);
}
printf("\n");
}
void DownHeapMin(int index)
{
    if(index*2 > count)return;
         int left = GetChildrenLeftIndex(index);
         int Right = GetChildrenRightIndex(index);
         int smallest = index;
         if(left <= count && Heap[left] < Heap[smallest]){
            smallest = left;
         }
         if(Right <= count && Heap[Right] < Heap[smallest]){
            smallest = Right;
         }
         if(smallest == index)return;
            int aux = Heap[index];
            Heap[index] = Heap[smallest];
            Heap[smallest] = aux;
         DownHeapMin(smallest);
}
void Pop()
{
    if(count == 0){
        return;
    }
    Heap[1] = Heap[count];
    count--;
    DownHeapMin(1);
}
void UpHeapMin(int index)
{
    if (index <= 1) return;
    int Parentidx = GetParentIndex(index);
    if(Heap[index] < Heap[Parentidx]){
         int aux = Heap[index];
         Heap[index] = Heap[Parentidx];
         Heap[Parentidx] = aux;
        UpHeapMin(Parentidx);
    }
}
int Insert(int Value)
{
    count++;
    Heap[count] = Value;
    UpHeapMin(count);
}
int main()
{
    Insert(6);
    Insert(5);
    Insert(4);
    Insert(3);
    printf("Antes da remoção\n");
    View();
    printf("Depois da remoção\n");
    Pop();
    View();
    printf("Antes da remoção\n");
    View();
    Pop();
    printf("Depois da remoção\n");
    View();
}
