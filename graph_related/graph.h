//
// Created by baoyu.jiang on 2025/1/7.
//

#ifndef GRAPH_H
#define GRAPH_H

/**
 * general graph structure
 */
public class Graph {

    public HashMap<Integer,GraphNode> nodes;
    public HashSet<GraphEdge>  edges;

    public Graph(){
        nodes = new HashMap<Integer, GraphNode>();
        edges = new HashSet<GraphEdge>();
    }

}

class GraphNode{
    public int value;
    public int inDegree;
    public int outDegree;
    public ArrayList<GraphNode> nexts;
    public ArrayList<GraphEdge> edges;

    public GraphNode(){
        nexts = new ArrayList<GraphNode>();
        edges = new ArrayList<GraphEdge>();
    }
}

class GraphEdge{
    public int weight;
    public GraphNode from;
    public GraphNode to;

    public GraphEdge(){
    }

}




#endif //GRAPH_H
