#include <bits/stdc++.h>
using namespace std;

// custom data type for tree building
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

// Below function accepts sttring and a pointer variable as
// an argument
// and draw the tree. Returns the root of the tree
Node* constructtree(string s, int* start)
{
	// Assuming there is/are no negative
	// character/characters in the string
	if (s.size() == 0 || *start >= s.size())
		return NULL;

	// constructing a number from the continuous digits
	int num = 0;
	while (*start < s.size() && s[*start] != '('
		&& s[*start] != ')') {
		int num_here = (int)(s[*start] - '0');
		num = num * 10 + num_here;
		*start = *start + 1;
	}

	// creating a node from the constructed number from
	// above loop
	struct Node* root = new Node(num);

	// check if start has reached the end of the string
	if (*start >= s.size())
		return root;

	// As soon as we see first right parenthesis from the
	// current node we start to construct the tree in the
	// left
	if (*start < s.size() && s[*start] == '(') {
		*start = *start + 1;
		root->left = constructtree(s, start);
	}
	if (*start < s.size() && s[*start] == ')')
		*start = *start + 1;

	// As soon as we see second right parenthesis from the
	// current node we start to construct the tree in the
	// right
	if (*start < s.size() && s[*start] == '(') {
		*start = *start + 1;
		root->right = constructtree(s, start);
	}
	if (*start < s.size() && s[*start] == ')')
		*start = *start + 1;
	return root;
}
void preorder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	string s = "4(2(3)(1))(6(5))";
	// cin>>s;
	int start = 0;
	Node* root = constructtree(s, &start);
	preorder(root);
	return 0;
}
//This code is contributed by Chaitanya Sharma.
