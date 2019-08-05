
// ChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"
#include "afxdialogex.h"
#include "ViewDlg.h"
#include "AddMan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
extern char R_get_chatname[100];//右击联系人弹出菜单时保存此联系人的名字
#endif
char chatcontent1[4096];//保存爸爸历史对话消息
char chatcontent2[4096];//保存妈妈历史对话消息
char chatcontent3[4096];//保存小李历史对话消息
char chatcontent4[4096];//保存小黄历史对话消息


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChatDlg 对话框



CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatDlg::IDD, pParent)
	, m_say(_T(""))
	, m_chatname(_T(""))
	, m_receive(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Text(pDX, IDC_EDIT_CHAT_MAN, m_chatname);
	DDX_Text(pDX, IDC_EDIT_SEND, m_say);
	DDX_Control(pDX, IDC_EDIT_SEND, m_editsend);
	DDX_Text(pDX, IDC_EDIT_RECEIVE, m_receive);
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CChatDlg::OnTvnSelchangedTree1)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, &CChatDlg::OnDblclkTreeMan)
	ON_NOTIFY(NM_RCLICK, IDC_TREE1, &CChatDlg::OnRclickTreeMenu)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CChatDlg::OnBnClickedButtonSend)
	ON_EN_CHANGE(IDC_EDIT_SEND, &CChatDlg::OnEnChangeEditSend)
	ON_COMMAND(ID_32773, &CChatDlg::OnViewMan)
	ON_COMMAND(ID_32772, &CChatDlg::OnAddMan)
END_MESSAGE_MAP()


// CChatDlg 消息处理程序

BOOL CChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO:  在此添加额外的初始化代码
	int i;
	HICON hIcon[2];
	// 定义树形控件句柄  
	//树的节点
	HTREEITEM family = m_tree.InsertItem(_T("家人"));//第一级节点
	HTREEITEM family1 = m_tree.InsertItem(_T("爸爸"), 1, 1, family, TVI_LAST);
	HTREEITEM family2 = m_tree.InsertItem(_T("妈妈"), 1, 1, family, TVI_LAST);
	HTREEITEM coworker = m_tree.InsertItem(_T("同事"));//第一级节点
	HTREEITEM coworker1 = m_tree.InsertItem(_T("小李"), 1, 1, coworker,TVI_LAST);
	HTREEITEM coworker2 = m_tree.InsertItem(_T("小黄"), 1, 1, coworker, TVI_LAST);
	//节点图标
	hIcon[0] = theApp.LoadIcon(IDI_ICON5);
	hIcon[1] = theApp.LoadIcon(IDI_ICON4);
	m_ImageList.Create(32, 32, ILC_COLOR32, 3, 3);
	for(i = 0;i<2;i++)
	{
		m_ImageList.Add(hIcon[i]);
	}
	m_tree.SetImageList(&m_ImageList, TVSIL_NORMAL);//将树形目录和图像列表关联
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatDlg::OnPaint()
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
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChatDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	
	*pResult = 0;
}


void CChatDlg::OnDblclkTreeMan(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	CString strText;// 树节点的标签文本字符串
	// 获取当前选中节点的句柄     
	HTREEITEM hItem=m_tree.GetSelectedItem();
	// 获取选中节点的标签文本字符串     
	strText=m_tree.GetItemText(hItem);
	// 将字符串显示到编辑框中     
	SetDlgItemText(IDC_EDIT_CHAT_MAN, strText);
	char *chat_name = (LPSTR)(LPCTSTR)strText;//保存当前聊天对象的名字,转换成char类型
	m_chatname=strText;
	if (m_tree.GetItemText(hItem) == "爸爸"){//当双击“爸爸”的时候，聊天框显示历史信息
		m_receive = chatcontent1;
	}
	if (m_tree.GetItemText(hItem) == "妈妈"){
		m_receive = chatcontent2;
	}
	*pResult = 0;
}


void CChatDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CChatDlg::OnRclickTreeMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	//临时鼠标的屏幕坐标，用来弹出menu
		CMenu menu;
		CString strName;//当前选中的对象的内容
		menu.LoadMenu(IDR_MENU_mytree);
		CPoint pt;
		GetCursorPos(&pt);
		m_tree.ScreenToClient(&pt);//转化为客户坐标
		HTREEITEM hSelTree = m_tree.HitTest(pt);
		if (hSelTree != NULL && m_tree.GetParentItem(hSelTree) != NULL)
		{
			m_tree.SelectItem(hSelTree);
			m_tree.ClientToScreen(&pt);
			CMenu* pPopup = menu.GetSubMenu(0);//装载第一个子菜单，即我们菜单的第一列
			pPopup->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);//弹出菜单
		}
		// 获取当前选中节点的句柄     
		HTREEITEM hName = m_tree.GetSelectedItem();
		// 获取选中节点的标签文本字符串     
		strName = m_tree.GetItemText(hName);
		char *Rchat_name = (LPSTR)(LPCTSTR)strName;
		strcpy(R_get_chatname , Rchat_name);//R_get_chatname这个字符串保存右键时的联系人名字，用于动态查看联系人资料页面
	*pResult = 0;
}


void CChatDlg::OnBnClickedButtonSend()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *chat_content = (LPSTR)(LPCTSTR)m_say;
	if (m_chatname == "爸爸")
	{
		strcat(chatcontent1, chat_content);
		strcat(chatcontent1, "\r\n");
		CString cstr = chatcontent1;
		cstr += _T("\r\n");
		m_receive = cstr;
		m_say.Empty();
	}
	if (m_chatname == "妈妈")
	{
		strcat(chatcontent2, chat_content);
		strcat(chatcontent2, "\r\n");
		CString cstr = chatcontent2;
		cstr += _T("\r\n");
		m_receive = cstr;
		m_say.Empty();
	}
	if (m_chatname == "小李")
	{
		strcat(chatcontent3, chat_content);
		strcat(chatcontent3, "\r\n");
		CString cstr = chatcontent3;
		cstr += _T("\r\n");
		m_receive = cstr;
		m_say.Empty();
	}
	if (m_chatname == "小黄")
	{
		strcat(chatcontent4, chat_content);
		strcat(chatcontent4, "\r\n");
		CString cstr = chatcontent4;
		cstr += _T("\r\n");
		m_receive = cstr;
		m_say.Empty();
	}
	UpdateData(FALSE);
}


void CChatDlg::OnEnChangeEditSend()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}


void CChatDlg::OnViewMan()
{
	// TODO:  在此添加命令处理程序代码
	CViewDlg dlg;
	dlg.DoModal();//弹出查看联系人对话框
}


void CChatDlg::OnAddMan()
{
	// TODO:  在此添加命令处理程序代码
	CAddMan dlg;
	dlg.DoModal();//弹出添加联系人对话框
}
