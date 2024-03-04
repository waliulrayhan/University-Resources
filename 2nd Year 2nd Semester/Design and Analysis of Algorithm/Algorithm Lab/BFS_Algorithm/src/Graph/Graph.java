//GraphAlgorithms
package Graph;

import Core.*;
import Filereadwrite.writetofile;
import java.util.HashMap;

public class Graph {
   private final int MAX_VERTS = 20;
   public final int MAX_EDGE=30;//
   private Vertex vertexList[];  
   private Edge edgeList[];//
   private int nVerts;
   private int nEdge;//
   private Heap myHeap;//
   private Queue queue;
   private Stack[] list;
   private boolean isDirected;
   private int time;
   HashMap < String,Integer > mymap=new HashMap < String, Integer >();
    writetofile write=new writetofile();

   public Graph(boolean isDir)
   {
      
      vertexList = new Vertex[MAX_VERTS];
      edgeList=new Edge[MAX_EDGE];
  
     
      nVerts = 0;
      nEdge=0;//
      list=new Stack[MAX_VERTS];
      for(int j=0; j<MAX_VERTS; j++) {
     
         list[j]=new Stack();

      }

      queue=new Queue();

      isDirected=isDir;
      
      write.OpenFile("src/BFSDFS/output.txt",'w'); // to write file.
   }
   
   // this method add vertex in hashmap
   public void addVertex(String lab)
   {

        vertexList[nVerts] = new Vertex(lab);
        if(mymap.put(lab, nVerts++)==null) ;
     
   }

 // this method includes edge list into djacency list (stack)
   public void addEdge(String start, String end)//
   {
       edgeList[nEdge]=new Edge(start, end);
       nEdge++;
       if(isDirected)
       {
           
           list[mymap.get(start)].push(mymap.get(end));
       }

       else
       {
           list[mymap.get(start)].push(mymap.get(end));
           list[mymap.get(end)].push(mymap.get(start));
       }

   }
 
   public String isInfinite(int v)
   {
       if(v>=999) return "INF";
       else return String.valueOf(v);
   }
   public String isNull(int v)
     {
         if(v==0) return "NIL";
         else return String.valueOf(v);
     }
   public void displayVertex()
   {
       for(int i=0;i<nVerts;i++)
       {
           write.Write("Node name :"+ vertexList[i].label+" |  Color:"+vertexList[i].color+" |  Dist: "+isInfinite(vertexList[i].dist)+" |  Parent->"+vertexList[i].parent+"\n");
           System.out.println("Node name :"+ vertexList[i].label+" |  Color:"+vertexList[i].color+" |  Dist: "+isInfinite(vertexList[i].dist)+" |  Parent->"+vertexList[i].parent);
       }
       
       
   }

   public void displayAdjList()
   {
        for(int j=0;j<nVerts;j++)
       {
           System.out.print(j);
            for(int k=0;k<=list[j].gettop();k++)
           {
               System.out.print(" -> "+list[j].get(k));
           }
           System.out.println();
       }
   }
   public void bfs()
   {
      vertexList[0].dist=0;
      vertexList[0].color="GRAY";

      queue.insert(0);
      while(!(queue.isEmpty())){
            int vert=(Integer)queue.remove();
            for(int i=0;i<=list[vert].gettop();i++){

                int v2=list[vert].get(i);
                displayVertex(); // used to display intermediate steps of each vertex
                if((vertexList[v2].color).equals("WHITE")){
                     
                    vertexList[v2].color="GRAY";
                    vertexList[v2].dist=vertexList[vert].dist+1;
                    vertexList[v2].parent=vertexList[vert].label;
                    queue.insert(v2);

                }

            }
            
            vertexList[vert].color="BLACK";

      }
      displayVertex();
      write.CloseFile();
      
   }
   public void printPath(String s,String v)
   {
       if(v.equals(s))
       {
           System.out.println(vertexList[mymap.get(s)].label);
           //write.Write(vertexList[mymap.get(s)].label+"\n");
       }
       else if(vertexList[mymap.get(v)].parent==null)
       {
           System.out.println("No path exists");
           //write.Write("No path exists"+"\n");
       }
       else
       {
            printPath(s,vertexList[mymap.get(v)].parent);
            //write.Write(vertexList[mymap.get(v)].label+"\n");
            System.out.println(vertexList[mymap.get(v)].label);
            //write.CloseFile();
       }


  } 
   
   
   public void dfs()
   {
       time=0;
       for(int j=0;j<nVerts;j++)
       {

          //displayDFSTime();
           if((vertexList[j].color).equals("WHITE"))
           {
               //displayDFSTime();
               dfsVisit(j);

           }
       }
   }
   public void dfsVisit(int verts)
   {
     // displayDFSTime();

       time=time+1;
       vertexList[verts].inTime=time;
       vertexList[verts].color="GRAY";
       //displayDFSTime();
       for(int i=0;i<=list[verts].gettop();i++){
           int v2=list[verts].get(i);

           if((vertexList[v2].color).equals("WHITE")){
               vertexList[v2].parent=vertexList[verts].label;
             //  displayDFSTime();
               dfsVisit(v2);

           }
       }
       vertexList[verts].color="BLACK";
      
       time=time+1;
       vertexList[verts].fTime=time;
        //displayDFSTime();
        displaytpSort(verts);
   }
   public void displayDFSTime()
   {
       for(int j=0;j<nVerts;j++){
            System.out.println(vertexList[j].label+"->"+vertexList[j].color+"->"+vertexList[j].parent+"->"+
                    vertexList[j].inTime+"->"+vertexList[j].fTime);
       }
       System.out.println();
       System.out.println();
   }
   
   public void displaytpSort(int ver)
   {
       System.out.println(vertexList[ver].label+"->"+vertexList[ver].color+"->"+vertexList[ver].parent+"->"+
                    vertexList[ver].inTime+"->"+vertexList[ver].fTime);
   }
   
   public void tpSort()
   {
       dfs();
   }

}
