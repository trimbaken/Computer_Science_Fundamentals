function send_event(callback_function) {
	let event_count =0;
	console.log(++event_count, " Event Received :");
	callback_function();
}
var up_event = function up_event_callback_function() {
	console.log("Up event is received");
}
send_event(up_event);
var down_event = function down_event_callback_function() {
	console.log("Down event is received");
}
send_event(down_event);

send_event(function none_event_callback_function(){
	console.log("None event is received");
});
function timeout_execution(){
	let time = 0;
	setTimeout(function(){
		time += 2000;
		console.log("Timeout Function is called and current time is ", time);
	},2000);
}

timeout_execution();
