#pragma once


// CAddMan �Ի���

class CAddMan : public CDialogEx
{
	DECLARE_DYNAMIC(CAddMan)

public:
	CAddMan(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddMan();

// �Ի�������
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
	CString m_newname;
	CString m_newphonenum;
};
