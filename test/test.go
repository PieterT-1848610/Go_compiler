//package main

// func plus(a int, b int) int {
// 	return a
// }

// func main() {
// 	var test, a, b int = 1, 5, 8
// 	var test2, f = 2, true
// 	test = a + test2
// 	var test3 = test
// 	//test2 = test + test2
// }}


//package main

func plus(a int, c int ) int {
	return a + c
} 

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
}

func fib(n int) int {
    if n == 0 {
        return 0
    } else if n == 1 {
		return 1
	} else {
		return fib(n-1) + fib(n-2)
	}
}

func assingCheck() {
	var y = 10
	var x = 5
	printInt(x)
	printInt(y)
	x, y = y,x 
	printInt(x)
	printInt(y)
}

func forLoop(x int){
	var i =  0
	var j = 0
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


func main() {
	//testingIfs()
	var y= 10
	var x int = 6
	var t bool = true
	var z bool = !t
	if(!t){
		printInt(6)
	}else{
		printInt(8)
	}
	printBool(t)
	printBool(z)
	//printInt(x)
	x  = x * 8
	printInt(x)
	if(x > 9){
		if(y >= 10){
			printBool(true)
		}
		printInt(0)
	}else{
		printInt(1)
	}
	y = x/6
	printInt(y)
	testingOpr()
	//x = fib(x)
	//assingCheck()
	
	//test2 = plus(a, test)
	//printInt(test)
	//test = test + test2
	//test2 = test
	//return true
}

