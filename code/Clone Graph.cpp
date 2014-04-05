/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        pmap.clear();
        return _cloneGraph(node);
    }
private:
    UndirectedGraphNode * _cloneGraph(UndirectedGraphNode *node) {
        if (pmap.find(node) != pmap.end()) {
            return pmap[node];
        }
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        pmap[node] = newnode;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            newnode->neighbors.push_back(_cloneGraph(node->neighbors[i]));
        }
        return newnode;
    }
    map<UndirectedGraphNode *, UndirectedGraphNode *> pmap;
};