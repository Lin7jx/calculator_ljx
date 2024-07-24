
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <atlstr.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent), output(nullptr)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculatorDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalculatorDlg::OnBnClickedButton23)
END_MESSAGE_MAP()


//设置字号大小
CFont cfont1;
CFont cfont2;

// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	//设置 Edit 编辑框文本字体放大
	cfont1.CreatePointFont(250, _T("黑体"), NULL);
	GetDlgItem(IDC_EDIT4)->SetFont(&cfont1);
	//设置 Static Text 静态文本字体放大
	cfont2.CreatePointFont(150, _T("黑体"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&cfont2);

	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	output = (CEdit*)GetDlgItem(IDC_EDIT4);    //通过ID获取控件，否则output为空

	if (output == nullptr) {
		MessageBox(L"获取 output 控件失败");
		return FALSE;
	}
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool hasDot = false;  //判断是否有小数点
bool need_Right = false;//判断是否需要右括号来匹配左括号
int left_Num = 0;//左括号的数量
int right_Num = 0;//右括号的数量
static int MaxSize = 10000;
CString infix_data[10000];//存放前缀表达式
CString suffix_data[10000];//存放后缀表达式
static int infix_Num = 0;//前缀表达式长度
bool right_flag = false;//是否出现负号后带括号的情况
bool hasEqual = false;



void CCalculatorDlg::OnBnClickedButton1()    //    C
{
	// TODO: 在此添加控件通知处理程序代码
	CString currentText;
	output->GetWindowText(currentText);

	// 将当前文本框设为空
	currentText = "";

	// 更新文本框
	output->SetWindowText(currentText);

	//小数点标志设置为无
	hasDot = false;//恢复原始数据
	need_Right = false;//恢复原始数据
	right_Num = 0;//恢复原始数据
	left_Num = 0;//恢复原始数据
	infix_Num = 0;//恢复原始数据
	right_flag = false;//恢复原始数据
	hasEqual = false;//恢复原始数据
	for (int i = 0; i < MaxSize; i++)//恢复原始数据
	{
		infix_data[i] = L"";
		suffix_data[i] = L"";
	}
}


void CCalculatorDlg::OnBnClickedButton2()     //  back
{
	// TODO: 在此添加控件通知处理程序代码
	// 声明一个CString对象来存储当前文本
	CString currentText;

	// 从文本框中获取当前文本
	output->GetWindowText(currentText);

	// 获取字符串长度
	int length = currentText.GetLength();

	// 如果字符串不为空，去掉最后一个字符
	if (length > 0) {
		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);
		if (lastChar == '.')//如果删除的是. 则更改hasDot标志
		{
			//小数点标志设置为无
			hasDot = false;
		}
		else if (lastChar == '(')//如果删除的是( 则左括号数量减一
		{
			left_Num--;
		}
		else if (lastChar == ')')//如果删除的是) 则右括号数量减一
		{
			right_Num--;
		}
		else if (lastChar == '=')
		{
			if (currentText.GetAt(length - 2) != '=')
			{
				hasEqual = false;
			}
		}

		if (left_Num > right_Num)//重新判断括号是否匹配
		{
			need_Right = true;
		}
		currentText = currentText.Left(length - 1);

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已清除完数据");
	}
}


void CCalculatorDlg::OnBnClickedButton3()  //取余
{
	// TODO: 在此添加控件通知处理程序代码
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) || lastChar == ')') {
			//小数点标志设置为无
			hasDot = false;

			// 在当前文本框的内容后面追加 "%"
			currentText += "%";

			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符不是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		MessageBox(L"输入无效！");
	}
}


void CCalculatorDlg::OnBnClickedButton4()     //除以 /
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取当前文本框的内容
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) || lastChar == ')') {
			//小数点标志设置为无
			hasDot = false;

			// 在当前文本框的内容后面追加 "/"
			currentText += "/";

			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符不是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		MessageBox(L"输入无效！");
	}
}


