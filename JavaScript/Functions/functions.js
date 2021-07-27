a();
//console.log(b);
// b();


// Function Statement or Declaration
function a() {
	console.log("Function A is called");
}
a();

// Function Expression
var b = function(){
	console.log("Function B is called");
}
b();
function c(){
	return function(){
		console.log("Function C is called");
	}
}
var d = c();
d();

function func1(temp){
	temp();
}
func1(b);

// Anonymous Function - function without name
/*
function anonymous(){
	console.log("Function anonymous is called");
}
*/

// Named Function Expression
var b = function named_function (){
	console.log("Function named_function is called");
}
b();
