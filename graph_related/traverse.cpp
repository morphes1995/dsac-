
/**
     * 图的宽度优先遍历
     */
    public void bfs(GraphNode root){
        if (root==null){
            return;
        }

        LinkedList<GraphNode> queue = new LinkedList<GraphNode>(); // 使用队列实现
        HashSet<GraphNode> nodesTraversed = new HashSet<GraphNode>();
        // 记录已经遍历过的节点，对于无向图或有环的有向图，用来解决循环遍历问题
        queue.addFirst(root);
        nodesTraversed.add(root);

        while(!queue.isEmpty()){
            GraphNode node = queue.removeLast();
            System.out.println(node.value);
            node.nexts.forEach(n->{
                if(!nodesTraversed.contains(n)){
                    nodesTraversed.add(n);
                    queue.addFirst(n);
                }
            });
        }
    }

    /**
     * 图的深度优先遍历
     */
    public void dfs(GraphNode root){
        if(root==null){
            return;
        }
        LinkedList<GraphNode> stack = new LinkedList<>();
        HashSet<GraphNode> nodesTraversed = new HashSet<>();
        stack.addFirst(root);
        nodesTraversed.add(root);

        System.out.println(root.value); //  在节点首次加入到stack 中的时候访问其中的数据

        while(!stack.isEmpty()){
            // 先将栈顶的节点移除，如果该节点存在没有访问的相邻节点，则将该节点和相邻节点压入栈中
            // 栈中始终存放着 根节点到当前正在遍历节点路径上的所有节点
            GraphNode node = stack.removeFirst();
            for(GraphNode n:node.nexts){
                if(!nodesTraversed.contains(n)){
                    nodesTraversed.add(n);
                    stack.addFirst(node);// 将node重新加入到stack中
                    stack.addFirst(n);   // 同时将其没有访问的相邻节点加入到stack中
                    System.out.println(n.value);
                    break; // 从该子节点开始新的深度优先遍历流程
                }
            }
        }
    }

    /**
     * 图结构的拓扑排序
     * 首先统计图中所有节点的入度值， 将入度值为0的节点放入一个队列中
     * 遍历入度为0的节点，然后将与该节点相邻的节点的入度值减一，
     * 如果与该节点相邻的节点的入度值减一后为0，则将节点加入遍历队列，作为下一轮待遍历的节点
     */

    public void topologySort(Graph graph){

        if(graph==null){
            return ;
        }

        LinkedList<GraphNode> queue = new LinkedList<>();
        HashMap<GraphNode, Integer> nodesInDegreeMap = new HashMap<>();
        for(GraphNode node : graph.nodes.values()){
            nodesInDegreeMap.put(node,node.inDegree);
            if(node.inDegree==0){
                queue.addFirst(node);
            }
        }

        while (!queue.isEmpty()){
            GraphNode node = queue.removeLast();
            System.out.println(node.value);


             // 通过图中的edges变量找到相邻的节点
//            for(GraphEdge edge:node.edges){
//                GraphNode relatedNodes = edge.to;
//                int newInDegree = nodesInDegreeMap.get(relatedNodes) - 1;
//                nodesInDegreeMap.put(relatedNodes,newInDegree);
//                if (newInDegree==0){
//                    queue.addFirst(relatedNodes);
//                }
//            }n

            // 通过图中的nexts变量找到相邻的节点
            for(GraphNode n:node.nexts){
                int newInDegree = nodesInDegreeMap.get(n) - 1; // 更新相邻节点的indegree
                nodesInDegreeMap.put(n,newInDegree);
                if (newInDegree==0){
                    queue.addFirst(n);
                }
            }
        }
    }