
// ChatDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CChatDlg 对话框
class CChatDlg : public CDialogEx
{
// 构造
public:
	CChatDlg(CWnd* pParent = NULL);	// 标准构造函数
	CImageList m_ImageList;
	CString strText;// 树节点的标签文本字符串
	
// 对话框数据
	enum { IDD = IDD_CHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	CTreeCtrl m_tree;
	
	
	afx_msg void OnDblclkTreeMan(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRclickTreeMenu(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonSend();
	CString m_chatname;
	CString m_say;
	CEdit m_editsend;
	afx_msg void OnEnChangeEditSend();
	CString m_receive;
	afx_msg void OnViewMan();
	
	afx_msg void OnAddMan();
};
