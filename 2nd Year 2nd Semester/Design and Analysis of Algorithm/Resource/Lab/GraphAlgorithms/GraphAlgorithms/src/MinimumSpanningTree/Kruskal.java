
package MinimumSpanningTree;

import Filereadwrite.ReadFromFile;
import Graph.Graph;

public class Kruskal {
        Graph g=new Graph(false);
        ReadFromFile read=new ReadFromFile();
        public void readGraph()
        {
            read.OpenFile("src/MinimumSpanningTree/KRUSKAL.txt");
            String nVertx;
            int nVert = Integer.parseInt(read.Read());
            //System.out.println(nVert);
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
                    g.addEdge(split[0], split[1],Integer.parseInt(split[2]));
            }
           
        }
        public void doMSTKruskal()
        {
            g.kruskal();
            
        }
}
