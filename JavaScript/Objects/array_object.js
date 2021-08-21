// stores a fixed-size sequential collection of elements of the same type. Useful to think of an array as a collection of variables of the same type.


let fruits = new Array("Banana", "Apple", "Mango");

let fruits_1 = ["Banana", "Apple", "Mango"];
let i =0;
for(i=0; i<fruits.length; i++)
{
	console.log(fruits[i]);
}
for(i=0; i<fruits_1.length; i++)
{
	console.log(fruits_1[i]);
}

let marks = [62,78, 54,89,42];

for(i =0; i<marks.length; i++)
{
	console.log(marks[i]);
}

Array.prototype.every = function(fun){
	for(i=0; i<this.length;i++)
	{
		if(!fun(this[i]))
			return false;
	}
	return true;
}
function check_passing_criteria(mark)
{
	return (mark>=60);
}

let is_pass = marks.every(check_passing_criteria);
console.log("Students Marks : ", marks);
if(!is_pass){
	console.log("Student Fail in Exam ");
}
else {
	console.log("Student Pass in Exam");
}

let student_1_marks = [60,65,89,90];
is_pass = student_1_marks.every(check_passing_criteria);
console.log("Students Marks :", student_1_marks);
if(!is_pass){
	console.log("Student Fail in Exam ");
}
else {
	console.log("Student Pass in Exam");
}