void CCalculatorDlg::OnBnClickedButton5()        //左括号
{
	// TODO: 在此添加控件通知处理程序代码
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (!_istdigit(lastChar)) {
			// 在当前文本框的内容后面追加 "("
			currentText += "(";
			left_Num++;//左括号数量加1
			if (left_Num > right_Num)//重新判断是否还需要右括号
			{
				need_Right = true;
			}
			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		// 在当前文本框的内容后面追加 "("
		currentText += "(";
		left_Num++;//左括号数量加1
		if (left_Num > right_Num)//重新判断是否还需要右括号
		{
			need_Right = true;
		}
		// 更新文本框
		output->SetWindowText(currentText);
	}
}


void CCalculatorDlg::OnBnClickedButton6()     //右括号
{
	// TODO: 在此添加控件通知处理程序代码
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) && need_Right == true || lastChar == ')' && need_Right == true)
		{
			// 在当前文本框的内容后面追加 ")"
			currentText += ")";
			right_Num++;//右括号数量加1
			if (left_Num == right_Num)//重新判断是否还需要右括号
			{
				need_Right = false;
			}
			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符不是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		MessageBox(L"输入无效！");
	}
}


void CCalculatorDlg::OnBnClickedButton7()     //      ^
{
	// TODO: 在此添加控件通知处理程序代码
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) || lastChar == ')') {
			//小数点标志设置为无
			hasDot = false;

			// 在当前文本框的内容后面追加 "^"
			currentText += "^";

			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符不是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		MessageBox(L"输入无效！");
	}
}


void CCalculatorDlg::OnBnClickedButton8()          //   *
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取当前文本框的内容
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) || lastChar == ')') {
			//小数点标志设置为无
			hasDot = false;

			// 在当前文本框的内容后面追加 "*"
			currentText += "*";

			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符不是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		MessageBox(L"输入无效！");
	}
}


void CCalculatorDlg::OnBnClickedButton9()  //  7
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "7"
		currentText += "7";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton10()    //8
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "8"
		currentText += "8";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton11()      //        9
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "9"
		currentText += "9";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton12()   // -
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取当前文本框的内容
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) || lastChar == ')' || lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/' || lastChar == '%' || lastChar == '^')
		{
			//小数点标志设置为无
			hasDot = false;

			// 在当前文本框的内容后面追加 "-"
			currentText += "-";

			// 更新文本框
			output->SetWindowText(currentText);
		}
		else if (lastChar == '(')
		{
			// 在当前文本框的内容后面追加 "0-"
			currentText += "0-";

			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符不是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		// 在当前文本框的内容后面追加 "0-"
		currentText += "0-";

		// 更新文本框
		output->SetWindowText(currentText);
	}
}


void CCalculatorDlg::OnBnClickedButton13()     // 4
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "4"
		currentText += "4";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton14()     //  5
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "5"
		currentText += "5";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton15()   //  6
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "6"
		currentText += "6";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton16()   // +
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取当前文本框的内容
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) || lastChar == ')') {
			//小数点标志设置为无
			hasDot = false;

			// 在当前文本框的内容后面追加 "+"
			currentText += "+";

			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符不是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		// 在当前文本框的内容后面追加 "0+"
		currentText += "0+";

		// 更新文本框
		output->SetWindowText(currentText);
	}
}


void CCalculatorDlg::OnBnClickedButton17()    //  1
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "1"
		currentText += "1";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton18()    //   2
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "2"
		currentText += "2";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton19()        //    3
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "3"
		currentText += "3";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton20()      //   00
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "00"
		currentText += "00";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton21()     // 0
{
	// TODO: 在此添加控件通知处理程序代码
	if (!hasEqual)
	{
		CString currentText;
		output->GetWindowText(currentText);

		// 在当前文本框的内容后面追加 "0"
		currentText += "0";

		// 更新文本框
		output->SetWindowText(currentText);
	}
	else
	{
		MessageBox(L"已有等号！");
	}
}


