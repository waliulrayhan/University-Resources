/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package BFSDFS;

import Filereadwrite.ReadFromFile;
import Graph.Graph;

/**
 *
 * @author meta
 */
public class BFS {
        Graph g=new Graph(false);
        ReadFromFile read=new ReadFromFile();
        public void readGraph()
        {
            read.OpenFile("src/BFSDFS/BFS.txt");
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
        public void doBFS()
        {
            g.bfs();
            System.out.println("Path from S to W:");
            g.printPath("T","Y" );
            System.out.println("Path from U to Y:");
            g.printPath("U","Y");
        }
    
}
