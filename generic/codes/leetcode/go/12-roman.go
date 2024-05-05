package main

type romaninfo struct {
	num   int
	roman string
}

func intToRoman(num int) string {
	var m [7]romaninfo
	m[0] = romaninfo{1000, "M"}
	m[1] = romaninfo{500, "D"}
	m[2] = romaninfo{100, "C"}
	m[3] = romaninfo{50, "L"}
	m[4] = romaninfo{10, "X"}
	m[5] = romaninfo{5, "V"}
	m[6] = romaninfo{1, "I"}
	var roman string
	i := 0
	for num > 0 {
		count := num / m[i].num
		num %= m[i].num
		num = count
	}

	return roman
}
