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

func rec(x int) int{
	printInt(x)
	if(x == 6){
		return x
	}else{
		rec(x + 1)
	}
}

func main() {
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
	var y = 1
	printInt(rec(y))

	var i = 0



	//test2 = plus(a, test)
	//printInt(test)
	//test = test + test2
	//test2 = test
	//return true
}

