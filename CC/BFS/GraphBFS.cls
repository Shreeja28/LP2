public class GraphBFS {
    public static void bfs(Map<String, List<String>> graph, String startNode) {
        Set<String> visited = new Set<String>();
        List<String> queue = new List<String>(); // using List as a queue
        
        queue.add(startNode);
        visited.add(startNode);
        
        System.debug('BFS Traversal:');
        
        while (!queue.isEmpty()) {
            String current = queue.remove(0); // dequeue from front
            System.debug(current);
            
            if (graph.containsKey(current)) {
                for (String neighbor : graph.get(current)) {
                    if (!visited.contains(neighbor)) {
                        visited.add(neighbor);
                        queue.add(neighbor); // enqueue
                    }
                }
            }
        }
    }
}