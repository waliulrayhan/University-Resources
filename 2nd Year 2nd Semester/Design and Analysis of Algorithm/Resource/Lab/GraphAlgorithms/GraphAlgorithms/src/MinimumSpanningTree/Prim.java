/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package MinimumSpanningTree;
import Filereadwrite.ReadFromFile;
import Graph.Graph;
/**
/**
 *
 * @author meta
 */
public class Prim {
     Graph g=new Graph(false);//true for directed.
        ReadFromFile read=new ReadFromFile();
        public void readGraph()
        {

            read.OpenFile("src/MinimumSpanningTree/prim.txt");
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

                String split[]=(read.Read()).split("-");

            g.addEdge(split[0], split[1], Integer.parseInt(split[2]));

            }
    }

        public void doMSTPrim()
        {
            g.prim();

        }
}
