/*
Design an algorithm to find the smallest K numbers in an array.
*/

const smallestK = function(arr, k) {
	if (k === 0) return [];
	
    const swap = (data, i, j) => {
        const temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    };

    const partition = (data, low, high) => {
        if (low >= high) {
            return;
        }

        const pivot = high;

        let i = low;
        let j = low;

        while (j <= high) {
            if (data[j] < data[pivot]) {
				if (i !== j) {
					swap(data, i, j);
				}
				i++;
            }
			j++
        }
		
		swap(data, i, pivot);

        return i > low ? i - 1 : low;
    };

    const sort = (data, low, high) => {
        const index = partition(data, low, high);

        if (index === k - 1) {
            return data.slice(0, k);
        }

        if (index < k - 1) {
            return sort(data, index + 1, high);
        }

        if (index > k - 1) {
            return sort(data, low, index);
        }
    };

    return sort(arr, 0, arr.length - 1);
};

console.log(smallestK([1,2,3], 0));
console.log(smallestK([1,3,5,7,2,4,6,8], 4));