#pragma once
#include "afxdialogex.h"


// 歌单 对话框

class 歌单 : public CDialogEx
{
	DECLARE_DYNAMIC(歌单)

public:
	歌单(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~歌单();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
};
