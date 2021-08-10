// Function bound with lexical environment of its parent
function x(){
	let a =10;
	function y(){
		console.log(a);
		function z()
		{
			console.log(a);
		}
		z();
	}
	y();
}
x();

function a(){
	let a_local_variable = 11;
	function a_local_function() {
		console.log("value of a local variable is ", a_local_variable);
	}
	a_local_variable = 12;
	return a_local_function;
}

a_global_function = a();
console.log(a_global_function);
a_global_function();

