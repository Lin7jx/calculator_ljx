# calculator_ljx

基本要求：
1.	能够接受包含括号的中缀表达式并正确计算其值。
2.	在程序中实现对输入表达式的简单错误检测，并提供相应的提示信息。
3.	能处理单目运算符+、-
4.	撰写详尽的实验报告，清晰展示设计思路和实现方法。
扩展功能：
1.  实现负号后带括号的计算，形如7--（3+4）
		2.  具备处理括号嵌套计算，即支持括号内包含更多括号的情况。
3.  对于输入为空或括号内为空的情况，程序能够智能地在+，-运算符前自动添加一个零，以确保计算的准确性。

涉及到了一些数据结构的知识，具体包括：
1.中缀表达式转后缀表达式
使用栈结构进行操作符的处理
考虑括号的匹配和嵌套
2.后缀表达式的计算
利用栈进行后缀表达式的计算
处理运算符的优先级
3.错误处理
对用户输入的表达式进行合法性检查
给出适当的错误提示
4.单目运算符处理
对于单目运算符（如取负号）的特殊处理

3.2 使用的C++集成开发环境。
	Visual Studio 2022

4.分析与实现
4.1分析综合实验项目的实现方法（围绕基本要求）
	(1) 获取用户输入的中缀表达式（字符串）： 用户通过点击界面显示的按钮进行输入，每个按钮都实现了写入方法，并具备检查功能。

	(2) 拆解字符串，存入中缀表达式数组：在中缀表达式转换的过程中，首先对输入的算式字符串进行遍历。对于每个字符，根据不同的情况进行处理：
①数字处理： 如果当前字符是数字，会进入循环，将数字字符拼接成一个完整的数字串 s，同时判断是否包含小数点。将得到的数字串直接存入中缀表达式数组中。
伪代码:
			while (当前字符是数字)
    			将当前字符追加到数字串 s 中
    			获取下一个字符
    			如果当前字符是小数点
        			将小数点追加到数字串 s 中
        			获取下一个字符

将数字串 s 存入中缀表达式数组

②-号处理： 如果当前字符是负号，根据其后字符的情况分别处理。如果后一个字符是数字，直接将后面的数字转换为double类型，取负数，并将其转换为字符串形式后存入中缀表达式数组。如果后一个字符是左括号，则主动在中缀表达式中写入(0- ， 然后通过条件判断，补全’)’ 。例如，对于输入3+-(5-8)，则中缀表达式数组中存储的为3+(0-(5-8))。如果当前字符是减号，直接存入中缀表达式数组。
伪代码：
			如果当前字符是负号
    			获取上一个字符 last_symbol 和下一个字符 next_symbol
   			如果 next_symbol 是数字
        			将 next_symbol 以及其后的数字转换为 double，取负数
        			将结果转换为字符串并存入中缀表达式数组
    			如果 next_symbol 是左括号
        			在中缀表达式数组中写入 "(0-"
        			将当前字符存入中缀表达式数组
					标志设为true
        			初始化左右括号计数 tempLeft 和 tempRight

			// 最后的括号匹配判断（放在最外层循环的最后）
如果 tempLeft 等于 tempRight 且标志为 true且tempLeft 不为零
    			补全中缀表达式数组
        		将 ")" 存入中缀表达式数组
    			重置左右括号计数 tempLeft 和 tempRight 为零
    			将标志设为 false

③其他运算符处理： 对于其他运算符（包括括号和常见运算符），直接将其存入中缀表达式数组中。

	(3) 中缀表达式转换为后缀表达式：自主设计CString栈类，设数字栈和运算符栈。实现方法：
		遍历中缀表达式数组：
如果当前字符是数字，直接压入数字栈。
如果当前字符是运算符：
若运算符栈为空或栈顶是左括号，将当前运算符压入运算符栈。
若当前运算符优先级大于栈顶运算符，将当前运算符压入运算符栈。
否则，弹出栈顶运算符，并压入数字栈，直到满足上述条件。
如果当前字符是左括号，直接压入运算符栈。
如果当前字符是右括号，弹出运算符栈中的运算符，并压入数字栈，直到
遇到左括号，将左括号从栈中弹出。

将运算符栈中的剩余运算符依次弹出，并压入数字栈。
		将数字栈中的元素通过栈1倒序保存到栈2。
将栈2中的元素通过正序保存到后缀表达式数组。
返回后缀表达式数组的长度 num。

	(4) 计算后缀表达式：自主设计double栈类，设dstack。
		遍历后缀表达式数组：
