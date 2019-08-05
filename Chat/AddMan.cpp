// AddMan.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Chat.h"
#include "AddMan.h"
#include "afxdialogex.h"


// CAddMan �Ի���

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


// CAddMan ��Ϣ�������




void CAddMan::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	CDialogEx::OnOK();
}
