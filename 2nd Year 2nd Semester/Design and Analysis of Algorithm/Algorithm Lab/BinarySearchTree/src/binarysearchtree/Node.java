package binarysearchtree;

public class Node {
Node left;
Node rigth;     
Node parent;     
Node root;
int value;
public Node(int v){
  this.rigth=null;
  this.left=null; 
  this.root=null;  
  this.parent=null;
  this.value=v;    
}
}
