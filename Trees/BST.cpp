// Ankit Saini - sainiak009@gmail.com

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int n) {
		data = n;
		left = NULL;
		right = NULL;
	}
};

Node * takeInput() {
	//take input -------depth-wise--------	
	int data;
	cin >> data;
	if (data == -1) return NULL;

	Node* root = new Node(data);
	root->left = takeInput();
	root->right = takeInput();
}

Node * takeInputLevel() { //take input ---------level-wise----------
	int data;
	cin >> data;

	if(data == -1) return NULL;

	Node* root = new Node(data);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){ //It means a parent exist, So now populate it's childs
		Node* parent = q.front(); //	Getting parent
		q.pop();

		int left; cin >> left;

		if(left != -1) //We got data for left child, So add left node now
		{
			Node* leftChild = new Node(left);
			parent->left = leftChild;
			q.push(leftChild);
		}

		int right; cin >> right;

		if(right != -1) //We got data for right child, So add right node now
		{
			Node* rightChild = new Node(right);
			parent->right = rightChild;
			q.push(rightChild);
		}
	}

	return root;
}

void printLevel(Node* root){
	if(root == NULL) return;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){ //Next parent for printing is available

		Node* currParent = q.front();
		q.pop();

		if(currParent == NULL) //We have reached either end of level or tree
		{
			cout << endl; //End

			if(!q.empty())//Next level's element entry will end, if we reached end of any level
			{
				q.push(NULL);
			}

			continue;
		}

		cout << currParent->data<< " ";
		if (currParent->left) q.push(currParent->left);
		if (currParent->right) q.push(currParent->right);

	}

	return;
}


void preOrder(Node* root) {
	if (root == NULL) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);

}

void inOrder(Node* root) {
	if (root == NULL) return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);

}

void postOrder(Node* root) {
	if (root == NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";

}

int height(Node* root) //Returns height of the given tree
{
	if(root == NULL) return 0;
	int maxTillNow = max(height(root->left), height(root->right));
	return maxTillNow + 1;
}

ostream &operator<<(ostream &os, Node *root){
	printLevel(root);
	return os;
}

istream &operator>>(istream &is, Node *root){
	printLevel(root);
	return is;
}

void bstInput(Node* root){

}

Node * insertInBst(Node * root, int data){
	//Function returns the root of the "updated" tree after insertion 
	if (root == NULL){
		Node *tmp = new Node(data);
		return tmp;
	}

	if (root->data < data){
		root->right =  insertInBst(root->right, data);
		return root;
	}

	else {
		root->left = insertInBst(root->left, data);
		return root;
	}
}

Node* takeInputBST(){
	int n;
	Node * root = NULL;

	while(cin >> n && n != -1){
		root = insertInBst(root, n);
	}

	return root;
}

// Node * lowestCommonAncestorBST(Node* root, int a, int b){
// 	if(root == NULL) return NULL;
// 	if(root->left == NULL and root->right == NULL) return NULL;

// 	if(root->data <= b && root->data >= a){
// 		return root;
// 	}
// 	else if(root->data < a && root->data < b){
// 		lowestCommonAncestorBST(root->left, a, b);
// 	}else{
// 		lowestCommonAncestorBST(root->right, a, b);
// 	}

// }

int main() {
	Node* root = takeInputLevel();
	
	

	return 0;
}
