
function add_price(price) {
	this.price = price;
}
var book = new Object();
book.title = "JavaScript Tutorial";
book.author = "ABC";
book.add_price = add_price;

console.log("Book Title : ", book.title);
console.log("Book Author : ", book.author);

book.add_price(100);
console.log("Book price : ", book.price);

function book_function(title, author){
	this.title = title;
	this.author = author;
	this.add_price = add_price;
}

book_obj = new book_function("Javascript", "XYZ");
book_obj.add_price(200);
console.log("Book Title : ", book_obj.title);
console.log("Book Author : ", book_obj.author);
console.log("Book price : ", book_obj.price);
