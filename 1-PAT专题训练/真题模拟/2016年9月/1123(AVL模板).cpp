/*
如何判断是否处于不平衡的状态？
如何判断属于哪一种不平衡的状态？
如何只对每一种状态进行调整？
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node* leftRotate(node *tree) {//R型
    node *temp = tree->right;//取右子树的根结点
    tree->right = temp->left;//将根结点赋值为右子树根结点的左子树(NULL)
    temp->left = tree;//将根结点作为右子树根结点的左结点
    return temp;
}
node* rightRotate(node *tree) {//L型
    node *temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}
node* leftRightRotate(node *tree) {//LR型
    tree->left = leftRotate(tree->left);//先忽略根结点，以根结点的左子结点为轴('R')进行左旋，得到L型的不平衡子树
    return rightRotate(tree);//然后以根结点为轴进行右旋
}
node* rightLeftRotate(node *tree) {//RL型
    tree->right = rightRotate(tree->right);//先忽略根结点，以根结点的右子结点为轴('L')进行右旋，得到R型的不平衡子树
    return leftRotate(tree);//然后以根结点为轴进行左旋
}
int getHeight(node *tree) {//获取结点的高度用于计算结点的平衡因子
    if (tree == NULL) return 0;
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return max(l, r) + 1;
}
node* insert(node *tree, int val) {//插入一个结点
    if (tree == NULL) {//如果为空，直接赋值给该结点
        tree = new node();
        tree->val = val;
    }else if (tree->val > val) {//插入到左子树
        tree->left = insert(tree->left, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);//获取插入该结点之后左右子树的高度
        if (l - r >= 2) {//左子树比右子树高引起失去平衡
            if (val < tree->left->val)//   ‘/’形状，LL型
                tree = rightRotate(tree);
            else// ‘<’形状，LR型
                tree = leftRightRotate(tree);
        }
    } else {//插入到右子树
        tree->right = insert(tree->right, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);
        if (r - l >= 2) {//右子树比左子树高引起失去平衡
            if (val > tree->right->val)//‘\’形状，RR型
                tree = leftRotate(tree);
            else//‘>’形状，RL型
                tree = rightLeftRotate(tree);
        }
    }
    return tree;
}
int isComplete = 1, after = 0;
vector<int> levelOrder(node *tree) {
    vector<int> v;
    queue<node *> queue;
    queue.push(tree);
    while (!queue.empty()) {
        node *temp = queue.front();
        queue.pop();
        v.push_back(temp->val);//暂存层次的结果
        if (temp->left != NULL) {
            if (after) isComplete = 0;
            queue.push(temp->left);
        } else {
            after = 1;
        }
        if (temp->right != NULL) {
            if (after) isComplete = 0;
            queue.push(temp->right);
        } else {
            after = 1;
        }
    }
    return v;
}
int main() {
    int n, temp;
    scanf("%d", &n);
    node *tree = NULL;//树根
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        tree = insert(tree, temp);
    }
    vector<int> v = levelOrder(tree);
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n%s", isComplete ? "YES" : "NO");
    return 0;
}
