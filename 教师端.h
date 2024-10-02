#pragma once
#include "afxdialogex.h"


// 教师端 对话框

class 教师端 : public CDialogEx
{
	DECLARE_DYNAMIC(教师端)

public:
	教师端(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~教师端();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	BOOL m_Enabled;
	afx_msg void OnBnClickedOk();
};
