#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, int val) {

    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}
void find(Node*root,int low,int high){
    if(root==NULL){
        return;
    }
    if(root->data>=low && root->data<=high){
        cout<<root->data<<" ";
    }
    find(root->left,low,high);
    find(root->right,low,high);
}

int main() {

    Node* root = NULL;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    cout<<"enter the range in which you want element"<<endl;
    int x,y;
    cin>>x>>y;
    find(root,x,y);


    return 0;
}
