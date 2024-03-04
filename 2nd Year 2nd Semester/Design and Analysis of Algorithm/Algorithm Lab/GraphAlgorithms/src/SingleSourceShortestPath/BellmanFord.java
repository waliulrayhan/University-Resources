/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package SingleSourceShortestPath;

import Filereadwrite.ReadFromFile;
import Graph.Graph;

/**
 *
 * @author meta
 */
public class BellmanFord 
{
        Graph g=new Graph(true);
        ReadFromFile read=new ReadFromFile();
        public void readGraph()
        {
            read.OpenFile("src/SingleSourceShortestPath/bellmanford.txt");
            String nVertx;
            int nVert = Integer.parseInt(read.Read());
           //System.out.println(nVert);
            for(int i=0;i<nVert;i++)
            {
                nVertx = read.Read();
                System.out.println(nVertx);
                g.addVertex(nVertx);
            }
            //Reading number of Edges
            int  nEdge = Integer.parseInt(read.Read());
            //System.out.println(nEdge);
       
            for(int i=0;i<nEdge;i++){
                    //strat and end node of an Edge 
                    String split[]=(read.Read()).split(":");
                    //System.out.println(split[0]+": "+split[1]+": "+split[2]);
                    g.addEdge(split[0],split[1],Integer.parseInt(split[2]));
            }
    
    
        }
        public void doBellmanFord()
        {
            if(g.bellManFord()){
                g.displayBellmanFordGraphInfo();
            }
        }
}