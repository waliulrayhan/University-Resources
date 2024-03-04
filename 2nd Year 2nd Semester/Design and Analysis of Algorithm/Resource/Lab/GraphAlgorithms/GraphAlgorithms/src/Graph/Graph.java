//GraphAlgorithms
package Graph;

import Core.*;
import java.util.HashMap;

public class Graph {
   private final int MAX_VERTS = 20;
   public final int MAX_EDGE=30;//
   private Vertex vertexList[];  
   private Edge edgeList[];//
   private Edge spanEdgeList[];//
   private int adjMat[][];
   private int floydWMat[][];
   private int floydPMat[][];
   private int nVerts;
   private int nEdge;//
   private Heap myHeap;//
   private Queue queue;
   private Stack[] list;
   private boolean isDirected;
   private int time;
   HashMap < String,Integer > mymap=new HashMap < String, Integer >();


   public Graph(boolean isDir)
   {
      
      vertexList = new Vertex[MAX_VERTS];
      edgeList=new Edge[MAX_EDGE];
      adjMat = new int[MAX_VERTS][MAX_VERTS];
      floydWMat = new int[MAX_VERTS][MAX_VERTS];
      floydPMat = new int [MAX_VERTS][MAX_VERTS];
      nVerts = 0;
      nEdge=0;//
      list=new Stack[MAX_VERTS];
      for(int j=0; j<MAX_VERTS; j++) {
         for(int k=0; k<MAX_VERTS; k++){
            adjMat[j][k] = 0;
            floydWMat[j][k]=0;
            floydPMat[j][k]=0;


         }
         list[j]=new Stack();

      }

      queue=new Queue();

      isDirected=isDir;
   }
   public void addVertex(String lab)
   {

        vertexList[nVerts] = new Vertex(lab);
        if(mymap.put(lab, nVerts++)==null) ;
       
      
   }


