package main



func assingCheck() {
	var y = 10
	var x = 5
	printInt(x)
	printInt(y)
	x, y = y,x 
	printInt(x)
	printInt(y)
}



//example of different assings
func assignOptions(){
	var x float32 = 2.0
	x += 5.5
	printFloat(x)
	x -= 3.5
	printFloat(x)
	x *= 4.0
	printFloat(x)
	var y = 10 % 3
	printInt(y)
}


//show operations
func operationsOptions(){
	var x = (2 + 5 * 7 + (-3))
	var y = x/2
	var z = 10%3
	printInt(x)
	printInt(y)
	printInt(z)
}







func main(){
	assignOptions()
	operationsOptions()
	
	assingCheck()
}
