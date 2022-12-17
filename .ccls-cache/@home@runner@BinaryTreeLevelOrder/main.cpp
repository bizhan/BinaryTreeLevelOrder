/*
https://www.educative.io/courses/grokking-the-coding-interview/xV7E64m4lnz
Given a binary tree, populate an array to represent its level-by-level
traversal. You should populate the values of all nodes of each level from left
to right in separate sub-arrays.

Since we need to traverse all nodes of each level before moving onto the next
level, we can use the Breadth First Search (BFS) technique to solve this
problem.

We can use a Queue to efficiently traverse in BFS fashion. Here are the steps of
our algorithm:

Start by pushing the root node to the queue.
Keep iterating until the queue is empty.
In each iteration, first count the elements in the queue (let’s call it
levelSize). We will have these many nodes in the current level. Next, remove
levelSize nodes from the queue and push their value in an array to represent the
current level. After removing each node from the queue, insert both of its
children into the queue. If the queue is not empty, repeat from step 3 for the
next level
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class TreeNode {
public:
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> traverse(TreeNode *root) {
  vector<vector<int>> result;
  queue<TreeNode*> queue;
  queue.push(root);


  // NOTE: Here queue is used to give an order to 
  while(!queue.empty()){
    cout<<queue.front()->value<<endl;
    // levelSize = number of the elements in the queue
    int levelSize = queue.size();
    // place holder for current level
    vector<int> currentLevel;
    // interate over all the elements in the queue
    for (int i = 0; i <levelSize; i++){
      // save the top to the currentLevel
      
      TreeNode *currentNode = queue.front();
      // remove one front element
      queue.pop();
      // add the node to the current level
      currentLevel.push_back(currentNode->value);
      // Add the left and right node the queue.
      if (currentNode->left != nullptr) queue.push(currentNode->left);
      if (currentNode->right != nullptr) queue.push(currentNode->right);
      
    }
    result.push_back(currentLevel);
  }
  
  return result;
}

int main() {
  std::cout << "Hello World!\n";
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(10);
  root->right->right = new TreeNode(5);
  auto result = traverse(root);
  for (auto vec: result){
    for (auto num: vec)
      cout<<num<<endl;
  }

  // for (auto vec: )
  
  
}