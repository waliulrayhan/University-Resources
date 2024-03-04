package binarysearchtree;
import Filereadwrite.ReadFromFile;
import java.util.Scanner;
import java.io.*;
public class BinarySearchTree {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BST_operation tree=new BST_operation();
       Node root=new Node(23);
       File file = new File("src/binarysearchtree/bst.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
       String st;
        while ((st = br.readLine()) != null)    
            //System.out.println(st);
            tree.insert(root,Integer.parseInt(st));
        
       
       //tree.insert(root,44);
      // tree.insert(root,12);
       //tree.insert(root,20);
      // tree.insert(root,35);
      // tree.insert(root,52);
       
        System.out.println("Enter 1 to run preorder tree");
        System.out.println("Enter 2 to run inorder tree");
        System.out.println("Enter 3 to run post order tree");
        System.out.println("Enter 4 to run minimum and maximum value");
        System.out.println("Enter 5 to found successor");
        System.out.println("Enter 6 to delete node");
        System.out.println("Enter 7 to found predecessor");
        System.out.println();
        System.out.print("Enter your choice (1-7) :");
        Scanner in=new Scanner(System.in);
        int choice=in.nextInt();
       if(choice==1){
       System.out.println("In preorder is:");
       tree.preorder(root); 
       }
       else if(choice==2){
        System.out.println("In inorder is:");
       tree.inorder(root);
       }
       else if(choice==3){
       System.out.println("In postorder is:");
       tree.postorder(root);
       }
       else if(choice==4){
        System.out.println("the maximum value is:");
       tree.treeMaximum(root);
       
       System.out.println("the minimum value is:");
       tree.treeMinimum(root);
       }
       else if(choice==5){
      int key=23;
       Node suc=new Node(23);
       System.out.println("23 successor is:");
       tree.successor(root,key);
       System.out.println("20 successor is:");
       tree.successor(root,20);
       }
       else if(choice==6){
        System.out.println("\nDelete 20");
        tree.delete_key(root,20);
        System.out.println("Inorder traversal of the modified tree");
        tree.inorder(root);
        System.out.println("\nDelete 35");
        tree.delete_key(root,35);
        System.out.println("Inorder traversal of the modified tree");
        tree.inorder(root);
        System.out.println("\nDelete 44");
        tree.delete_key(root,44);
        System.out.println("Inorder traversal of the modified tree");
        tree.inorder(root);   
       }
       else if(choice==7){
           int key=23;
           Node suc=new Node(23);
           System.out.println("23 predecessor is:");
           tree.predecessor(root,key);
           System.out.println("20 predecessor is:");
           tree.predecessor(root,20);
       }
    }  
}
