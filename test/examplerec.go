package main

var q int = 0
var a int = 3


func main() {
	q = 5
	test(5)
	q = 7
}

func test(x int) {
	q = q + 1
	test(5)
}

