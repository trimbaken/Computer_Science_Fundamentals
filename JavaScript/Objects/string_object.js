// The String object lets you work with a series of characters.

var str_object = String("ABC");
var str1_object = String("ABC XYZ");
var str2_object = String("ABC XYZ ABC XYZ");


console.log("str_object : ", str_object);
console.log("length : ", str_object.length);

console.log("charAt ", str_object.charAt(0));
console.log("charCodeAt ", str_object.charCodeAt(0));

console.log("concat : ", str_object.concat(" ", str1_object));

console.log("indexOf : ", str1_object.indexOf("X"));
console.log("indexOf : ", str1_object.indexOf("BC"));
console.log("lastIndexOf : ", str_object.concat(" ", str1_object).lastIndexOf("ABC"));


console.log("localeCompare :", str1_object.localeCompare("ABC")); // 0 - equal, -1 - smaller, 1 - higher

console.log("slice : ", str1_object.slice(1, -1));

console.log("split : ", str2_object.split(" ", 3));
console.log("split : ", str2_object.split("ABC", 2));

console.log("substr : ", str2_object.substr(1,2));
console.log("substr : ", str2_object.substr(-2,2));
console.log("substr : ", str2_object.substr(1));

console.log("substring : ", str2_object.substring(1,2));
console.log("substring : ", str2_object.substring(-2,2));
console.log("substring : ", str2_object.substring(1));

console.log("valueOf : ", str2_object.valueOf());
