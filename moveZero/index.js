const solve = (arr) => {
	for (let i = arr.length - 1; i >= 0; i--) {
		if (arr[i] === 0) {
			arr.splice(i, 1);
			arr.push(0);
		}
	}
}

const data = [0,0,0,3,12];
console.log(data);
solve(data);
console.log(data);