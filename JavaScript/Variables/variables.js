
console.log("var_a :", var_a);
//console.log("let_a :", let_a); // since let_a is stored in temporary memory and not in global context it is not defined , accessing before initialization is Temporal Dead Zone
//console.log("const_a :",  const_a); // since const_a is stored in temporary memory and not in global context it is not defined, accessing before initialization is Temporal Dead Zone

var var_a =10;

let let_a =100;

const const_a = 1000;

console.log("var_a :", var_a);
console.log("let_a :", let_a);
console.log("const_a :",  const_a);

var var_a = 20;
console.log("var_a :", var_a);
//let let_a =100; // re-decleration of let is not possible
//const const_a = 1000; // re-decleration of const is not possible

let_a = 200;
console.log("let_a :", let_a);

//const_a = 2000; // can not assign to const variable
//console.log("const_a :",  const_a);

/*
 * Priority : const, let, var
*/
