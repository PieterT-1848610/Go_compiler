package main

func main()  {

	// Showcases If & For functionality
	//println("If & For")
	showcaseIfNFor()
	//println()
	// Showcases different types of returns
	//println("Returns")
	//showcaseReturns()
	//println()
	//println("Prints")
	//println()
	// Showcases all arithmetic operations
	//println("Arithmetic Operations")
	showcaseOperations()
	



	
}

func returnTrue() (a bool) {
	return true
}

func returnTrue1() bool {
	return false
}

func returnTrue2() (a bool){
	var b = true
	return b
}

func showcaseIfNFor(){
	var x = 5
	printInt(x)


	if x < 10{
		x = x +3
		printInt(x)
	}

	for ; x < 10 ; {
		x = x +3
		printInt(x)
	}

	var i int = 0
	for i; i < 5; i= i+1{
		printInt(i)
	}

	if(false){
		printInt(555555555)
	} else{
		printBool(false)
	}	

	
	printInt(i)
	

}


func showcaseReturns(){
	var over = returnTrue()
	printBool(over)
	over = returnTrue1()
	printBool(over)
	over = returnTrue2()
	printBool(over)
}

func showcaseOperations(){

	var q = (2 + 1 * 3 * (2 + 1) + 1) / 5
	printInt(q)

	var k = q / 2
	printInt(k)

	var p = !true
	printBool(p)
}






