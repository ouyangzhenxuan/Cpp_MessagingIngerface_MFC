#pragma once
#include "afxwin.h"


// CViewDlg �Ի���

class CViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CViewDlg)

public:
	CViewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CViewDlg();
	CFont newFont;
// �Ի�������
	enum { IDD = IDD_VIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static_head;
	virtual BOOL OnInitDialog();
	CStatic m_Bmp;
	CString m_viewname;
	CString m_viewphonenum;
};
