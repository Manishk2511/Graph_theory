void dfs(vector<Node*> &visited,Node* copy,Node *node)
{
    visited[copy->val]=copy;
    for(auto u:node->neighbors)
    {
        if(visited[u->val]==NULL)
        {
            Node *newnode=new Node(u->val);
            copy->neighbors.push_back(newnode);
            dfs(visited,newnode,u);
        }
        else
        {
            copy->neighbors.push_back(visited[u->val]);
        }
    }
}
class Solution {
public:
    map<int,Node*> visited;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(visited[node->val]!=NULL)
            return visited[node->val];
        Node* newnode=new Node(node->val);
        visited[node->val]=newnode;
        for(auto u:node->neighbors)
        {
            newnode->neighbors.push_back(cloneGraph(u));
        }
        return newnode;
    }
};