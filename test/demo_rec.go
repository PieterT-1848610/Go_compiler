package main;


func main() {
    var q int = fib(12)
    printInt(q)  
}
    
func fib(n int) int {
	if n == 0{
		return 0
	}
    if n == 1 || n == 2 {
        return 1
    } else {
        return fib(n - 1) + fib(n - 2)
    }
};



