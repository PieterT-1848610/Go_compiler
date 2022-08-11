package main


func main(){

	var x string = "StartString";
	println(x);
	x = "ChangedValue"
	println(x);

	var k = "TestString"
	println(k)
	k = "ChangedValue2"
	println(k)

	var y string
	println(y)

	println(test(x))

	println(test1("InLoop1", "InLoop1", 0))

	println(test2())

}

func test(a string) (string, string) {
	println(a)
	return "RetValue1", "RetValue2"
}

func test1(c, d string, q int) (a, b string){
	var i = 0
	for i = q; i < 5; i++{
		println(i, c, d)
	}
	return "FunctionValue1", d
}

func test2() (bool, int, string){
	return true, 233, "MultiTypedReturn"
}