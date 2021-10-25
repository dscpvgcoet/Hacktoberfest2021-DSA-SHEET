#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// only queue is used.
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> vec;
    if (root == NULL)
        return vec;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        vector<int> level;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);

            level.push_back(temp->data);
        }

        vec.push_back(level);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";

        cout << "\n";
    }
}

// stack and queue both is used.
vector<int> levelOrderReverse(Node *root)
{
    vector<int> vec;
    if (root == NULL)
        return vec;

    stack<Node *> st;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        st.push(temp);
        q.pop();

        if (temp->right != NULL)
            q.push(temp->right);

        if (temp->left != NULL)
            q.push(temp->left);
    }

    while (!st.empty())
    {
        vec.push_back(st.top()->data);
        st.pop();
    }

    for (int j = 0; j < vec.size(); j++)
        cout << vec[j] << " ";
}

int main()
{
    Node *root = new Node(25);

    root->left = new Node(15);
    root->left->right = new Node(22);
    root->right = new Node(30);
    root->right->left = new Node(28);
    root->right->right = new Node(33);

    levelOrder(root);
    cout << "\n";
    levelOrderReverse(root);
}