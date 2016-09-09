# Conformance of jsmn (C)

## 1. Parse Validation

* `../data/jsonchecker/fail03.json` is invalid but was mistakenly deemed valid.
~~~js
{unquoted_key: "keys must be quoted"}
~~~

* `../data/jsonchecker/fail04.json` is invalid but was mistakenly deemed valid.
~~~js
["extra comma",]
~~~

* `../data/jsonchecker/fail05.json` is invalid but was mistakenly deemed valid.
~~~js
["double extra comma",,]
~~~

* `../data/jsonchecker/fail06.json` is invalid but was mistakenly deemed valid.
~~~js
[   , "<-- missing value"]
~~~

* `../data/jsonchecker/fail07.json` is invalid but was mistakenly deemed valid.
~~~js
["Comma after the close"],
~~~

* `../data/jsonchecker/fail09.json` is invalid but was mistakenly deemed valid.
~~~js
{"Extra comma": true,}
~~~

* `../data/jsonchecker/fail10.json` is invalid but was mistakenly deemed valid.
~~~js
{"Extra value after close": true} "misplaced quoted value"
~~~

* `../data/jsonchecker/fail11.json` is invalid but was mistakenly deemed valid.
~~~js
{"Illegal expression": 1 + 2}
~~~

* `../data/jsonchecker/fail12.json` is invalid but was mistakenly deemed valid.
~~~js
{"Illegal invocation": alert()}
~~~

* `../data/jsonchecker/fail13.json` is invalid but was mistakenly deemed valid.
~~~js
{"Numbers cannot have leading zeroes": 013}
~~~

* `../data/jsonchecker/fail14.json` is invalid but was mistakenly deemed valid.
~~~js
{"Numbers cannot be hex": 0x14}
~~~

* `../data/jsonchecker/fail16.json` is invalid but was mistakenly deemed valid.
~~~js
[\naked]
~~~

* `../data/jsonchecker/fail19.json` is invalid but was mistakenly deemed valid.
~~~js
{"Missing colon" null}
~~~

* `../data/jsonchecker/fail20.json` is invalid but was mistakenly deemed valid.
~~~js
{"Double colon":: null}
~~~

* `../data/jsonchecker/fail21.json` is invalid but was mistakenly deemed valid.
~~~js
{"Comma instead of colon", null}
~~~

* `../data/jsonchecker/fail22.json` is invalid but was mistakenly deemed valid.
~~~js
["Colon instead of comma": false]
~~~

* `../data/jsonchecker/fail23.json` is invalid but was mistakenly deemed valid.
~~~js
["Bad value", truth]
~~~

* `../data/jsonchecker/fail24.json` is invalid but was mistakenly deemed valid.
~~~js
['single quote']
~~~

* `../data/jsonchecker/fail25.json` is invalid but was mistakenly deemed valid.
~~~js
["	tab	character	in	string	"]
~~~

* `../data/jsonchecker/fail27.json` is invalid but was mistakenly deemed valid.
~~~js
["line
break"]
~~~

* `../data/jsonchecker/fail29.json` is invalid but was mistakenly deemed valid.
~~~js
[0e]
~~~

* `../data/jsonchecker/fail30.json` is invalid but was mistakenly deemed valid.
~~~js
[0e+]
~~~

* `../data/jsonchecker/fail31.json` is invalid but was mistakenly deemed valid.
~~~js
[0e+-1]
~~~


Summary: 11 of 34 are correct.

## 2. Parse Double


Summary: 66 of 66 are correct.

## 3. Parse String

* `["Hello\nWorld"]`
  * expect: `"Hello
World"` (length: 11)
  * actual: `"Hello\nWorld"` (length: 12)

* `["Hello\u0000World"]`
  * expect: `"Hello\0World"` (length: 11)
  * actual: `"Hello\u0000World"` (length: 16)

* `["\"\\/\b\f\n\r\t"]`
  * expect: `""\/
	"` (length: 8)
  * actual: `"\"\\/\b\f\n\r\t"` (length: 15)

* `["\u0024"]`
  * expect: `"$"` (length: 1)
  * actual: `"\u0024"` (length: 6)

* `["\u00A2"]`
  * expect: `"¢"` (length: 2)
  * actual: `"\u00A2"` (length: 6)

* `["\u20AC"]`
  * expect: `"€"` (length: 3)
  * actual: `"\u20AC"` (length: 6)

* `["\uD834\uDD1E"]`
  * expect: `"𝄞"` (length: 4)
  * actual: `"\uD834\uDD1E"` (length: 12)


Summary: 2 of 9 are correct.

## 4. Roundtrip


Summary: 0 of 0 are correct.

