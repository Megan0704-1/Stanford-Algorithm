import random
import copy
from collections import defaultdict

class Solution:
    def __init__(self, filename):
        self.path = filename
        self.ad_list = self.node_degree = None
        self.node_pool = set(range(1, 201))
        self.make_graph()

        self.graph = self.degree = self.pool = self.min_cut = None
        self.ans = 200000
        self.reset()

    def reset(self):
        self.graph = copy.deepcopy(self.ad_list)
        self.degree = copy.deepcopy(self.node_degree)
        self.pool = copy.deepcopy(self.node_pool)
        self.min_cut = 0

    def make_graph(self):
        self.ad_list = dict()
        self.node_degree = dict()
        with open(self.path, "r") as fh:
            for line in fh.readlines():
                line = line.split()
                vertex = int(line[0])
                self.ad_list[vertex] = dict()
                for edge in line[1:]:
                    self.ad_list[vertex][int(edge.strip())] = 1
                self.node_degree[vertex] = len(self.ad_list[vertex])

    def run(self, test=False):
        for _ in range(2500):
            if test: self.test()
            random.seed(random.choice(range(50000)))

            while len(self.degree) > 2:
                u, v = self.pick_vertex()
                self.fuse(u, v)
                self.pool.add(u)

            assert len(self.pool)==2, "invalid update op"
            u, v = self.pool
            assert self.degree[u] == self.degree[v], f"invalid counting op.\ndegree[{u}]: {self.degree[u]}\tdegree[{v}]: {self.degree[v]}"
            self.min_cut = self.degree[u]
            print(f"in {_}th iter, got: {self.min_cut}")
            self.ans = min(self.ans, self.min_cut)

            self.reset()
    
    def test(self):
        self.graph = {1:{2:1, 3:1},
                        2:{1:1, 3:1, 4:1},
                        3:{1:1, 2:1, 4:1},
                        4:{2:1, 3:1}}
        self.degree = {1:2, 2:3, 3:3, 4:2}
        self.pool = set(range(1, 5))

    def update_graph(self, u, v):
        for vertex, edges in self.graph.items():
            if vertex != u:
                if u in edges and v in edges:
                    edges[u] += edges[v]
                    edges.pop(v)
                elif v in edges:
                    edges[u] = edges[v]
                    edges.pop(v)
    
    def pick_vertex(self):
        try:
            u = random.choice(list(self.pool))
            v = random.choice(list(self.graph[u].keys()))
            u, v = (v, u) if v<u else (u, v)
        except:
            self.pick_vertex()
        else:
            self.pool.remove(u)
            self.pool.remove(v)
            return (u, v)
    
    def fuse(self, u, v):
        u_edges = self.graph[u]
        v_edges = self.graph[v]
        update_edges = defaultdict(int)
        degree_cnt = 0

        for edge, num in u_edges.items():
            if edge != v:
                update_edges[edge] += num
                degree_cnt += num
        for edge, num in v_edges.items():
            if edge != u:
                update_edges[edge] += num
                degree_cnt += num

        self.graph[u] = dict(update_edges)
        self.degree[u] = degree_cnt
        self.graph.pop(v)
        self.degree.pop(v)
        self.update_graph(u, v)

if __name__ == "__main__":
    path = "./assignment2.txt"
    ans = Solution(path)
    test = False
    ans.run(test)
    print(ans.ans)