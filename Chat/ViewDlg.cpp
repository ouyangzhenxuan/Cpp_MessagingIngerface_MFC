// ViewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Chat.h"
#include "ViewDlg.h"
#include "afxdialogex.h"
#include "ChatDlg.h"

char R_get_chatname[100];//�һ���ϵ�˵����˵�ʱ�������ϵ�˵����֣������Ի���.h�ļ��е���
// CViewDlg �Ի���

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


// CViewDlg ��Ϣ�������


BOOL CViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	newFont.CreatePointFont(100,"����");
	m_static_head.SetFont(&newFont);
	//��ʾ����
	CString strText = R_get_chatname;//��õ�ǰѡ����ϵ�˵�����
	SetDlgItemText(IDC_EDIT_VIEWNAME, strText);
	//��ʾ��ϵ��ͷ��
	HBITMAP hBitmap;
	if (strText == "�ְ�"){
		hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
		m_Bmp.SetBitmap(hBitmap);
	}
	if (strText == "����"){
		hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2));
		m_Bmp.SetBitmap(hBitmap);
	}
	if (strText == "С��"){
		hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3));
		m_Bmp.SetBitmap(hBitmap);
	}
	if (strText == "С��"){
		hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4));
		m_Bmp.SetBitmap(hBitmap);
	}
	//��ʾ��ϵ������
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
