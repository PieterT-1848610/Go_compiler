package main


func main()  {
	printInt(test1())
	
}

func test1() int {
	if true{
		return 5
	} else if true {
		return 5
	}
	return 3
	
}

func test() int {
	if false {
		if false{
			return 0
		} else if true {
			return 2
		} else{
			return 2
		}
	} else if true{
		if true {
			return 3
		} else{
			return 6
		}
		
	} else{
		return 3
	}

}
