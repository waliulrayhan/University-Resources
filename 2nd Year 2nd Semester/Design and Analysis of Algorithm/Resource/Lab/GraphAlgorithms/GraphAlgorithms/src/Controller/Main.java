/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import BFSDFS.BFS;
import BFSDFS.DFS;
import MinimumSpanningTree.*;
import SingleSourceShortestPath.BellmanFord;
import AllPairShortestPath.FloydWarshall;
import java.util.Scanner;


public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("Enter 1 to run adjacency matrix and list for undirected graph");
        System.out.println("Enter 2 to run adjacency matrix and list for directed graph");
        System.out.println("Enter 3 to run BFS on a undirected graph");
        System.out.println("Enter 4 to run DFS on a directed graph");
        System.out.println("Enter 5 to run Kruskal for calculating MST on a undirected graph");
        System.out.println("Enter 6 to run Prim for calculating MST on a undirected graph");
        System.out.println("Enter 7 to run Bellman Ford for calculating  Single source shortest Path");
        System.out.println("Enter 8 to run DAC algo for calculating  Single source shortest Path");
        System.out.println("Enter 9 to run Dijkstra algo for calculating  Single source shortest Path");
        System.out.println("Enter 10 to run Floyd Warshall algo for calculating  Single source shortest Path");
        
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
            
            
        }else if(choice==4){
            DFS dfs =new DFS();
            dfs.readGraph();
            dfs.doDFS();
        }else if(choice==5){
            Kruskal k=new Kruskal();
            k.readGraph();
            k.doMSTKruskal();
            
        }else if(choice==6){
            Prim testPrim=new Prim();
            testPrim.readGraph();
            testPrim.doMSTPrim();
            
        }else if(choice==7){
            BellmanFord b=new BellmanFord();
            b.readGraph();
            b.doBellmanFord();
            
        }else if(choice==8){
            
        }else if(choice==9){
            
        }else if(choice==10){
            FloydWarshall testFloydWarshall=new FloydWarshall();
            testFloydWarshall.readGraph();
            testFloydWarshall.doFloydWarshall();
        }else{
            
        }
       
    }
}
