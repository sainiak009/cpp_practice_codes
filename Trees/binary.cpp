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

pair<int,int> diameter_height(Node* root)// Returns diameter or width of given binary tree
{	

	pair<int,int> p(0,0); //pair to send diameter and path to reduce time complexity
	if(root == NULL) return p;

	pair<int,int> leftMax = diameter_height(root->left);
	pair<int,int> rightMax = diameter_height(root->right);

	p.second = max(leftMax.second, rightMax.second) + 1;
	int crossing_dia = leftMax.second + rightMax.second + 1;
	p.first = max(crossing_dia, max(leftMax.first, rightMax.first));

	return p;
}

ostream &operator<<(ostream &os, Node *root){
	printLevel(root);
	return os;
}

istream &operator>>(istream &is, Node *root){
	printLevel(root);
	return is;
}

void mirror(Node* root){
	if(root == NULL) return;

	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
}

pair<int,int> maxSumChildsOrParent(Node* root){
	pair<int,int> p(0,0);

	if(root == NULL) return p;

	int X = root->data;
	pair<int,int> left = maxSumChildsOrParent(root->left);
	pair<int,int> right = maxSumChildsOrParent(root->right);

	//Including X
	p.first = X + left.first + right.first;

	//Excluding X
	p.second = max(left.first, left.second) + max(right.first, right.second);

	return p;
}

void printAllPaths(Node* root, vector<int> path){
	if(root == NULL){
		vector<int>::iterator it;
		for(it = path.begin(), it <= path.end(), ++it) cout << *it;
		cout << endl;
	}

	path.push_back(root->data);
	printAllPaths(root->left);
	printAllPaths(root->right);
	path.pop_back();

}

int main() {
	Node* root = takeInputLevel();
	printLevel(root);
	// mirror(root);
	pair<int,int> p= maxSumChildsOrParent(root);
	cout << p.first << "  " << p.second;



	// pair<int,int> p = diameter_height(root);
	// cout << "diameter : " << p.first << " " << "height : " << p.second << endl;
	return 0;
}
