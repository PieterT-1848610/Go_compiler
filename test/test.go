
func plus(a int, c int ) int {
	return a + c
} 

//testing if else statments
func testingIfs(){
	var x = 2.31
	printFloat(x)
	var test, a float32 = 100.0, 7.0
	var test2 = x + a
	printFloat(test2)
	if(a == 8.0){
		printInt(3)
	}else if(test2 == x){
		printFloat(3.12)
	}else{
		printInt(55)
	}

	var f = 0
	if(f == 0){
		printBool(true)
	}
}

//recursion test fibo
func fib(n int) int {
    if n == 0 {
        return 0
    } else if n == 1 {
		return 1
	} else {
		return fib(n-1) + fib(n-2)
	}
}

//check swithc assign
func assingCheck() {
	var y = 10
	var x = 5
	printInt(x)
	printInt(y)
	x, y = y,x 
	printInt(x)
	printInt(y)
}

//testing the different two for loops
func forLoop(x int){
	var i =  0
	var j = 0
	printInt(x)
	for j=0; j <=5; j = j + 1{
		i =  i + 1
		printInt(j)
		x = 4554
	}
	printInt(x)

	i = 0
	for i <= 10{
		if(i<=5){
			i = i+2
		}else{
			i = i + 1
		}
		printInt(i)
	}
	printInt(i)

}

//testing bool operation and, or, not
func testingOpr(){
	var x = true;
	var x2 = true;
	var y = false;
	var y2= false;

	if(x && x2){
		printBool(x)
	}
	if(x && y){
		printBool(y)
	}
	if(x||y){
		printBool(x)
	}
	if(y || !y2){
		printBool(x)
	}
}

func expo(value int, exponent int) int{
	var i = 0
	if(exponent == 0){
		return 0	
	}else if(exponent == 1){
		return value
	}

	var result int = value
	for i = 0; i < exponent; i = i +1{
		result = result * value
	}
	return result
}

func testReturn() int{
	var p = 99
	return p
}


func main() {
	//testingIfs()
	//var y int = 1
	//var x int = 6
	//var i = 6
	//var p = 6
	var z = testReturn()
	printInt(z)

	z = z +1
	//printInt(p)
	//var z = expo(x, y)
	//printInt(z)
	printInt(z)
	//testingOpr()
	
}

