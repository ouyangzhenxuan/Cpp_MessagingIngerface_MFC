// AddMan.cpp : 实现文件
//

#include "stdafx.h"
#include "Chat.h"
#include "AddMan.h"
#include "afxdialogex.h"


// CAddMan 对话框

IMPLEMENT_DYNAMIC(CAddMan, CDialogEx)

CAddMan::CAddMan(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddMan::IDD, pParent)
	, m_newname(_T(""))
	, m_newphonenum(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CAddMan::~CAddMan()
{
}

void CAddMan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NEWNAME, m_newname);
	DDX_Text(pDX, IDC_EDIT_NEWPHONENUM, m_newphonenum);
}


BEGIN_MESSAGE_MAP(CAddMan, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddMan::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddMan 消息处理程序




void CAddMan::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}
