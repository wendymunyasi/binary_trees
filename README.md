# Project Name
**0x1D. C - Binary trees**

## Author's Details
Name: *Wendy Munyasi.*

Email: *wendymunyasi@gmail.com*

Tel: *+254707240068.*

##  Requirements
*   Allowed editors: `vi`, `vim`, `emacs`.
*   All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
*   Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`.
*   All your files should end with a new line.
*   You are not allowed to use global variables.
*   No more than 5 functions per file.
*   The `main.c` files are used to test your functions, but you don’t have to push them to your repo.
*   The prototypes of all your functions should be included in your header file called `binary_trees.h`.
*   All your header files should be include guarded.

##  More Info
*   Please use this data structure for this project:
```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

```
**Binary Search Tree**
```
typedef struct binary_tree_s bst_t;
```
**AVL Tree**
```
typedef struct binary_tree_s avl_t;
```
**Max Binary Heap**
```
typedef struct binary_tree_s heap_t;
```

## Project Description
Learn about binary trees and binary search trees.

* **0. New node** - Write a function that creates a binary tree node. - `0-binary_tree_node.c`.
* **1. Insert left** - Write a function that inserts a node as the left-child of another node. - `1-binary_tree_insert_left.c`.
* **2. Insert right** - Write a function that adds a new node at the beginning of a `dlistint_t` list. - `2-binary_tree_insert_right.c`.
* **3. Delete** - Write a function that deletes an entire binary tree. - `3-binary_tree_delete.c`.
* **4. Is leaf** - Write a function that checks if a node is a leaf. - `4-binary_tree_is_leaf.c`.
* **5. Is root** - Write a function that checks if a given node is a root. - `5-binary_tree_is_root.c`.
* **6. Pre-order traversal** - Write a function that goes through a binary tree using pre-order traversal. - `6-binary_tree_preorder.c`.
* **7. In-order traversal** - Write a function that goes through a binary tree using in-order traversal. - `7-binary_tree_inorder.c`.
* **8. Post-order traversal** - Write a function that goes through a binary tree using post-order traversal. - `8-binary_tree_postorder.c`.
* **9. Height** - Write a function that measures the height of a binary tree. - `9-binary_tree_height.c`.
* **10. Depth** - Write a function that measures the depth of a node in a binary tree. - `10-binary_tree_depth.c`.
* **11. Size** - Write a function that measures the size of a binary tree. - `11-binary_tree_size.c`.
* **12. Leaves** - Write a function that counts the leaves in a binary tree. - `12-binary_tree_leaves.c`.
* **13. Nodes** - Write a function that counts the nodes with at least 1 child in a binary tree. - `13-binary_tree_nodes.c`.
* **14. Balance factor** - Write a function that measures the balance factor of a binary tree. - `14-binary_tree_balance.c`.
* **15. Is full** - Write a function that checks if a binary tree is full. - `15-binary_tree_is_full.c`.
* **16. Is perfect** - Write a function that checks if a binary tree is perfect. - `16-binary_tree_is_perfect.c`.
* **17. Sibling** - Write a function that finds the sibling of a node. - `17-binary_tree_sibling.c`.
* **18. Uncle** - Write a function that finds the uncle of a node. - `18-binary_tree_uncle.c`.


## Collaborate

To collaborate, reach me through my email address wendymunyasi@gmail.com.
