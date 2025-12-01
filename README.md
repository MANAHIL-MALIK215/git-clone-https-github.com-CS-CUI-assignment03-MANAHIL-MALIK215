


1. **BST Implementation**

* **Operations Implemented:**

  * Insert nodes into BST
  * Inorder, Preorder, Postorder traversals
  * Search for a key
  * Delete a node
  * Compute height of tree and specific nodes
* **Purpose:** Understand standard BST operations and traversal methods.

2. **BST to AVL Conversion**

* **Description:** Convert an unbalanced BST to a balanced AVL tree.
* **Approach:**

  1. Perform inorder traversal of BST to create a sorted array.
  2. Build a height-balanced AVL tree from the sorted array recursively.
* **Benefit:** Ensures O(log n) search time for previously unbalanced BSTs.

### 3. **AVL Tree Implementation**

* **Operations Implemented:**

  * Insert nodes with automatic rebalancing (LL, RR, LR, RL rotations)
  * Delete nodes with automatic rebalancing
  * Calculate height and balance factor of nodes
  * Inorder and reverse-inorder traversals
* **Purpose:** Learn self-balancing binary search trees and AVL rotation mechanics.

4. **Gaming Leaderboard (AVL Application)**
*Description:** Online gaming platform leaderboard using AVL trees for fast updates and search.
*Implemented Features:**

  * `insertScore(int score)` — Add a new player's score.
  * `removeScore(int score)` — Remove a player's score when they leave.
  * `printTopScores()` — Print scores in descending order using reverse in-order traversal.
*Benefit:** Demonstrates real-world AVL application for efficient dynamic ranking.

---


