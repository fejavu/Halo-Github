function common(o) {
	var i = 0;
	if (typeof o == "object") {
		var j = 0;
		for (var k = 0; i < 10; k++) {
			console.log(k);
		}
		console.log(k);
	}
	console.log(j);
}

function judge() {
	var trueJudge = true;
	var falseJudge = false;
	var numVar = 1;

	return numVar ? trueJudge:falseJudge; 
}

function judgeNan() {
	var varia = NaN;

	return varia !== varia; //It will return true.
}