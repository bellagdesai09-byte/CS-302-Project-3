# Design Decisions

Here is a breakdown of a few specific choices I made while putting this tree together:

**Keeping the Tree Balanced**
I realized pretty quickly that if I just inserted my 8 songs in pure alphabetical order, the BST would basically just become a straight line (a degenerate tree) leaning to the right, which ruins the search efficiency. To fix this and pass the `isBalanced()` check, I deliberately inserted "Hotline Bling" first so it would become the root node. Then, I alternated inserting songs that came before and after it alphabetically to force the tree to build out evenly on both the left and right sides.

**Handling Node Deletion**
The `remove()` function was definitely the hardest part to design because you can't just delete a node and leave a hole in the tree. I broke it down into three specific scenarios:
1. **Leaf Nodes:** Easy. Just delete it and set the parent's pointer to null.
2. **One Child:** I wrote logic to bypass the deleted node. The parent pointer just reaches around the deleted node and connects directly to the grandchild.
3. **Two Children:** This was tricky. Instead of deleting the node outright, I wrote a helper function to go into the right subtree and find the "inorder successor" (the leftmost node). I copied that successor's data into the target node, and then recursively deleted the duplicate leaf at the bottom.

**Avoiding Standard Libraries**
To stick to the core concepts of the class, I completely avoided using libraries like `<cmath>` or `<algorithm>`. Instead of using `std::max()` to figure out tree height, or `std::abs()` to check for balance, I just wrote out the native `if/else` logic and basic math to compare the left and right sides.

**Memory Management**
To make sure I didn't leave any memory leaks, I set up a `destroyTree()` function that uses a Post-Order traversal. By checking the left child, then the right child, and *then* the root, it guarantees that all the children are safely deleted before their parent is wiped out. I hooked this up to the `clear()` function and the destructor.