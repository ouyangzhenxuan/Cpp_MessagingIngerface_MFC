#pragma once


// CAddMan 对话框

class CAddMan : public CDialogEx
{
	DECLARE_DYNAMIC(CAddMan)

public:
	CAddMan(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddMan();

// 对话框数据
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
	CString m_newname;
	CString m_newphonenum;
};
