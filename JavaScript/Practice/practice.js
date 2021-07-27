var startTime = new Date().getTime();
var num1 =0;
var num2 =0;
function add(a,b){
	num1 = a;
	num2 = b;
	return a+b;
}

console.log("\nAddition of two number is : ", add(5,10),"\n");
console.log("\nAddition of two number is : ", add(5.5,10),"\n");
add(10,20);
console.log("\nnum1 : ", num1, " num2 : ", num2, "\n");

var endTime = new Date().getTime();
console.log("Time Required [ms] = " + (endTime-startTime));
