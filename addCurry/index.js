const add = function(...args) {
	const fn = function(...ar) {
		args.push(...ar);
		return fn;
	};
	
	fn.toString = function() {
		return args.reduce((cur, next) => (cur + next), 0);
	};
	
	return fn;
};

const test1 = add(1)(2)(3);

console.log(test1.toString());