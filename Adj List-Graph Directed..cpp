#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
Node* next;
int data;
};

class StackADT{ //Stack
private:
int* arr;
int size;
int max;
public:
StackADT(){
arr = NULL;
size = max = 0;
}
StackADT(int s){
size = 0;
max = s;
arr = new int[max];
}


/*~StackADT()
{
delete[]arr;
}*/

void push(int val){
arr[size] = val;
size++;
}

int pop(){
int val;
size--;
val = arr[size];
return val;
}
};

class LLADT{ //Linklist
public:
Node* first;
Node* last;

LLADT(){
first = last= NULL;
}

void InsertAtTail (int val){
Node* temp = new Node;
temp->data = val;
temp->next = nullptr;
if (first == NULL)
{
first = last = temp;
return;
}

last->next = temp;
last = last->next;
}

void print(){
Node* curr = first;
while (curr != 0){
cout << curr->data << "->";
curr = curr->next;
}
}
};

class Graph{ //Graph
int v; 
LLADT obj[10];
public:
Graph(int n){
v = n;
}
void TakeInput(int n, int w){
obj[n].InsertAtTail(w);
}
void Printlist(){
for (int i = 0; i < v; i++){
cout << i << "  ";
obj[i].print();
cout << "NULL";
cout << endl;

}
}
void ExploreFunction(int start){
int visit[10];
for (int i = 0; i < v; i++){
visit[i] = -1;
}

DFS(start, visit);
cout << endl;
for (int i = 0; i < v; i++)
{
if (i != start){
cout << start << " ";
DFS(i, visit);
cout << endl;
}
}
}

void DFS(int start, int visit[]){ //DFS
visit[start] = 1;
cout << start << " ";
Node* temp = obj[start].first;
int num = -1;
while (temp != NULL)
{
int n = temp->data;
if (visit[n] == num){
DFS(n, visit);
}
temp = temp->next;
}
}
};
int main(){
Graph g(5);
    g.TakeInput(0, 1);
    g.TakeInput(1, 0);
    g.TakeInput(0, 3);
    g.TakeInput(3, 0);
    g.TakeInput(3, 1);
    g.TakeInput(1, 3);
    g.TakeInput(3, 2);
    g.TakeInput(2, 3);
    g.TakeInput(1, 2);
    g.TakeInput(2, 1);
    g.TakeInput(2, 4);
    g.TakeInput(4, 2);
    g.TakeInput(1, 4);
    g.TakeInput(4, 1);
  
cout << " Adjacency Matrix DFS: "<<endl;
g.Printlist();
cout<<endl;
cout << "Indepth traversal: \n"<<endl;
g.ExploreFunction(1);

return 0;
}
