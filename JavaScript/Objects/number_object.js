// The Number object represents numerical date, either integers or floating-point numbers
var int_number = Number(10);
var float_number = Number(10.11);
var binary_number = Number(0);

binary_number = int_number;
binary_number = true;
float_number = 10.101;


console.log("int_number :", int_number);
console.log("float_number :", float_number);
console.log("binary_number :", binary_number);

console.log("MAX_VALUE of Number :", Number.MAX_VALUE);
console.log("MIN_VALUE of Number :", Number.MIN_VALUE);

var str = "ABC " + 10.11 + " Str";
var str1 = "ABC " + float_number.toString() + " Str";
console.log(str);
console.log(str1);
console.log("to string ", float_number.toString());

console.log("Value of :", float_number.valueOf());
