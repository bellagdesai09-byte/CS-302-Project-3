# Abstract Data Type (ADT) Design

For this project, I broke the architecture down into three main pieces: the data itself, the generic tree engine, and a wrapper class to tie it all together.

**The Song Class (The Data)**
This is basically just the payload. It holds the title, artist, and year for each track. The most important thing I did here was overload the `<` and `==` operators so that they only look at the song's title. This guarantees that whenever a `Song` gets passed into a data structure, it automatically knows how to sort itself alphabetically. 

**The BST Class (The Engine)**
I built the Binary Search Tree as a template (`template<class ItemType>`). I wanted to make sure the tree itself had no idea it was holding music—it just knows how to sort generic items that have comparison operators. I kept all the messy recursive helper functions (like `addHelper` and the traversals) hidden in the `protected` section. That way, whoever is using the tree can't accidentally pass in a bad memory pointer and break the whole structure. 

**The MusicLibrary Class (The Wrapper)**
This acts as the middleman between the `main` driver file and the BST. It inherits from the `BinaryTreeInterface` that was provided to us. Instead of rewriting tree logic here, this class just holds a private instance of my `BST<Song>` and passes commands down to it. For example, if you call `library.add()`, it just hands the song over to the BST's add method to do the actual work.