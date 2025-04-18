#!/usr/bin/python3
"Function that determines if all the boxes can be opened"


def canUnlockAll(boxes):
    visited = set()
    keysStack = [0]

    while keysStack:
        box_index = keysStack.pop()
        if box_index not in visited:
            visited.add(box_index)
            for key in boxes[box_index]:
                if key < len(boxes):
                    keysStack.append(key)

    return len(visited) == len(boxes)