如果当前字符是数字，将其转换为double类型并压入数字栈。
如果当前字符是运算符：
弹出数字栈的两个元素，执行相应的运算，并将结果压入数字栈。
对于除法，要注意除数不能为0的情况，若除数为0，弹出错误提示。
对于取余操作，同样要注意不能对0取余的情况，若对0取余，弹出错误提示。
对于指数运算，根据指数的正负分别进行计算。
从数字栈中弹出最终结果。
将结果转换为CString类型并返回。


4.2 采用适当的数据结构与算法（Why、What、How）
	(1) 中缀表达式转后缀表达式
Why：选择使用两个栈的数据结构（数字栈和运算符栈），以便有效地处理运算符的优先级和后缀表达式的计算。
栈结构提供了便利的后进先出（LIFO）特性，适用于解决中缀表达式中运算符的优先级问题。
			What：数字栈：用于存储中间计算结果和最终结果。
运算符栈：用于存储中缀表达式中的运算符，便于处理运算符的优先级。
How：遍历中缀表达式，根据数字和运算符的特性，分别压入数字栈和运算符栈。
根据运算符的优先级，合理地将运算符从运算符栈弹出并压入数字栈，直到遍历完整个中缀表达式。

		(2) 后缀表达式的计算
		Why：使用栈来存储数字，使得计算过程更加直观和有效。
采用常见的四则运算和指数运算，结合栈的先进先出（FIFO）特性，简化了计算器系统的实现。
			What：数字栈（dstack）：用于存储后缀表达式的计算结果。
采用常见的四则运算和指数运算算法，包括加法、减法、乘法、除法和指数运算。
			How：遍历后缀表达式，根据数字和运算符的特性，分别压入和弹出数字栈。
根据当前运算符，从数字栈中弹出相应数量的数字进行运算，并将结果重新压入数字栈，直到遍历完整个后缀表达式。



4.3 各个函数之间调用关系
GUI 相关函数：
OnBnClickedButton：按钮点击事件处理函数，触发表达式计算的逻辑。

中缀表达式处理函数：
toCStringArray：将输入的表达式拆分成中缀表达式的数组，处理数字、负号等情况。
infix_to_suffix：将中缀表达式数组转换为后缀表达式数组，调用了运算符优先级判断函数 getPriority。

后缀表达式计算函数：
calculate：计算后缀表达式的值，使用栈结构存储数字，处理加减乘除等运算。

栈操作相关函数：
Stack::push：将元素压入栈。
Stack::pop：从栈中弹出元素。
Stack::top：获取栈顶元素。
Stack::isEmpty：检查栈是否为空。

其他辅助函数：
getPriority：获取运算符的优先级，用于判断运算符入栈顺序。

六、综合实验总结
创新部分：
1.对负号后接着括号的算式处理如7--（3+4）；我采用的方法是在负号前主动加‘（’和‘0’，再写入负号，使该负号转换成减号，方便后续计算。并设立该情况出现的标志和左右括号的数量，当标志为true时，记录左右括号的数量。在最外层循环的最后，判断左右括号是否相等，若相等则主动添加‘）’，补全之前添加的‘（’，再将标志设为false。上例最终写入的中缀表达式为7-（0-（3+4））。
2.对括号的嵌套输入；设立bool值needright和两个记录左右括号的int变量，当左括号数量大于右括号数量时才可以添加右括号，否则弹出提示信息，从而能够实现括号的嵌套匹配。
3.对小数点的限制如不能出现形如3.3.4的数字；我的方法是设立一个bool值，初始值为false。只有当该值为false时，才能添加小数点。添加了小数点后，设置该值为true。输入其他运算符后，设置该值为false。 

相关课程设计项目最有价值的内容：
实践中运用数据结构： 通过使用栈等数据结构，以及对中缀表达式和后缀表达式的处理提供了很好的实践机会，使我更深入理解数据结构在实际问题中的应用。

需要进一步了解或得到帮助的方面：
性能优化： 在处理大型表达式或复杂表达式时，可能需要考虑性能优化，确保算 法的效率。
更全面的错误处理： 在用户输入错误时，提供更详细的错误信息，以帮助用户更好地理解和解决问题。

编程实现课程设计的感悟：
实践促使理论理解： 编程实现课程设计是将理论知识付诸实践的过程，通过亲自动手编写代码，加深了对数据结构和算法的理解。
问题解决能力： 遇到代码执行卡死的问题，通过逐步排查和调试，培养了解决问题的能力。在项目中遇到的问题是学习过程中不可或缺的一部分。




