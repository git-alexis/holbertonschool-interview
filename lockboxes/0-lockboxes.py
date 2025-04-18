#!/usr/bin/python3
def canUnlockAll(boxes):
	visited = set()
	stack = [0]

	while stack:
		box_index = stack.pop()
		if box_index not in visited:
			visited.add(box_index)
			for key in boxes[box_index]:
				if key < len(boxes):
					stack.append(key)

	return len(visited) == len(boxes)
