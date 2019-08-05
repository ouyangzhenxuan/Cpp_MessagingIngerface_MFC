// ViewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Chat.h"
#include "ViewDlg.h"
#include "afxdialogex.h"
#include "ChatDlg.h"

char R_get_chatname[100];//右击联系人弹出菜单时保存此联系人的名字，从主对话框.h文件中调用
// CViewDlg 对话框

IMPLEMENT_DYNAMIC(CViewDlg, CDialogEx)
CViewDlg::CViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CViewDlg::IDD, pParent)
	, m_viewname(_T(""))
	, m_viewphonenum(_T(""))
{

}

CViewDlg::~CViewDlg()
{
}

void CViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICHEAD, m_static_head);
	DDX_Control(pDX, IDC_PH, m_Bmp);
	DDX_Text(pDX, IDC_EDIT_VIEWNAME, m_viewname);
	DDX_Text(pDX, IDC_EDIT_PHONENUM, m_viewphonenum);
}


BEGIN_MESSAGE_MAP(CViewDlg, CDialogEx)
END_MESSAGE_MAP()


// CViewDlg 消息处理程序


BOOL CViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	newFont.CreatePointFont(100,"楷体");
	m_static_head.SetFont(&newFont);
	//显示姓名
	CString strText = R_get_chatname;//获得当前选中联系人的名字
	SetDlgItemText(IDC_EDIT_VIEWNAME, strText);
	//显示联系人头像
	HBITMAP hBitmap;
	if (strText == "爸爸"){
		hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
		m_Bmp.SetBitmap(hBitmap);
	}
	if (strText == "妈妈"){
		hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2));
		m_Bmp.SetBitmap(hBitmap);
	}
	if (strText == "小黄"){
		hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3));
		m_Bmp.SetBitmap(hBitmap);
	}
	if (strText == "小李"){
		hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4));
		m_Bmp.SetBitmap(hBitmap);
	}
	//显示联系人姓名
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
