/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tpSort;

import Filereadwrite.ReadFromFile;
import Graph.Graph;

/**
 *
 * @author csejnu
 */
public class tpSort {
    Graph g=new Graph(false);
        ReadFromFile read=new ReadFromFile();
        public void readGraph()
        {
            read.OpenFile("src/tpSort/tpFile.txt");
            String nVertx;
            int nVert = Integer.parseInt(read.Read());
            System.out.println(nVert);
            for(int i=0;i<nVert;i++)
            {
                nVertx = read.Read();
                g.addVertex(nVertx);
            }
            //Reading number of Edges
            int  nEdge = Integer.parseInt(read.Read());
        
       
            for(int i=0;i<nEdge;i++){
                    //strat and end node of an Edge 
                    String split[]=(read.Read()).split("-");
                    g.addEdge(split[0], split[1]);
            }
           
        }
        public void dotpSort()
        {
            g.tpSort();
//            System.out.println("Path from S to W:");
//            g.printPath("T","Y" );
//            System.out.println("Path from U to Y:");
//            g.printPath("U","Y");
        }
    
}