void CCalculatorDlg::OnBnClickedButton22()     // .
{
	// TODO: 在此添加控件通知处理程序代码
	CString currentText;
	output->GetWindowText(currentText);

	// 判断字符串是否为空
	if (!currentText.IsEmpty()) {
		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) && hasDot == false) {
			// 在当前文本框的内容后面追加 "."
			currentText += ".";
			hasDot = true;
			// 更新文本框
			output->SetWindowText(currentText);
		}
		// 如果最后一位字符不是数字
		else {
			MessageBox(L"输入无效！");
		}
	}
	else {
		MessageBox(L"输入无效！");
	}
}


void CCalculatorDlg::OnBnClickedButton23()      //   =
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取当前文本框的内容
	CString currentText;
	output->GetWindowText(currentText);

	if (left_Num != right_Num)//左右括号不匹配
	{
		MessageBox(L"输入无效！");
	}
	else if (hasEqual)
	{
		MessageBox(L"已有等号！");
	}
	// 判断字符串是否为空
	else if (!currentText.IsEmpty())
	{

		// 获取字符串的长度
		int length = currentText.GetLength();

		// 获取最后一位字符
		TCHAR lastChar = currentText.GetAt(length - 1);

		// 判断最后一位字符是否为数字
		if (_istdigit(lastChar) || lastChar == ')')
		{
			// 在当前文本框的内容后面追加 "="
			currentText += "=";

			hasEqual = true;

			toCStringArray(currentText);

			int num = infix_to_suffix(infix_data, suffix_data, infix_Num);

			CString result = calculate(suffix_data, num);
			// 在当前文本框的内容后面追加计算结果
			currentText += result;
			// 更新文本框
			output->SetWindowText(currentText);

		}
		// 如果最后一位字符不是数字
		else
		{
			MessageBox(L"输入无效！");
		}


	}
	else {
		MessageBox(L"输入无效！");
	}
}

void CCalculatorDlg::toCStringArray(CString currentText)
{

	int length = currentText.GetLength();//输入的算式字符串的长度
	int current = 0;//infix_data的下标
	infix_Num = 0;//后缀表达式的长度

	int tempLeft = 0;//出现负号后是(的情况后的左括号数量
	int tempRight = 0;//出现负号后是(的情况后的右括号数量

	for (current = 0; current < length; infix_Num++)
	{
		CString s ; //数字或符号
		s = "";
		TCHAR c = currentText.GetAt(current);

		if (_istdigit(c))//数字处理
		{
			while (_istdigit(c))//数字直接填入
			{
				s += c;
				c = currentText.GetAt(++current);
				if (c == '.')//判断是否是小数
				{
					s += c;
					c = currentText.GetAt(++current);
				}
			}
			infix_data[infix_Num] = s;
		}

		else if (c == '-')
		{
			TCHAR last_symbol;//减号的上一位
			TCHAR next_symbol;//减号的下一位
			last_symbol = currentText.GetAt(current - 1);
			next_symbol = currentText.GetAt(current + 1);
			//减号,直接填入
			if (_istdigit(last_symbol)||last_symbol==')')
			{
				s += c;
				++current;
				infix_data[infix_Num] = s;
			}
			//负号,且负号后是数字,思路是直接把负号丢掉，将后面的数转换成double，取负数，再变回CString类型
			else if ((last_symbol == '+' || last_symbol == '-' || last_symbol == '*' || last_symbol == '/' || last_symbol == '^' || last_symbol == '%') && next_symbol != '(' && _istdigit(next_symbol))
			{
				c = currentText.GetAt(++current);
				while (_istdigit(c))
				{
					s += c;
					current++;
					c = currentText.GetAt(current);
					if (c == '.')
					{
						s += c;
						current++;
						c = currentText.GetAt(current);
					}
				}
				//	infix_data[infix_Num]=s;
				
				double d = -1 * _wtof(s); // 直接使用 _wtof 进行字符串到浮点数转换
				CString result;
				result.Format(_T("%g"), d);
				infix_data[infix_Num] = result;
				
			}
			//负号，且后面是左括号 思路是主动添加(0-()),如7-(3+4),则中缀表达式为7-(0-(3+4)),从而实现负号的效果
			else if (last_symbol == '+' || last_symbol == '-' || last_symbol == '*' || last_symbol == '/' || last_symbol == '^' || last_symbol == '%' && next_symbol == '(')
			{
				current++;
				right_flag = true;
				infix_data[infix_Num++] = _T('(');
				infix_data[infix_Num++] = _T('0');

				s += c;
				infix_data[infix_Num] = s;//主动写入(0-
				tempLeft = 0;
				tempRight = 0;
			}
		}

		else if (c == '(' || c == ')' || c == '%' || c == '^' || c == '/' || c == '*' || c == '+')//遇到这些运算符直接压入栈
		{
			if (c == '(' && right_flag == true)
			{
				tempLeft++;
			}
			else if (c == ')' && right_flag == true)
			{
				tempRight++;
			}
			s += c;
			++current;
			infix_data[infix_Num] = s;
		}
		else if (infix_Num > MaxSize)
		{
			MessageBox(L"溢出！");
			break;
		}
		else if (c == '=')
		{
			break;
		}
		else
		{
			MessageBox(L"输入无效！");
			break;
		}




		if (tempLeft == tempRight && right_flag == true && tempLeft!=0)//最后再一次循环结束之前判断(0-)内部的左右括号是否匹配
		{
			tempLeft = 0;
			tempRight = 0;
			infix_data[++infix_Num] = ')';
			right_flag = false;
		}


	}
	//中缀表达式输出测试
	/*
	CString test;
	test = "";
	for (int z = 0; z < infix_Num; z++)
	{
		test += infix_data[z];
	}
	
	MessageBox(test);
	*/

}


