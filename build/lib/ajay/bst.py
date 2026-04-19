class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root


def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=" ")
        inorder(root.right)


def preorder(root):
    if root:
        print(root.key, end=" ")
        preorder(root.left)
        preorder(root.right)


def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.key, end=" ")


# Example
if __name__ == "__main__":
    root = None
    for val in [50, 30, 70, 20, 40, 60, 80]:
        root = insert(root, val)

    print("Inorder:")
    inorder(root)
    print("\nPreorder:")
    preorder(root)
    print("\nPostorder:")
    postorder(root)