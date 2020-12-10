const data = require('./data');

const bfs = (tree, cb) => {
  const queue = [tree];

  while (queue.length) {
    const node = queue.shift();

    if (cb(node)) {
      return node;
    }
    
    if (node.children) {
      queue.push(...node.children);
    }
  }
};

bfs(data, (node) => {
  console.log(node.id);
  return false
});
