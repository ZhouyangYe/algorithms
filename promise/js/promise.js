module.exports = function Promise(cb) {
  const PENDING = 0;
  const RESOLVED = 1;
  const REJECTED = 2;

  let state = PENDING;
  let result = null;

  const handlePromiseResult = (res, rej, resolve, reject) => {
    state = PENDING;
    result.then((a) => {
      state = RESOLVED;
      result = a;
      return;
    }, (a) => {
      state = REJECTED;
      result = a;
      return;
    });
    poll(res, rej, resolve, reject);
  };

  const resolve = (data) => {
    state = RESOLVED;
    result = data;
  };

  const reject = (data) => {
    state = REJECTED;
    result = data;
  };

  const poll = (res, rej, resolve, reject) => {
    setTimeout(() => {
      if (state === PENDING) {
        poll(res, rej, resolve, reject);
      } else if (state === RESOLVED) {
        if (result instanceof Promise) {
          handlePromiseResult(res, rej, resolve, reject);
          return;
        }
        resolve(res(result));
      } else {
        if (result instanceof Promise) {
          handlePromiseResult(res, rej, resolve, reject);
          return;
        }
        reject(rej(result));
      }
    }, 0);
  };

  cb(resolve, reject);

  this.then = (res, rej) => {
    return new Promise((resolve, reject) => {
      poll(res, rej, resolve, reject);
    });
  };

  this.catch = (callback) => {

  };
}
