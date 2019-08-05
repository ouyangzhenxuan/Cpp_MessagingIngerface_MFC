#pragma once
#include "afxwin.h"


// CViewDlg 对话框

class CViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CViewDlg)

public:
	CViewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CViewDlg();
	CFont newFont;
// 对话框数据
	enum { IDD = IDD_VIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static_head;
	virtual BOOL OnInitDialog();
	CStatic m_Bmp;
	CString m_viewname;
	CString m_viewphonenum;
};
