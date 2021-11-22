#include <iostream>

using namespace std;

struct TreeNode
{
	int key;
	struct TreeNode* left, * right;
};

void postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->key << '\n';
	}
}

TreeNode* insert(TreeNode* node, int key)
{
	if (node == NULL) //���� ��Ʈ �����
	{
		TreeNode* temp = new TreeNode();
		temp->key = key;
		temp->left = temp->right = NULL;
		return temp;
	} 

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	//����� �ӵ�
	TreeNode* root = NULL;

	int node;
	while (!cin.eof()) //�����Է³����� �ޱ�
	{
		cin >> node;
		root = insert(root, node);

	}
	postorder(root);

	return 0;
}
//���� �ڷᱸ������ ����Ž��Ʈ�� 308��