getName();
console.log(x);
console.log(getName);
console.log(arrowFunction);
console.log(getName2);

var x =7;

function getName(){
        console.log("Inside getName Function");
//        x = 10;
}

// Arrow Function
var arrowFunction = () => {
	console.log("Inside arrowFunction Function");
}

var getName2 = function () {
	console.log("Inside getName2 Function");
}
