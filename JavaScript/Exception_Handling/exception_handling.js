/*
Syntax Errors - also called parsing errors, occur at compile time in traditional programming languages and at interpret time in JavaScript
Runtime Errors - Runtime errors, also called exceptions, occur during execution (after compilation/interpretation).
Logical Errors - occur when you make a mistake in the logic that drives your script and you do not get the result you expected.
try...catch...finally Statement - can catch programmer-generated and runtime exceptions
*/

function myFunc() {
	var a = 100;
	var b = 0;
	try {
		let c = a/b;
		console.log(c);
		if(b==0){
			throw("Divice by zero error");
		}
		console.log("Value of variable a is : " + a );
	}
	catch ( e ) {
		console.log("Error: " + e.description );
		console.log("Error: " + e );
	}
	finally {
		console.log("Finally block will always execute!" );
	}
}

myFunc();
