from collections import deque

def create_adj_directed(edges):
    numOfNodes=1+max([e[0] for e in edges]+[e[1] for e in edges])
    adj_matrix=[[0]*numOfNodes for _ in range(numOfNodes)]
    for e in edges:
        adj_matrix[e[0]][e[1]]=1
    return adj_matrix
def create_adj_undirected(edges):
    numOfNodes=1+max([e[0] for e in edges]+[e[1] for e in edges])
    adj_matrix=[[0]*numOfNodes for _ in range(numOfNodes)]
    for e in edges:
        adj_matrix[e[0]][e[1]]=adj_matrix[e[1]][e[0]]=1
    return adj_matrix
edges=[[0,1],[1,2],[1,3],[2,4],[3,4],[5,7],[7,6]]

# for x in create_adj_directed(edges):
#     print(x)
# for x in create_adj_undirected(edges):
#     print(x)

def bfs(adj):
    n=len(adj)
    vis=set()    
    q=deque()
    for i in range(n):
        if i in vis:
            continue
        vis.add(i)
        q.appendleft(i)
        while q:
            el=q.pop()
            print(el,end=" ")
            for adjel in range(n):
                if adj[el][adjel] and adjel not in vis:
                    vis.add(adjel)
                    q.appendleft(adjel) 
    print() 
adj_undirected=create_adj_undirected(edges)
# bfs(adj_undirected)
adj_directed=create_adj_directed(edges)
# bfs(adj_directed)
#CODE FOR  dfs
def dfs(adj):
    n=len(adj)
    st=deque()
    vis=set()
    for node in range(n):
        if node in vis:
            continue
        vis.add(node)
        st.append(node)
        while st:
            el=st.pop()
            print(el,end=' ')
            for adjel in range(n):
                if adj[el][adjel] and not adjel in vis:
                    vis.add(adjel)
                    st.append(adjel)
    print()
# dfs(adj_directed)
# dfs(adj_undirected)
edges1=[[0,1],[1,5],[1,4],[1,3],[1,2],[5,6],[4,6],[3,7],[2,7],[6,8],[7,8],[8,6]]
# dfs(create_adj_directed(edges1))

# cycle detection
# cycle detection in undirected graph through bfs
def undirected_cycle_detect_bfs(adj):
    n=len(adj)
    q=deque()
    vis=set()
    for node in range(n):
        if node in vis:
            continue
        vis.add(node)
        q.appendleft([node,-1])
        while q:
            el,par=q.pop()
            for adjel in range(n):
                if adj[el][adjel]:
                    if adjel not in vis:
                        vis.add(adjel)
                        q.appendleft([adjel,el])
                    elif adjel!=par:
                        print(f"cycle found at {el}--->{adjel}")
                        return
    print("No cycle found")
undirected_cycle_detect_bfs(adj_undirected)
# cycle detection in undirected graph through dfs
def undirected_cycle_detect_dfs(adj):
    n=len(adj)
    st=deque()
    vis=set()
    for node in range(n):
        if node in vis:
            continue
        vis.add(node)
        st.append([node,node])
        while st:
            el,par=st.pop()
            for adjel in range(n):
                if adj[el][adjel]:
                    if adjel not in vis:
                        vis.add(adjel)
                        st.append([adjel,el])
                    elif adjel!=par:
                        print(f"cycle found at {el}--->{adjel}")
                        return
    print("No cycle found")
undirected_cycle_detect_dfs(adj_undirected)
# recursive cycle detection in undirected graph through dfs
def rec_cycle_detect_dfs(adj,vis,el,par):
    vis.add(el)
    for adjel in range(len(adj)):
        if adj[el][adjel]:
            if adjel not in vis:
                if rec_cycle_detect_dfs(adj,vis,adjel,el):
                    return True
            elif par!=adjel:
                print(f"cycle found at {el}--->{adjel}")
                return True
    return False
def undirected_rec_cycle_detection(adj):
    vis=set()
    n=len(adj)
    for node in range(n):
        if node in vis:
            continue
        if rec_cycle_detect_dfs(adj,vis,node,-1):
            return 
    print("No cycle found")
undirected_rec_cycle_detection(adj_undirected)
# recursive cycle detection in directed graph through dfs, can't be optimally using bfs
# once DFS finds a cycle, the stack will contain the nodes forming the cycle.The same is
# not true for BFS
def directed_dfs_rec(adj,vis,path,el):
    vis.add(el)
    path.add(el)
    for adjel in range(len(adj)):
        if adj[el][adjel]:
            if not adjel in vis:
                if directed_dfs_rec(adj,vis,path,adjel):
                    return True
            elif adjel in path:
                print(f"cycle found at {el}--{adjel}")
                return True
    path.remove(el)
    return False

def directed_detect_cycle_dfs_rec(adj):
    vis=set()
    n=len(adj)
    for node in range(n):
        if node in vis:
            continue
        if directed_dfs_rec(adj,vis,set(),node):
            return
    print("no cycle")
directed_detect_cycle_dfs_rec(adj_directed)
directed_detect_cycle_dfs_rec(create_adj_directed(edges1))