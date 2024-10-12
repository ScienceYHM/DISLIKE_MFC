#pragma once
#include "afxdialogex.h"


// Cemeg 对话框

class Cemeg : public CDialog
{
	DECLARE_DYNAMIC(Cemeg)

public:
	Cemeg(CWnd* pParent = nullptr);   // 标准构造函数
	
	virtual ~Cemeg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	int m_mz;
	int m_mm;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	
};
