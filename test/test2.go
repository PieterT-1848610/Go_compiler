package main
//Show the option for multiple return and params for functions


//multireturn
func multireturn() (int, int){
	return 3, 7
}

//multi params
func multiparam(x int, y int){
	x = x + 3
	printInt(x)
	y = y - 4
	printInt(y)
}

func main(){
	var x, y = multireturn()
	multiparam(x, y)
}
