package main

// func plus(a int, c int ) int {
// 	return a + c
// } 


func compareValues(){
	var x, y, z = 5, 7, 5
	var comp = x == y
	printBool(comp)

	comp = x!=y
	printBool(comp)

	comp = x < y
	printBool(comp)

	comp = x >= z
	printBool(comp)

	comp = !comp
	printBool(comp)
}



func showingif(){
	if(true && true){
		printInt(1)
	}else{
		printInt(0)
	}
	if(false || false){
		printInt(0)
	}else{
		printInt(1)
	}

	if(true){
		if(!false){
			printInt(1)
		}else if(false){
			printInt(0)
		}else{
			printInt(0)
		}
	}else{
		printInt(0)
	}
}





func main() {
	compareValues()
	showingif()	
}

