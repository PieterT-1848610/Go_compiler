package main

//example for loops
func forLoop(x int){
	var i =  0
	var j = 0
	printInt(x)
	for j=0; j <=5; j++{
		printInt(j)
		x = 4554
	}
	printInt(x)

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

func main(){
	var x = 3
	forLoop(x)
	printInt(x)
}
