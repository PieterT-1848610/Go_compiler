package main

//exponent function combo params and return
func expo(value int, exponent int) int{
	var i = 0
	if(exponent == 0){
		return 0	
	}else if(exponent == 1){
		return value
	}

	var result int = value
	for i = 1; i < exponent; i = i +1{
		result = result * value
	}
	return result
}

func main(){
	var value, exponent = 5, 3
	var result = expo(value, exponent)
	printInt(result)
}