int CCalculatorDlg::getPriority(CString cstring)//判断优先级
{
	if (cstring == "(")
		return 0;
	else if (cstring == "+" || cstring == "-")
		return 1;
	else if (cstring == "*" || cstring == "/" || cstring == "%")
		return 2;
	else if (cstring == "^")
		return 3;
	else if (cstring == ")")
		return 4;

	return -1; // 错误指示
}

class CStack {
public:
	// 构造函数
	CStack() {}

	// 入栈操作
	void push(const CString& value) {
		stack.Add(value);
	}

	// 出栈操作
	CString pop() {
		if (!isEmpty()) {
			CString topValue = stack[stack.GetSize() - 1];
			stack.RemoveAt(stack.GetSize() - 1);
			return topValue;
		}
		else {
			// 栈为空时返回空字符串
			return _T("");
		}
	}

	// 获取栈顶元素
	CString top() const {
		if (!isEmpty()) {
			return stack[stack.GetSize() - 1];
		}
		else {
			// 栈为空时返回空字符串
			return _T("");
		}
	}

	// 判断栈是否为空
	bool isEmpty() const {
		if (stack.GetSize() == 0)
			return true;
		else
			return false;
	}

	// 获取栈的大小
	int size() const {
		return static_cast<int>(stack.GetSize());
	}

private:
	CArray<CString, CString> stack;
};

CStack stack1;//符号栈
CStack stack2;//数字栈


