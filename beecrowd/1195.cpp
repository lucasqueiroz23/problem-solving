#include <iostream>

int counter=0;
using namespace std;

typedef struct node
{
	int n;
	struct node *left, *right;
}node;

node *createNode(int val)
{
	node *newNode = new node;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->n = val;

	return newNode;
}

void insertBinTree(node *tree, int val)
{
	if(val<tree->n)
	{
		if(tree->left == NULL)
		{
			tree->left = createNode(val);
			return;
		}
		insertBinTree(tree->left,val);
		return;
	}
	if(val>tree->n)
	{
		if(tree->right == NULL)
		{
			tree->right = createNode(val);
			return;
		}
		insertBinTree(tree->right,val);
		return;
	}

}

void preOrder(node *tr,int valmax)
{
	if(tr !=NULL)
	{
		cout << tr->n;
		counter++;
		if(counter != valmax)
			cout <<" ";
		preOrder(tr->left,valmax);
		preOrder(tr->right,valmax);
	}

}

void inOrder(node *tr,int valmax)
{
	if(tr !=NULL)
	{

		inOrder(tr->left,valmax);
		cout << tr->n;
		counter++;
		if(counter != valmax)
			cout <<" ";
		inOrder(tr->right,valmax);
	}
}

void postOrder(node *tr, int valmax)
{
	if(tr !=NULL)
	{

		postOrder(tr->left,valmax);
		postOrder(tr->right,valmax);
		cout << tr->n;
		counter++;
		if(counter != valmax)
			cout <<" ";
	}

}


int main()
{
	int x = 0;
	cin >> x;
	for(int i = 1;i<=x;i++)
	{

		node *btree = new node;
		btree->left = NULL;
		btree->right = NULL;


		int n = 0;
		cin >> n;
		int fval = 0;
		cin >>fval;
		btree->n = fval;
		for(int k = 1;k<n;k++)
		{
			int val = 0;
			cin >> val;
			insertBinTree(btree,val);
		}

		cout << "Case " << i <<":\n";
		cout <<"Pre.: ";
		counter = 0;
		preOrder(btree,n);
		counter = 0;
		cout <<"\n";
		cout<<"In..: ";
		inOrder(btree,n);
		counter = 0;
		cout<<"\n";
		cout<<"Post: ";
		postOrder(btree,n);
		counter = 0;
		cout<<"\n\n";

		delete btree;
	}

	return 0;
}
