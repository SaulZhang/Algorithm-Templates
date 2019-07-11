对于二叉树的构造函数一般遵循以下的结构

Node* build(T,x){<br>
  if(T==BULL)<br>
  T = create();<br>
   T->data = x;<br>
  if(左子树不为空)<br>
      T->left = build();<br> 
  if(右子树不为空)<br>
      T->right = build();<br>
  return T;<br>
}<br>
