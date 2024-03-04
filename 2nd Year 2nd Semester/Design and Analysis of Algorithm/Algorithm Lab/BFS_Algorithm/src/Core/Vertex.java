/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Core;

/**
 *
 * @author meta
 */
public class Vertex {
    public String label;
    public String color;
    public String parent;
    public int dist;
    public int inf=999;
    public int inTime;
    public int fTime;

    public Vertex(String name)
    {
        label=name;
        color="WHITE";
        parent=null;
        dist=inf;
        
    }
     public int getWeight()
    {
        return dist;
    }
    
}
