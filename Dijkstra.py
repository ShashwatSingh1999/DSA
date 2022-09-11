# single source shortest path
adj =  [[0, 40, 0, 50, 0, 0],
        [0, 0, 30, 0, 0, 0],
        [0, 0, 0, 0, 20, 50],
        [0, 0, 10, 0, 40, 0],
        [0, 0, 0, 0, 0, 10],
        [0, 0, 0, 0, 0, 0]]
def dijkstra(adj,src):
    # numOfNodes
    n=len(adj)
    inf=99999999999999999999
    dist=[inf]*n
    isAspNode=[False]*n
    dist[src]=0
    for i in range(n):
        mindist=inf 
        next_asp_node=-1
        for node in range(n):
            if not isAspNode[node] and dist[node]<mindist:
                mindist=dist[node]
                next_asp_node=node

        isAspNode[next_asp_node]=True
        for adj_node in range(n):
            if not isAspNode[adj_node] and adj[next_asp_node][adj_node]>0:
                dist[adj_node]=min(dist[adj_node],dist[next_asp_node]+adj[next_asp_node][adj_node])
    print(dist)
dijkstra(adj,0)
from collections import defaultdict
  
  
# Function to return a default
# values for keys that is not
# present
def def_value():
    return "Not Present"
      
# Defining the dict
d = defaultdict(list)
d["a"].append(1)
d['a'].append(0)
d["b"] = 2
print(d)
print(d["a"])
print(d["b"])
print(d["c"])
print(d['d'])