int CCalculatorDlg::infix_to_suffix(CString* infix_Data, CString* suffix_Data, int length)//中缀表达式转后缀表达式
{
	int i = 0, num = 0;

	for (i = 0; i < infix_Num; i++)
	{
		if (infix_Data[i] != '+' && infix_Data[i] != '-' && infix_Data[i] != '*' && infix_Data[i] != '/' && infix_Data[i] != '%' && infix_Data[i] != '^' && infix_Data[i] != '(' && infix_Data[i] != ')')//数字直接压入数字栈
		{
			stack2.push(infix_Data[i]);
		}
		else if (infix_Data[i] == '+' || infix_Data[i] == '-' || infix_Data[i] == '*' || infix_Data[i] == '/' || infix_Data[i] == '%' || infix_Data[i] == '^')//运算符
		{
			while (true)
			{
				if (stack1.isEmpty() || stack1.top() == '(')
				{
					stack1.push(infix_Data[i]);
					break;
				}
				else if (getPriority(infix_Data[i]) > getPriority(stack1.top()))
				{
					stack1.push(infix_Data[i]);
					break;
				}
				else
				{
					CString temp = stack1.top();
					stack1.pop();
					stack2.push(temp);
				}
			}
		}
		else
		{
			if (infix_Data[i] == '(')
			{
				stack1.push(infix_Data[i]);
			}
			else                 // 右括号
			{
				while (stack1.top() != '(')
				{
					CString temp = stack1.top();
					stack1.pop();
					stack2.push(temp);
				}
				stack1.pop();
			}
		}
	}

	while (!stack1.isEmpty())//最后将运算符压入数字栈
	{
		CString temp = stack1.top();
		stack1.pop();
		stack2.push(temp);
	}

	while (!stack2.isEmpty())//直接从stack2弹出是倒序，所以利用stack1先倒序输出一次
	{
		CString temp = stack2.top();
		stack2.pop();
		stack1.push(temp);
	}

	num = 0;
	while (!stack1.isEmpty())//再通过stack1 正序写入
	{
		CString temp = stack1.top();
		suffix_Data[num++] = temp;
		stack1.pop();
	}

	/*
	CString resultString;
	resultString = "";

	for (int k = 0; k < num; k++)
	{
		resultString += suffix_Data[k];
	}

	MessageBox(resultString);
	*/

	return num;

}

class doubleStack {
public:
	// 构造函数
	doubleStack() {}

	// 入栈操作
	void push(const double& value) {
		stack.Add(value);
	}

	// 出栈操作
	double pop() {
		if (!isEmpty()) {
			double topValue = stack[stack.GetSize() - 1];
			stack.RemoveAt(stack.GetSize() - 1);
			return topValue;
		}
		else {
			// 栈为空时返回-1
			return -1;
		}
	}

	// 获取栈顶元素
	double top() const {
		if (!isEmpty()) {
			return stack[stack.GetSize() - 1];
		}
		else {
			// 栈为空时返回-1
			return -1;
		}
	}

	// 判断栈是否为空
	bool isEmpty() const {
		if (stack.GetSize() == 0)
			return true;
		else
			return false;
	}

	// 获取栈的大小
	int size() const {
		return static_cast<int>(stack.GetSize());
	}

private:
	CArray<double, double> stack;
};

doubleStack dstack;


