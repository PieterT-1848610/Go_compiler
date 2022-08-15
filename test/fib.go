package main

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


func main(){
	var x = 10
	x = fib(x)
	printInt(x)
}
