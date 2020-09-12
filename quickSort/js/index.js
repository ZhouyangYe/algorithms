const swap = (i, j, arr) => {
  const temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
};

const partition = (low, high, arr) => {
  if (low >= high) return;

  let pivot = high;
  let i = low;
  for (let j = low; j <= high; j++) {
    if (arr[j] < arr[pivot]) {
      continue;
    }
    if (i === j) {
      i++;
      continue;
    }
    swap(i, j, arr);
    i++;
  }

  pivot = i;

  partition(low, pivot - 2, arr);
  partition(pivot, high, arr);
};

const quickSort = (arr) => {
  partition(0, arr.length - 1, arr);
};

const data = [1, 20, 13, 2, 8, 36, 15, 10];
quickSort(data);

console.log(data);
