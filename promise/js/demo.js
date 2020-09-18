const Promise = require('./Promise');

const test = new Promise((res, rej) => {
  setTimeout(() => {
    res('hello');
  }, 3000);
});

test.then(data => {
  console.log('resolved', data);
  return '111';
}).then(data => {
  console.log(data);
  return new Promise((res) => {
    setTimeout(() => {
      console.log('ttt1');
      res(new Promise(re => {
        setTimeout(() => {
          re('done');
        }, 2000);
      }));
    }, 2000);
  });
}).then(data => {
  console.log('finally', data);
});
const aaa = NaN;

console.log(aaa === aaa);
