
package BFSDFS;
import Filereadwrite.ReadFromFile;
import Graph.Graph;

public class DFS {
   Graph g=new Graph(true);
        ReadFromFile read=new ReadFromFile();
        public void readGraph()
        {
            read.OpenFile("src/BFSDFS/DFS.txt");
            String nVertx;
            int nVert = Integer.parseInt(read.Read());
            System.out.println(nVert);
            for(int i=0;i<nVert;i++)
            {
                nVertx = read.Read();
                g.addVertex(nVertx);
            }
          
            int  nEdge = Integer.parseInt(read.Read());
        
       
            for(int i=0;i<nEdge;i++){
                   
                    String split[]=(read.Read()).split("-");
                    g.addEdge(split[0], split[1]);
            }
           
        }
        public void doDFS()
        {
            g.dfs();
        }
         
}
