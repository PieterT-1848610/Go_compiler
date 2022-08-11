package main;


// This function calls fib for 10
func main() {
    var q int = fib(11)

    
}
    
func fib(n int) int {
    if n == 0 || n == 1 {
        return 1
    } else {

        return fib(n - 1) + fib(n - 2)
    }
};



