const deepClone = (obj, map = new Map()) => {
	if (typeof obj !== 'object') {
		return obj;
	}
	
	if (map.get(obj)) {
		return map.get(obj);
	}

	const result = {};
	map.set(obj, result);

	for (key in obj) {
		result[key] = deepClone(obj[key], map);
	}
	
	return result;
};

const data = { a: 1, b: { d: 5, e: 6 }, c: 3 };

const data2 = { a: data };

data.f = data2;

const test = deepClone(data);

console.log(test);