const data = require('./data');

const dfs = (tree, cb) => {
  const queue = [tree];

  while (queue.length) {
    const node = queue.pop();

    if (cb(node)) {
      return node;
    }
    
    if (node.children) {
      queue.push(...node.children);
    }
  }
};

dfs(data, (node) => {
  console.log(node.id);
  return false;
});
