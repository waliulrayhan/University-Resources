package binarysearchtree;

public class BST_operation {
    Node insert(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.value) {
            root.left = insert(root.left, key);
        } else if (key > root.value) {
            root.rigth = insert(root.rigth, key);
        }
        return root;
    }

    public void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.println(root.value + "->");
            inorder(root.rigth);
        }
    }

    public void preorder(Node root) {
        if (root != null) {
            System.out.println(root.value + "->");
            inorder(root.left);
            inorder(root.rigth);
        }
    }

    public void postorder(Node root) {
        if (root != null) {
            inorder(root.left);
            inorder(root.rigth);
            System.out.println(root.value + "->");
        }
    }

    public void treeMinimum(Node root) {
        while (root.left != null) {
            root = root.left;
        }
        System.out.println(root.value);
    }

    public int Minimum(Node root) {
        while (root.left != null) {
            root = root.left;
        }
        return root.value;
    }

    public void treeMaximum(Node root) {
        while (root.rigth != null) {
            root = root.rigth;
        }
        System.out.println(root.value);
    }

    public void successor(Node root, int key) {
        if (root.value == key) {
            if (root.rigth != null) {
                root = root.rigth;
                while (root.left != null) {
                    root = root.left;
                }
                // System.out.println("Successor is " + root.value);
                if (root != null)
                    System.out.println("Successor is " + root.value);
                else
                    System.out.println("No Successor");
            }
        } else if (root.value > key) {
            System.out.println("Successor is " + root.value);
        }
    }

    public void predecessor(Node root, int key){
        if (root.value == key) {
            if (root.left != null) {
                root = root.left;
                while (root.rigth != null) {
                    root = root.rigth;
                }
                // System.out.println("Successor is " + root.value);
                if (root != null)
                    System.out.println("Predecessor is " + root.value);
                else
                    System.out.println("No Predecessor");
            }
        } else if (root.value > key) {
            System.out.println("Predecessor is " + root.value);
        }
    }

    Node delete_rec(Node root, int key) {
        if (root == null)
            return root;
        else if (root.value > key) {
            root.left = delete_rec(root.left, key);
            //System.out.println("left root is"+root.left);
        } else if (root.value < key) {
            root.rigth = delete_rec(root.rigth, key);
            //System.out.println("rigth root is"+root.left);
        } else {
            if (root.left == null)
                //System.out.println("rigth root is"+root.rigth);
                return root.rigth;
            else if (root.rigth == null)
                //System.out.println("rigth root is"+root.left);
                return root.left;

            root.value = Minimum(root.rigth);
            root.rigth = delete_rec(root.rigth, root.value);
        }
        return root;
    }

    public void delete_key(Node root, int key) {
        root = delete_rec(root, key);
    }

}
