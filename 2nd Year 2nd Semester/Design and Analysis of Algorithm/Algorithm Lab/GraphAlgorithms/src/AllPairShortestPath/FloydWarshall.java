/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package AllPairShortestPath;
import Filereadwrite.ReadFromFile;
import Graph.Graph;

/**
 *
 * @author meta
 */
public class FloydWarshall {
      Graph g=new Graph(true);//true for directed.
        ReadFromFile read=new ReadFromFile();
        public void readGraph()
        {

            read.OpenFile("src/AllPairShortestPath/floydWarshall.txt");
            String nVertx;
            int nVert = Integer.parseInt(read.Read());//reading total number of vertices
            //System.out.println(nVert);
            for(int i=0;i<nVert;i++) //reading lebel of vertices
            {
            // System.out.println("   "+i+"  ");
                nVertx = read.Read();
                g.addVertex(nVertx);

            }
            int nEdge = Integer.parseInt(read.Read());//reading number of edges

            for(int i=0;i<nEdge;i++){

                String split[]=(read.Read()).split(",");

           // g.addEdge(split[0], split[1], Integer.parseInt(split[2]));
          g.addWeightedEdge(split[0], split[1], Integer.parseInt(split[2]));

            }
    }
        public void doFloydWarshall()
        {
            
            g.doFloydWarshall();
          
        }
}
