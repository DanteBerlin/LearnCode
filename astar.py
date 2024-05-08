import sys

visited = []
vertices = []
edges = []
h = []
cost = 0
goal = 0

n = int(input("Enter the number of vertices: "))

# Input vertices
for i in range(n):
    vertices.append(input("Enter vertex: "))

# Input edges
for i in range(n):
    print(f"Enter costs for edges connected to vertex {vertices[i]} (enter 0 if no edge):")
    x = list(map(int, input().split()))
    edges.append(x)

# Input heuristic values
print("Enter heuristic values for each vertex:")
for i in range(n):
    h.append(int(input(f"Heuristic value for {vertices[i]}: ")))

# Input goal state
goal_vertex = input("Enter goal state vertex: ")

# Find index of goal vertex
goal = vertices.index(goal_vertex)

visited.append(vertices[0])

def astar(vertex_index):
    global cost

    min_cost = sys.maxsize
    min_index = 0
    
    # Check each neighboring vertex
    for j in range(n):
        if edges[vertex_index][j] != 0 and vertices[j] not in visited:
            total_cost = edges[vertex_index][j] + h[j]  # f(n) = g(n) + h(n)

            if total_cost < min_cost:
                min_cost = total_cost
                min_index = j

    visited.append(vertices[min_index])
    cost += edges[vertex_index][min_index]  # Update cost with the edge cost
    print(f"Visited: {vertices[min_index]} with total cost: {cost}")

    if min_index != goal:  # Check if goal state is reached
        astar(min_index)
    else:
        print("Goal found.")

astar(0)  # Start from the first vertex
print("Path:", visited)
print("Total cost:", cost)
