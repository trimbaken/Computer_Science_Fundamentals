// A regular expression is an object that describes a pattern of characters.
// exec() - Executes a search for a match in its string parameter.

var str = "Javascript is an interesting scripting language";
var re = new RegExp( "script", "g" );
var result = re.exec(str);
console.log("Test 1 - returned value : " +  result);

re = new RegExp( "/", "g" );
var result = re.exec(str);
console.log("Test 2 - returned value : " +  result);


// test() - The test method searches string for text that matches regexp. If it finds a match, it returns true; otherwise, it returns false.

var re = new RegExp( "script", "g" );
var result = re.test(str);
console.log("Test 1 - returned value : " +  result);

re = new RegExp( "/", "g" );
var result = re.test(str);
console.log("Test 2 - returned value : " +  result);
