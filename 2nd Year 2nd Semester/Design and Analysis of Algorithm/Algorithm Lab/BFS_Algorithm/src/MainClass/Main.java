
package MainClass;

import BFSDFS.BFS;
import BFSDFS.DFS;

import java.util.Scanner;
import tpSort.tpSort;


public class Main {
    public static void main(String[] args) {
        System.out.println("Enter 1 to run adjacency matrix and list for undirected graph");
        System.out.println("Enter 2 to run adjacency matrix and list for directed graph");
        System.out.println("Enter 3 to run BFS on a undirected graph");
        System.out.println("Enter 4 to run DFS on a directed graph");
        System.out.println("Enter 5 to run Topological Sort");
        
        
        System.out.println();
        System.out.print("Enter your choice (1-10) :");
        Scanner input=new Scanner(System.in);
        int choice=input.nextInt();
        if(choice==1){
            
        }else if(choice==2){
            
        }else if(choice==3){
            BFS b=new BFS();
            b.readGraph();
            b.doBFS();  
            
        }
        else if(choice==4){
            DFS dfs =new DFS();
            dfs.readGraph();
            dfs.doDFS();
        }
        else if(choice==5){
            tpSort tp = new tpSort();
            tp.readGraph();
            tp.dotpSort();
        }
       
    }
}