   public void addEdge(String start, String end, int w)//
   {
       edgeList[nEdge]=new Edge(start, end, w);
       nEdge++;
       if(isDirected)
       {
           adjMat[mymap.get(start)][mymap.get(end)]=w;
           list[mymap.get(start)].push(mymap.get(end));
       }

       else
       {
           adjMat[mymap.get(start)][mymap.get(end)]=w;
           adjMat[mymap.get(end)][mymap.get(start)]=w;
           list[mymap.get(start)].push(mymap.get(end));
           list[mymap.get(end)].push(mymap.get(start));
       }

   }
   public void addEdge(String start, String end)
   {
      int startx=mymap.get(start);
      int endx=mymap.get(end);
      adjMat[startx][endx] = 1;
      if(isDirected==false)
            adjMat[endx][startx] = 1;
      list[startx].push(endx);
      if(isDirected==false) list[endx].push(startx);
   }
    public void addWeightedEdge(String start, String end, int w)
    {

       int startx=mymap.get(start);
       int endx=mymap.get(end);
      //weightedMat[startx][endx] = w;
      floydWMat[startx][endx]=w;
      adjMat[startx][endx]=w;
      if(w==0 && w==9999)
          floydPMat[startx][endx]=0;
      else
        floydPMat[startx][endx]=startx+1;

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
            System.out.println("Node name :"+ vertexList[i].label+" |  Color:"+vertexList[i].color+" |  Dist: "+isInfinite(vertexList[i].dist)+" |  Parent->"+vertexList[i].parent);
       }
   }
   public void displayAdjMat()
   {
       System.out.println("Adjacent Matrix:");
       for(int j=0;j<nVerts;j++)
       {
           for(int k=0;k<nVerts;k++)
           {
               System.out.print(adjMat[j][k]+" ");
           }
           System.out.println();
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
                displayVertex();
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
      
   }
   public void printPath(String s,String v)

   {
       if(v.equals(s))
       {
           System.out.println(vertexList[mymap.get(s)].label);
       }
       else if(vertexList[mymap.get(v)].parent==null)
       {
           System.out.println("No path exists");
       }
       else
       {
            printPath(s,vertexList[mymap.get(v)].parent);
            System.out.println(vertexList[mymap.get(v)].label);
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
               displayDFSTime();
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
       displayDFSTime();
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
        displayDFSTime();

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
   public void sortEdges()//
   {
      myHeap=new Heap(nEdge,edgeList); 
      myHeap.buildMinHeap();
      myHeap.heapSort();
       
   }
   
   public void kruskal()
   {
       DisjointSet set= new DisjointSet(nVerts);
       set.makeSet();
       spanEdgeList = new Edge[MAX_EDGE];
       int count=0;
       sortEdges();
       myHeap.displayHeap(nEdge);
       set.displaySet();
       Edge []temp=myHeap.getEdge();
       for(int i=nEdge;i>0;i--)
       {
           int stnode=mymap.get(temp[i].stNode);
           int endnode=mymap.get(temp[i].endNode);
           if(set.findSet(stnode)!=set.findSet(endnode)){
               set.setUnion(stnode, endnode);
               spanEdgeList[count++]=temp[i];
               
           }
       }
       printKruskalEdge();
   }
   public void printKruskalEdge()
   {
       for(int i=0;i<=nVerts-2;i++)
       {
           System.out.println("stnode-"+spanEdgeList[i].stNode+"-endnode-"+spanEdgeList[i].endNode+"-weight-"+spanEdgeList[i].edWeight);
       }
   }
   public void Relax(int u,int v,int w)
   {
      if(vertexList[v].dist>(vertexList[u].dist+w))
              {
                  vertexList[v].dist=vertexList[u].dist+w;  
                  vertexList[v].parent=vertexList[u].label;
                  
              }
   
   
   }
   
   
   public boolean bellManFord()
   {
       vertexList[0].dist=0;
       for(int i=0;i<nVerts-1;i++)
       {
           for(int j=0;j<nEdge;j++)
           {
              Relax(mymap.get(edgeList[j].stNode),mymap.get(edgeList[j].endNode),edgeList[j].edWeight);
           
           }
          
       
       }
       for(int i=0;i<nEdge;i++){
           if(vertexList[mymap.get(edgeList[i].endNode)].dist>vertexList[mymap.get(edgeList[i].stNode)].dist+edgeList[i].edWeight){
               return false;
           }
       }  
       return true;
   }
   
   public void displayBellmanFordGraphInfo()
   {
       for(int i=0;i<nVerts;i++){
           System.out.println("VertTex Label : "+vertexList[i].label
                   +" vertex Dist : "+vertexList[i].dist+"  Parent: "+vertexList[i].parent);
       }
       
   }

    public void prim()
       {
          vertexList[0].dist=0;
          myHeap=new Heap(nVerts,vertexList);
          myHeap.buildVMinHeap();

          //System.out.println(temp.label+" "+temp.dist);
          while(myHeap.isEmpty())
          {
              Vertex u=myHeap.heapVExtractMin();
              for(int i=0;i<=list[mymap.get(u.label)].gettop();i++)
              {
                  int v=list[mymap.get(u.label)].get(i);
                  if(myHeap.isInQueue(vertexList[v].label))
                  {
                      if(adjMat[mymap.get(u.label)][v]<vertexList[v].dist)
                      {
                          vertexList[v].parent=u.label;
                          vertexList[v].dist=adjMat[mymap.get(u.label)][v];
                      }
                  }
              }

          }
          displayPrim();
       }

       public void displayPrim()
       {
           System.out.println("Label->Parent->Distance");
           for(int i=0;i<nVerts;i++)
           {
               System.out.println(vertexList[i].label+" -> "+vertexList[i].parent+" -> "+vertexList[i].dist);
           }
       }
          public void doFloydWarshall(){

           int q[][]=new int [nVerts][nVerts];

           for(int i=0;i<nVerts;i++)
            {
                for(int j=0;j<nVerts;j++)
                {
                      if(floydWMat[i][j]==0&& i!=j)
                          q[i][j]=9999;
                      else
                          q[i][j]=floydWMat[i][j];

                }
            }

           for(int k=0;k<nVerts;k++)
           {
               System.out.println("Step "+(k+1)+" :");
               printFloydWarshall(q);
               printParentFloyd(floydPMat);

               System.out.println();
               for(int i=0;i<nVerts;i++)
               {
                   for(int j=0;j<nVerts;j++)
                   {
                       if(q[i][j]<=(q[i][k]+q[k][j]))
                       {
                           floydPMat[i][j]=floydPMat[i][j];
                       }
                       else
                           floydPMat[i][j]=floydPMat[k][j];
                        q[i][j]=minimum(q[i][j],q[i][k]+q[k][j]);
                   }
               }
           }
           System.out.println("Final Step: ");
           printFloydWarshall(q);
           printParentFloyd(floydPMat);

      }

       public int minimum(int i,int j)
       {
            if(i>=j)
                return j;
            else return i;
       }

       public void printFloydWarshall(int q[][]){
           System.out.println("Distance Matrix: ");
            for(int i=0;i<nVerts;i++)
            {
                for(int j=0;j<nVerts;j++)
                {

                    System.out.print(isInfinite(q[i][j])+" ");
                }
                System.out.println();
            }
           System.out.println();
        }
       public void printParentFloyd(int q[][])
       {
           System.out.println("Parent Matrix: ");
           for(int i=0;i<nVerts;i++)
            {
                for(int j=0;j<nVerts;j++)
                {

                    System.out.print(isNull(q[i][j])+" ");
                }
                System.out.println();
            }
           System.out.println();
       }


}