CString CCalculatorDlg::calculate(CString* suffix_Data, int length)
{
	int i;
	double num1, num2, num3;

	//后缀表达式输出测试
	/*
	CString resultString;
	resultString = "";

	for (int k = 0; k < length; ++k)
	{
		resultString += suffix_Data[k];
	}

	MessageBox(resultString);
	*/


	for (i = 0; i < length; i++)
	{
		if (suffix_Data[i] != '+' && suffix_Data[i] != '-' && suffix_Data[i] != '*' && suffix_Data[i] != '/' && suffix_Data[i] != '%' && suffix_Data[i] != '^' && suffix_Data[i] != '(' && suffix_Data[i] != ')')
		{
			/*  测试代码
			CString s;
			s = "";
			s += suffix_Data[i];
			s += "入栈";
			AfxMessageBox(s, MB_OK | MB_ICONINFORMATION);
			*/
			dstack.push(atof(CStringA(suffix_Data[i])));

		}
		else
		{
			if (suffix_Data[i] == '+')
			{
				num1 = dstack.top();
				dstack.pop();
				num2 = dstack.top();
				dstack.pop();
				num3 = num1 + num2;
				/*   测试代码
				CString temp1, temp2, temp3;
				CString s = "弹出";
				temp1.Format(_T("%f"), num1);
				s += temp1;
				s += " ";
				temp2.Format(_T("%f"), num2);
				s += temp2;
				temp3.Format(_T("%f"), num3);
				s += "  压入" + temp3;
				AfxMessageBox(s, MB_OK | MB_ICONINFORMATION);
				*/
				dstack.push(num1 + num2);
			}
			else if (suffix_Data[i] == '-')
			{
				num1 = dstack.top();
				dstack.pop();
				num2 = dstack.top();
				dstack.pop();
				num3 = num2 - num1;
				/*    测试代码
				CString temp1, temp2, temp3;
				CString s = "弹出";
				temp1.Format(_T("%f"), num1);
				s += temp1;
				s += " ";
				temp2.Format(_T("%f"), num2);
				s += temp2;
				temp3.Format(_T("%f"), num3);
				s += "  压入" + temp3;
				AfxMessageBox(s, MB_OK | MB_ICONINFORMATION);
				*/
				dstack.push(num2 - num1);
			}
			else if (suffix_Data[i] == '*')
			{
				num1 = dstack.top();
				dstack.pop();
				num2 = dstack.top();
				dstack.pop();
				num3 = num1 * num2;
				/*   测试代码
				CString temp1, temp2, temp3;
				CString s = "弹出";
				temp1.Format(_T("%f"), num1);
				s += temp1;
				s += " ";
				temp2.Format(_T("%f"), num2);
				s += temp2;
				temp3.Format(_T("%f"), num3);
				s += "  压入" + temp3;
				AfxMessageBox(s, MB_OK | MB_ICONINFORMATION);
				*/
				dstack.push(num2 * num1);
			}
			else if (suffix_Data[i] == '/')
			{
				num1 = dstack.top();
				if (num1 == 0)
				{
					MessageBox(L"不能除0！");
				}
				else
				{
					dstack.pop();
					num2 = dstack.top();
					dstack.pop();
					num3 = num2 / num1;
					/*     测试代码
					CString temp1, temp2, temp3;
					CString s = "弹出";
					temp1.Format(_T("%f"), num1);
					s += temp1;
					s += " ";
					temp2.Format(_T("%f"), num2);
					s += temp2;
					temp3.Format(_T("%f"), num3);
					s += "  压入" + temp3;
					AfxMessageBox(s, MB_OK | MB_ICONINFORMATION);
					*/
					dstack.push(num2 / num1);
				}
			}
			else if (suffix_Data[i] == '%')
			{
				num1 = dstack.top();
				if (num1 == 0)
				{
					MessageBox(L"不能对0取余！");
				}
				else
				{
					dstack.pop();
					num2 = dstack.top();
					dstack.pop();
					num3 = fmod(num2, num1);
					/*         测试代码
					CString temp1, temp2, temp3;
					CString s = "弹出";
					temp1.Format(_T("%f"), num1);
					s += temp1;
					s += " ";
					temp2.Format(_T("%f"), num2);
					s += temp2;
					temp3.Format(_T("%f"), num3);
					s += "  压入" + temp3;
					AfxMessageBox(s, MB_OK | MB_ICONINFORMATION);
					*/
					dstack.push(fmod(num2, num1));
				}
			}
			else if (suffix_Data[i] == '^')
			{
				num1 = dstack.top();
				dstack.pop();
				num2 = dstack.top();
				dstack.pop();
				num3 = 1;
				if (num1 > 0)
				{
					for (int j = 0; j < num1; j++)
					{
						num3 *= num2;
					}
				}
				else if (num1 == 0)
				{
					num3 = 1;
				}
				else
				{
					for (int j = 0; j > num1; j--)
					{
						num3 *= num2;
					}
					num3 = 1 / num3;
				}

				/*     测试代码
				CString temp1, temp2, temp3;
				CString s = "弹出";
				temp1.Format(_T("%f"), num1);
				s += temp1;
				s += " ";
				temp2.Format(_T("%f"), num2);
				s += temp2;
				temp3.Format(_T("%f"), num3);
				s += "  压入" + temp3;
				AfxMessageBox(s, MB_OK | MB_ICONINFORMATION);
				*/
				dstack.push(num3);
			}

		}
	}

	double result = dstack.top();

	CString c_result;
	CStringA c_resultA(c_result);  // 将宽字符型 CString 转换为窄字符型 CStringA
	c_resultA.Format("%g", result);
	c_result = c_resultA;

	return c_result;

}